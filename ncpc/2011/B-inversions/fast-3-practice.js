process.stdin.resume();
process.stdin.setEncoding('utf8');

function SegmentTree(n) {
  this.tree = [];

  for(var i = 0; i < n * 4; i++)
    this.tree.push(0);
}

SegmentTree.prototype.add = function(pos, start, end, key, value) {
  if(key >= start && key <= end) {
    this.tree[pos] += value;

    if(start != end) {
      this.add(2 * pos, start, Math.floor((start+end)/2), key, value);
      this.add(2 * pos + 1, Math.floor((start+end)/2) + 1, end, key, value);
    }
  }
}

SegmentTree.prototype.query = function(pos, start, end, query_start, query_end) {
  if(start >= query_start && end <= query_end) {
    return this.tree[pos];
  } else if(end < query_start || start > query_end) {
    return 0;
  } else {
    return this.query(2 * pos, start, Math.floor((start+end)/2), query_start, query_end) + 
      this.query(2 * pos + 1, Math.floor((start+end)/2) + 1, end, query_start, query_end);
  }
}

process.stdin.on('data', function(data) {
  // Read in a line of numbers
  var numbers = data.trim().split(" ").map(function(i) { return parseInt(i) });
  numbers.shift();
  numbers = numbers.reverse();
  // console.log(numbers);
  var n = 100;

  var frequency = new SegmentTree(n);
  var sum = new SegmentTree(n);

  var res = 0;

  // reverse
  for(var i = 0; i < numbers.length; i++) {
    var smaller = frequency.query(1,1,n, 1, numbers[i] - 1);
    frequency.add(1,1,n, numbers[i], 1);

    // console.log("Smaller than " + numbers[i] + ": " + smaller);

    var triplets = sum.query(1,1,n, 1, numbers[i] - 1);
    sum.add(1,1,n, numbers[i], smaller);

    // console.log("Triplets from " + numbers[i] + ": " + triplets);

    res += triplets;
  }

  console.log(res);
});
