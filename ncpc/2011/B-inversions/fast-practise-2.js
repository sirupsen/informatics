process.stdin.resume();
process.stdin.setEncoding('utf8');

function SegmentTree(n) {
  this.n = n;
  this.tree = [];

  for(var i = 0; i < n * 4; i++)
    this.tree.push(0);
}

SegmentTree.prototype.add = function(pos, start, end, key, value) {
  if(key >= start && key <= end) {
    this.tree[pos] += value;

    if(end != start) {
      this.add(pos * 2, start, Math.floor((start + end)/2), key, value);
      this.add(pos * 2 + 1, Math.floor((start + end)/2 + 1), end, key, value);
    }
  }
}

SegmentTree.prototype.query = function(pos, start, end, q_start, q_end) {
  if(start >= q_start && end <= q_end) {
    return this.tree[pos];
  } else if(end < q_start || start > q_end) {
    return 0;
  } else {
    return this.query(2 * pos, start, Math.floor((start + end)/2), q_start, q_end) +
      this.query(2 * pos + 1, Math.floor((start + end)/2 + 1), end, q_start, q_end);
  }
}

process.stdin.on('data', function(data) {
  // Read in a line of numbers
  var numbers = data.trim().split(" ").map(function(i) { return parseInt(i) });
  numbers = numbers.reverse();
  var n = numbers.length;

  var frequency = new SegmentTree(n);
  var sum = new SegmentTree(n);

  var res = 0;

  for(var i = 0; i < n; ++i) {
    frequency.add(1,1,n, numbers[i],1);
    var smaller = frequency.query(1,1,n, 1,numbers[i]-1);

    sum.add(1,1,n, numbers[i], smaller);
    var triplets = sum.query(1,1,n, 1,numbers[i]-1);

    res += triplets;
  }

  console.log(res);
});
