fs = require('fs');
fs.readFile("input.gen", "UTF-8", function(err, data) {
  var numbers = data.trim().split(" ").map(function(i) { return parseInt(i) })
  numbers.shift();
});

