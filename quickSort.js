console.log("Quick Sort Algorithm in JavaScript");
const quicksort = (arr, start, end) =>{
    //divide
    if(start < end){
        const pivot_inx = partition(arr, start, end);
        quicksort(arr, start, pivot_inx - 1);
        quicksort(arr, pivot_inx + 1, end);
    }
    
    //conquer in partition step
    //in-place so explicit combine

    return arr;
}

const partition = (arr, start, end) => {
    const pivot = arr[start];
    let i = start + 1;
    let j = end;
    while(i<=j){
        while(arr[i] < pivot && i <= end) i++;
        while(arr[j] > pivot && j >= start) j--;
        if(i < j){
            [arr[i], arr[j]] = [arr[j], arr[i]];
            i++;
            j--;
        }
        
    }
    [arr[start], arr[j]] = [arr[j], arr[start]];
    console.log(arr);
    return j;
}
// let arr = [
//     73,12,88,45,6,91,34,17,59,2,
//     84,26,67,9,53,41,98,21,75,14,
//     62,8,90,33,57,19,86,4,48,71,
//     25,64,11,97,38,5,82,29,69,16,
//     55,93,7,44,80,23,61,10,76,35,
//     89,1,52,68,18,95,27,60,13,83,
//     40,99,20,72,31,56,94,15,65,46,
//     3,87,24,58,70,36,92,22,79,50
// ];
let arr = [3,4,1,2,6,7,45,6,2,4,664,24,64,345,32,457,9,3245,14,7534,3,345,345,6772,0];
// let arr = [3,4,1,2,6,0];
console.log('before sort', arr)
const sorted = quicksort(arr, 0, arr.length - 1);
console.log('after sort', sorted);

// let arr = [
//     73,12,88,45,6,91,34,17,59,2,
//     84,26,67,9,53,41,98,21,75,14,
//     62,8,90,33,57,19,86,4,48,71,
//     25,64,11,97,38,5,82,29,69,16,
//     55,93,7,44,80,23,61,10,76,35,
//     89,1,52,68,18,95,27,60,13,83,
//     40,99,20,72,31,56,94,15,65,46,
//     3,87,24,58,70,36,92,22,79,50
// ];

// const ITER = 100000;
// let sink = 0;

// const start = performance.now();
// for (let i = 0; i < ITER; i++) {
//     const sorted = quicksort(arr, 0, arr.length);
//     sink ^= sorted[i % sorted.length];
// }
// const end = performance.now();
// const totalNs = (end - start) * 1e6;

// console.log(`Total Time: ${totalNs.toFixed(0)} ns`);
// console.log(`Avg Time : ${(totalNs / ITER).toFixed(0)} ns/run`);
// console.log("sink:", sink);
