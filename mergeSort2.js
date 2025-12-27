let defaultCompare = (a, b) =>
  a > b ? 1 : (a < b ? -1 : 0);

let mergesort = (
  array,
  start = 0,
  end = array.length,
  compare = defaultCompare
) => {
  let length = end - start;
  if (length <= 1) { return array.slice(start, end); }
  
  // Divide
  let pivot = Math.floor(length / 2);
  
  // Conquer
  let left = mergesort(array, start, start + pivot, compare);
  let right = mergesort(array, start + pivot, end, compare);
  
  // Combine
  let sorted = [];
  let i = 0, j = 0;
  for (let k = 0; k < length; k++) {
      if (i < left.length && compare(left[i], right[j]) <= 0) {
          sorted.push(left[i]);
          i++;
      } else {
          sorted.push(right[j]);
          j++;
      }
  }
  
  return sorted;
};

let mergesortArraySplit = (
  array,
  compare = defaultCompare
) => {
  if (array.length <= 1) { return array; }
  
  // Divide
  let pivot = Math.floor(array.length / 2);
  
  // Conquer
  let left = mergesortArraySplit(array.slice(0, pivot), compare);
  let right = mergesortArraySplit(array.slice(pivot, array.length), compare);
  
  // Combine
  let sorted = [];
  let i = 0, j = 0;
  for (let k = 0; k < array.length; k++) {
      if (i < left.length && compare(left[i], right[j]) <= 0) {
          sorted.push(left[i]);
          i++;
      } else {
          sorted.push(right[j]);
          j++;
      }
  }
  
  return sorted;
};


const arr = [
    73,12,88,45,6,91,34,17,59,2,
    84,26,67,9,53,41,98,21,75,14,
    62,8,90,33,57,19,86,4,48,71,
    25,64,11,97,38,5,82,29,69,16,
    55,93,7,44,80,23,61,10,76,35,
    89,1,52,68,18,95,27,60,13,83,
    40,99,20,72,31,56,94,15,65,46,
    3,87,24,58,70,36,92,22,79,50
];

const ITER = 100000;
let sink = 0;

// 🔥 benchmark
const start = performance.now();

for (let i = 0; i < ITER; i++) {
    const sorted = mergesortArraySplit(arr);
    sink ^= sorted[i % sorted.length];
}

const end = performance.now();

// results
const totalNs = (end - start) * 1e6;

console.log(`Total Time: ${totalNs.toFixed(0)} ns`);
console.log(`Avg Time : ${(totalNs / ITER).toFixed(0)} ns/run`);
console.log("sink:", sink);
// export default mergesortArraySplit;