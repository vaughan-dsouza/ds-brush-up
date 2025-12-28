package main

import (
	"fmt"
	"time"
)

// HeapSort sorts arr in-place using max-heap.
func heapSort(arr []int) {
	n := len(arr)
	if n <= 1 {
		return
	}

	// Build max-heap
	for i := n/2 - 1; i >= 0; i-- {
		siftDown(arr, i, n)
	}

	// Extract elements from heap one by one
	for end := n - 1; end > 0; end-- {
		arr[0], arr[end] = arr[end], arr[0] // move max to the end
		siftDown(arr, 0, end)               // restore heap in arr[0:end]
	}
}

// siftDown restores the max-heap property for the node at index i,
// assuming subtrees are already heaps. heapSize is exclusive.
func siftDown(arr []int, i, heapSize int) {
	for {
		left := 2*i + 1
		if left >= heapSize {
			return
		}
		largest := left
		right := left + 1
		if right < heapSize && arr[right] > arr[left] {
			largest = right
		}
		if arr[i] >= arr[largest] {
			return
		}
		arr[i], arr[largest] = arr[largest], arr[i]
		i = largest
	}
}

func main() {
	original := []int{
		73, 12, 88, 45, 6, 91, 34, 17, 59, 2,
		84, 26, 67, 9, 53, 41, 98, 21, 75, 14,
		62, 8, 90, 33, 57, 19, 86, 4, 48, 71,
		25, 64, 11, 97, 38, 5, 82, 29, 69, 16,
		55, 93, 7, 44, 80, 23, 61, 10, 76, 35,
		89, 1, 52, 68, 18, 95, 27, 60, 13, 83,
		40, 99, 20, 72, 31, 56, 94, 15, 65, 46,
		3, 87, 24, 58, 70, 36, 92, 22, 79, 50,
	}

	const ITER = 100000
	sink := 0

	// warm-up (use a copy so original stays unchanged)
	{
		arr := make([]int, len(original))
		copy(arr, original)
		heapSort(arr)
		sink ^= arr[0]
	}

	start := time.Now()

	for i := 0; i < ITER; i++ {
		arr := make([]int, len(original))
		copy(arr, original)

		heapSort(arr)
		sink ^= arr[i%len(arr)]
	}

	elapsed := time.Since(start)
	totalNs := elapsed.Nanoseconds()
	avgNs := totalNs / int64(ITER)

	fmt.Println("Total Time:", totalNs, "ns")
	fmt.Println("Avg Time :", avgNs, "ns/run")
	fmt.Println("sink:", sink)
}
