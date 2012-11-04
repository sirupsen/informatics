var numbers = [3,3,2,1];

var triplets = 0;

for(var i = 0; i < numbers.length; i++)
  for(var j = i + 1; j < numbers.length; j++)
    for(var k = j + 1; k < numbers.length; k++)
      if(numbers[i] > numbers[j] && numbers[j] > numbers[k])
        triplets++;

console.log(triplets);
