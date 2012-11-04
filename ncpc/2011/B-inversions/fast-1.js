fs = require('fs');

function SegmentTree(n) {
  this.tree = [];

  for(var i =0; i < n * 4; i++)
    this.tree.push(0);
}

SegmentTree.prototype.add = function(pos, start, end, key, value) {
  if(key >= start && key <= end){
    this.tree[pos] += value;

    if(start != end) {
      this.add(pos * 2, start, Math.floor((start+end)/2), key, value);
      this.add(pos * 2 + 1, Math.floor((start+end)/2) + 1, end, key, value);
    }
  }
}

SegmentTree.prototype.query = function(pos, start, end, query_start, query_end) {
  if(start >= query_start && end <= query_end) {
    return this.tree[pos];
  } else if (start > query_end || end < query_start) {
    return 0;
  } else {
    return this.query(pos * 2, start, Math.floor((start + end)/2), query_start, query_end) + 
      this.query(pos * 2 + 1, Math.floor((start + end)/2) + 1, end, query_start, query_end);
  }
}

fs.readFile("input.gen", "UTF-8", function(err, data) {
  var numbers = data.trim().split(" ").map(function(i) { return parseInt(i) })
  numbers.shift();

  var n = numbers.length;
  numbers = numbers.reverse();

  var freq = new SegmentTree(n);
  var sum = new SegmentTree(n);

  var res = 0;

  for(var i = 0; i < n; i++) {
    var smaller = freq.query(1,1,n, 1,numbers[i]-1);
    freq.add(1,1,n, numbers[i], 1);

    var triplets = sum.query(1,1,n, 1,numbers[i]-1);
    sum.add(1,1,n, numbers[i], smaller);

    res += triplets;
  }

  console.log(res);
});

