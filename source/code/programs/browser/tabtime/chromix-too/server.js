#!/usr/bin/env node
;
var WSS, args, clientId, handleWebsocketError, optimist, responseHandlers, server, uniqueId, utils, webSock, wss;

utils = require("./utils.js");

utils.extend(global, utils);

optimist = require("optimist");

args = optimist.usage("Usage: $0 [--port=PORT] [--host=ADDRESS] [--sock=PATH] [--mode=MODE]").alias("h", "help").default("port", config.port).default("host", config.host).default("sock", config.sock).default("mode", config.mode).argv;

if (args.help) {
  optimist.showHelp();
  process.exit(0);
}

responseHandlers = {};

webSock = null;

WSS = require("ws").Server;

wss = new WSS({
  port: args.port,
  host: args.host
});

wss.on("connection", function(ws) {
  console.log(`${new Date().toString()}: websocket client connected`);
  webSock = ws;
  return ws.on("message", function(msg) {
    var name;
    return typeof responseHandlers[name = JSON.parse(msg).clientId] === "function" ? responseHandlers[name](msg) : void 0;
  });
});

uniqueId = Math.floor(2000000000 * Math.random()).toString();

clientId = 0;

handleWebsocketError = function(request) {
  var name;
  if (typeof responseHandlers[name = request.clientId] === "function") {
    responseHandlers[name](JSON.stringify(extend(request, {
      error: "websocket is not connected"
    })));
  }
  responseHandlers = {};
  return webSock = null;
};

server = require("net").createServer(function(sock) {
  var myClientId;
  clientId += 1;
  myClientId = `${uniqueId}-${clientId}`;
  responseHandlers[myClientId] = sock.write.bind(sock);
  sock.on("data", function(data) {
    var request;
    try {
      request = JSON.parse(data);
    } catch (error) {
      console.error(`failed to parse JSON: ${data}`);
    }
    try {
      extend(request, {
        clientId: myClientId
      });
      return webSock.send(JSON.stringify(request), function(err) {
        if (err) {
          return handleWebsocketError(request);
        }
      });
    } catch (error) {
      return handleWebsocketError(request);
    }
  });
  return sock.on("close", function() {
    return delete responseHandlers[myClientId];
  });
});

require("fs").unlink(args.sock, function() {
  return server.listen(args.sock, function() {
    return require("fs").chmod(args.sock, args.mode, function() {
      return console.log(`listening on: ${args.sock}`);
    });
  });
});
