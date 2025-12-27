package main

import (
	"fmt"
	"time"
)

func quicksort(arr []int, start, end int) {
	if start >= end {
		return
	}

	p := pivotPartition(arr, start, end)
	quicksort(arr, start, p-1)
	quicksort(arr, p+1, end)
}

func pivotPartition(arr []int, start, end int) int {
	pivot := arr[start]
	i := start + 1
	j := end

	for i <= j {
		for i <= end && arr[i] < pivot {
			i++
		}
		for j >= start+1 && arr[j] > pivot {
			j--
		}
		if i <= j {
			arr[i], arr[j] = arr[j], arr[i]
			i++
			j--
		}
	}

	// Put pivot into final position
	arr[start], arr[j] = arr[j], arr[start]
	return j
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

	// warm-up (use a copy so original stays unsorted)
	{
		arr := make([]int, len(original))
		copy(arr, original)
		quicksort(arr, 0, len(arr)-1)
		sink ^= arr[0]
	}

	start := time.Now()

	for i := 0; i < ITER; i++ {
		arr := make([]int, len(original))
		copy(arr, original)

		quicksort(arr, 0, len(arr)-1)
		sink ^= arr[i%len(arr)]
	}

	elapsed := time.Since(start)
	totalNs := elapsed.Nanoseconds()
	avgNs := totalNs / int64(ITER)

	fmt.Println("Total Time:", totalNs, "ns")
	fmt.Println("Avg Time :", avgNs, "ns/run")
	fmt.Println("sink:", sink)
}
