#!/usr/bin/env node
;
var arg, args, chromix, commandArgs, commandName, filterTabs, focusWindow, getMatchingTabs, getQueryFlags, i, j, len, len1, optimist, url, utils;

utils = require("./utils");

utils.extend(global, utils);

optimist = require("optimist");

args = optimist.usage("Usage: $0 [--sock=PATH]").alias("h", "help").default("sock", config.sock).argv;

if (args.help) {
  optimist.showHelp();
  process.exit(0);
}

chromix = require("./chromix-too")(args.sock).chromix;

[commandName, commandArgs] = 2 < process.argv.length ? [process.argv[2], process.argv.slice(3)] : ["ping", []];

// Extract the query flags (for chrome.tabs.query) from the arguments.  Return the new arguments and the
// query-flags object.
getQueryFlags = function(commandArgs) {
  var arg, flag, i, len, queryFlags, ref, validQueryFlags;
  validQueryFlags = {};
  ref = "active pinned audible muted highlighted discarded autoDiscardable currentWindow lastFocusedWindow".split(" ");
  // These are the valid boolean flags listed here: https://developer.chrome.com/extensions/tabs#method-query.
  for (i = 0, len = ref.length; i < len; i++) {
    flag = ref[i];
    validQueryFlags[flag] = true;
  }
  queryFlags = {};
  commandArgs = (function() {
    var j, len1, ref1, ref2, results;
    results = [];
    for (j = 0, len1 = commandArgs.length; j < len1; j++) {
      arg = commandArgs[j];
      if (arg in validQueryFlags) {
        queryFlags[arg] = true;
        continue;
      // Use a leading "-" or "!" to negate the test; e.g. "-audible" or "!active".
      } else if (((ref1 = arg[0]) === "-" || ref1 === "!") && arg.slice(1) in validQueryFlags) {
        queryFlags[arg.slice(1)] = false;
        continue;
      // For symmetry, we also allow "+"; e.g. "+audible".
      } else if (((ref2 = arg[0]) === "+") && arg.slice(1) in validQueryFlags) {
        queryFlags[arg.slice(1)] = true;
        continue;
      } else {
        results.push(arg);
      }
    }
    return results;
  })();
  return [commandArgs, queryFlags];
};

// Filter tabs by the remaining command-line arguements.  We require a match in either the URL or the title.
// If the argument is a bare number, then we require it to match the tab Id.
filterTabs = (function() {
  var integerRegex;
  integerRegex = /^\d+$/;
  return function(commandArgs, tabs) {
    var i, len, results, tab;
    results = [];
    for (i = 0, len = tabs.length; i < len; i++) {
      tab = tabs[i];
      if (!(function() {
        var arg, j, len1;
        for (j = 0, len1 = commandArgs.length; j < len1; j++) {
          arg = commandArgs[j];
          if (integerRegex.test(arg) && tab.id === parseInt(arg)) {
            continue;
          } else if (integerRegex.test(arg)) {
            return false;
          } else if (tab.url.indexOf(arg) === -1 && tab.title.indexOf(arg) === -1) {
            return false;
          }
        }
        return true;
      })()) {
        continue;
      }
      results.push(tab);
    }
    return results;
  };
})();

// Return an array of tabs matching the flags and other arguments on the command line.
getMatchingTabs = function(commandArgs, callback) {
  var queryFlags;
  [commandArgs, queryFlags] = getQueryFlags(commandArgs);
  return chromix("chrome.tabs.query", {}, queryFlags, function(tabs) {
    tabs = filterTabs(commandArgs, tabs);
    if (tabs.length === 0) {
      process.exit(1);
    }
    return callback(tabs);
  });
};

focusWindow = function(windowId) {
  return chromix("chrome.windows.update", {}, windowId, {
    focused: true
  }, function() {});
};

