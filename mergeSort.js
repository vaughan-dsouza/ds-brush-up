console.log("Merge Sort Algorithm in JavaScript (Deno)");

function mergeSort(arr, start, end) {
    const length = end - start;
    if (length <= 1) return arr;

    const mid = Math.floor(length / 2);
    const left = mergeSort(arr, start, start + mid);
    const right = mergeSort(arr, start + mid, end);
    let i = 0, j = 0;
    const result = [];

    while (i < left.length || j < right.length) {
        if (i < left.length && j < right.length) {
            if (left[i] > right[j]) {
                result.push(right[j++]);
            } else {
                result.push(left[i++]);
            }
        } else if (i < left.length) {
            result.push(left[i++]);
        } else {
            result.push(right[j++]);
        }
    }
    return result;
}

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

const start = performance.now();
for (let i = 0; i < ITER; i++) {
    const sorted = mergeSort(arr, 0, arr.length);
    sink ^= sorted[i % sorted.length];
}
const end = performance.now();
const totalNs = (end - start) * 1e6;

console.log(`Total Time: ${totalNs.toFixed(0)} ns`);
console.log(`Avg Time : ${(totalNs / ITER).toFixed(0)} ns/run`);
console.log("sink:", sink);
