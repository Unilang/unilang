var utils,
  slice = [].slice;

utils = require("./utils");

utils.extend(global, utils);

module.exports = function(sock) {
  if (sock == null) {
    sock = config.sock;
  }
  return {
    chromix: function() {
      var arg, callbacks, client, extra_arguments, i, len, path, request;
      path = arguments[0], request = arguments[1], extra_arguments = 3 <= arguments.length ? slice.call(arguments, 2) : [];
      extend(request, {
        path: path
      });
      if (request.args == null) {
        request.args = [];
      }
      callbacks = [];
      for (i = 0, len = extra_arguments.length; i < len; i++) {
        arg = extra_arguments[i];
        (typeof arg === "function" ? callbacks : request.args).push(arg);
      }
      client = require("net").connect(sock, function() {
        return client.write(JSON.stringify(request));
      });
      return client.on("data", function(data) {
        var callback, j, len1, response;
        response = JSON.parse(data.toString("utf8"));
        if (response.error) {
          console.error("error: " + response.error);
          process.exit(1);
        }
        for (j = 0, len1 = callbacks.length; j < len1; j++) {
          callback = callbacks[j];
          callback.apply(null, response.response);
        }
        return client.destroy();
      });
    }
  };
};