switch (commandName) {
  case "ls":
  case "list":
  case "tabs":
    getMatchingTabs(commandArgs, function(tabs) {
      var i, len, results, tab;
      results = [];
      for (i = 0, len = tabs.length; i < len; i++) {
        tab = tabs[i];
        results.push(console.log(`${tab.id} ${tab.url} ${tab.title}`));
      }
      return results;
    });
    break;
  case "tid": // Like "ls", but outputs only the tab Id of the matching tabs.
    getMatchingTabs(commandArgs, function(tabs) {
      var i, len, results, tab;
      results = [];
      for (i = 0, len = tabs.length; i < len; i++) {
        tab = tabs[i];
        results.push(console.log(`${tab.id}`));
      }
      return results;
    });
    break;
  case "focus":
  case "activate":
    getMatchingTabs(commandArgs, function(tabs) {
      var i, len, results, tab;
      results = [];
      for (i = 0, len = tabs.length; i < len; i++) {
        tab = tabs[i];
        chromix("chrome.tabs.update", {}, tab.id, {
          selected: true
        });
        results.push(focusWindow(tab.windowId));
      }
      return results;
    });
    break;
  case "select":
    getMatchingTabs(commandArgs, function(tabs) {
      var i, len, results, tab;
      results = [];
      for (i = 0, len = tabs.length; i < len; i++) {
        tab = tabs[i];
        results.push(chromix("chrome.tabs.update", {}, tab.id, {
          selected: true
        }));
      }
      return results;
    });
    break;
  case "reload":
    getMatchingTabs(commandArgs, function(tabs) {
      var i, len, results, tab;
      results = [];
      for (i = 0, len = tabs.length; i < len; i++) {
        tab = tabs[i];
        results.push(chromix("chrome.tabs.reload", {}, tab.id, {}));
      }
      return results;
    });
    break;
  case "url":
    [url, ...commandArgs] = commandArgs;
    getMatchingTabs(commandArgs, function(tabs) {
      var i, len, results, tab;
      results = [];
      for (i = 0, len = tabs.length; i < len; i++) {
        tab = tabs[i];
        results.push(chromix("chrome.tabs.update", {}, tab.id, {url}));
      }
      return results;
    });
    break;
  case "rm":
  case "remove":
  case "close":
    getMatchingTabs(commandArgs, function(tabs) {
      var i, len, results, tab;
      results = [];
      for (i = 0, len = tabs.length; i < len; i++) {
        tab = tabs[i];
        results.push(chromix("chrome.tabs.remove", {}, tab.id));
      }
      return results;
    });
    break;
  case "open":
  case "create":
    for (i = 0, len = commandArgs.length; i < len; i++) {
      arg = commandArgs[i];
      (function(arg) {
        return chromix("chrome.tabs.create", {}, {
          url: arg
        }, function(tab) {
          focusWindow(tab.windowId);
          return console.log(`${tab.id} ${tab.url}`);
        });
      })(arg);
    }
    break;
  case "ping":
    chromix("ping", {}, function(response) {
      console.log(response);
      if (response === "ok") {
        return process.exit(0);
      } else {
        return process.exit(1);
      }
    });
    break;
  case "test":
    chromix("test", {}, function(response) {
      console.log(response);
      if (response === "yo") {
        return process.exit(0);
      } else {
        return process.exit(1);
      }
    });
    break;
  case "file":
    for (j = 0, len1 = commandArgs.length; j < len1; j++) {
      arg = commandArgs[j];
      url = arg.indexOf("file://") === 0 ? arg : `file://${require("path").resolve(arg)}`;
      (function(url) {
        return getMatchingTabs([], function(tabs) {
          var k, len2, results, t, tab;
          tabs = (function() {
            var k, len2, results;
            results = [];
            for (k = 0, len2 = tabs.length; k < len2; k++) {
              t = tabs[k];
              if (t.url.indexOf(url) === 0) {
                results.push(t);
              }
            }
            return results;
          })();
          if (tabs.length === 0) {
            return chromix("chrome.tabs.create", {}, {
              url: url
            }, function(tab) {
              focusWindow(tab.windowId);
              return console.log(`${tab.id} ${tab.url}`);
            });
          } else {
            results = [];
            for (k = 0, len2 = tabs.length; k < len2; k++) {
              tab = tabs[k];
              results.push((function(tab) {
                return chromix("chrome.tabs.update", {}, tab.id, {
                  selected: true
                }, function() {
                  return chromix("chrome.tabs.reload", {}, tab.id, {}, function() {
                    return focusWindow(tab.windowId);
                  });
                });
              })(tab));
            }
            return results;
          }
        });
      })(url);
    }
    break;
  case "raw":
  case "josn":
    args = (function() {
      var k, len2, ref, results;
      ref = commandArgs.slice(1);
      results = [];
      for (k = 0, len2 = ref.length; k < len2; k++) {
        arg = ref[k];
        try {
          results.push(JSON.parse(arg));
        } catch (error) {
          results.push(arg);
        }
      }
      return results;
    })();
    chromix(commandArgs[0], {}, ...args, function(response) {
      return console.log(JSON.stringify(response));
    });
    break;
  default:
    console.error(`error: unknown command: ${commandName}`);
    process.exit(2);
}
