var extend, root,
  hasProp = {}.hasOwnProperty,
  slice = [].slice;

root = typeof exports !== "undefined" && exports !== null ? exports : window;

extend = root.extend = function(hash1, hash2) {
  var key;
  for (key in hash2) {
    if (!hasProp.call(hash2, key)) continue;
    hash1[key] = hash2[key];
  }
  return hash1;
};

extend(root, {
  config: {
    host: "localhost",
    port: "7442",
    timeout: 5000
  },
  makeIdempotent: function(func) {
    return function() {
      var args, base, previousFunc, ref;
      args = 1 <= arguments.length ? slice.call(arguments, 0) : [];
      return typeof (base = (ref = [func, null], previousFunc = ref[0], func = ref[1], ref))[0] === "function" ? base[0].apply(base, args) : void 0;
    };
  }
});
