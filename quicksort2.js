const quicksort = (arr, start = 0, end = arr.length - 1) => {
  if (start >= end) return arr;

  const p = partition(arr, start, end);
  quicksort(arr, start, p - 1);
  quicksort(arr, p + 1, end);
  return arr;
};

const partition = (arr, start, end) => {
  const pivot = arr[start];
  let i = start + 1;
  let j = end;

  while (i <= j) {
    while (i <= end && arr[i] < pivot) i++;
    while (j >= start && arr[j] > pivot) j--;

    if (i <= j) {
      [arr[i], arr[j]] = [arr[j], arr[i]];
      i++;
      j--;
    }
  }

  // put pivot in its final place
  [arr[start], arr[j]] = [arr[j], arr[start]];
  return j;
};

// demo
let arr = [3,4,1,2,6,7,45,6,2,4,664,24,64,345,32,457,9,3245,14,7534,3,345,345,6772,0];
console.log("before", arr);
console.log("after ", quicksort(arr));
