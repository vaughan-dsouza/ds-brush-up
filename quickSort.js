console.log("Quick Sort Algorithm in JavaScript");

const quicksort = (arr, start = 0, end = arr.length - 1) => {
  if (start >= end) return;

  const p = partition(arr, start, end);
  quicksort(arr, start, p - 1);
  quicksort(arr, p + 1, end);
};

const partition = (arr, start, end) => {
  const pivot = arr[start];
  let i = start + 1;
  let j = end;

  while (i <= j) {
    while (i <= end && arr[i] < pivot) i++;
    while (j >= start + 1 && arr[j] > pivot) j--;

    if (i <= j) {
      [arr[i], arr[j]] = [arr[j], arr[i]];
      i++;
      j--;
    }
  }

  [arr[start], arr[j]] = [arr[j], arr[start]];
  return j;
};

const original = [
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

// warm-up (use a copy so original stays unchanged)
{
  const arr = original.slice();
  quicksort(arr);
  sink ^= arr[0];
}

// benchmark
const start = performance.now();

for (let i = 0; i < ITER; i++) {
  const arr = original.slice();   // fresh input each run
  quicksort(arr);                 // in-place, no return
  sink ^= arr[i % arr.length];
}

const end = performance.now();
const totalNs = (end - start) * 1e6;

console.log(`Total Time: ${totalNs.toFixed(0)} ns`);
console.log(`Avg Time : ${(totalNs / ITER).toFixed(0)} ns/run`);
console.log("sink:", sink);