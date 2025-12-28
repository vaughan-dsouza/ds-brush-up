const heapify = (arr, n, i) => {
    let lar = i;
    let left = 2*i + 1;
    let right = 2*i + 2;

    if(left < n && arr[left] > arr[lar]) lar = left;    
    if(right < n && arr[right] > arr[lar]) lar = right;    
    if( i != lar){
        [arr[i], arr[lar]] = [arr[lar], arr[i]];
        heapify(arr, n, lar)
    }
}

const heapsort = (arr) => {
    //construct initial heap
    let length = arr.length;
    for(let i = Math.floor(length/2)-1 ; i >=0; i--) heapify(arr, length, i);
    
    //remove max and then heapify
    for(let i=length-1; i>0; i--){
        // Move current max to end
        [arr[0], arr[i]] = [arr[i], arr[0]];

        // Restore heap property on reduced heap
        heapify(arr, i, 0);
    }
}

// let arr = [3,5,4,2,1,0,4,5,8,2,9,7,6,0];
// console.log(arr);
// heapsort(arr);
// console.log(arr);
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

{
  const arr = original.slice();
  heapsort(arr);
  sink ^= arr[0];
}

const start = performance.now();
for (let i = 0; i < ITER; i++) {
  const arr = original.slice();   
  heapsort(arr);                 
  sink ^= arr[i % arr.length];
}
const end = performance.now();
const totalNs = (end - start) * 1e6;

console.log(`Total Time: ${totalNs.toFixed(0)} ns`);
console.log(`Avg Time : ${(totalNs / ITER).toFixed(0)} ns/run`);
console.log("sink:", sink);