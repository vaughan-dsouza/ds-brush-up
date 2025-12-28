package main

import (
	"fmt"
	"time"
)

// RadixSort sorts non-negative integers using LSD radix sort (base 10)
func radixSort(arr []int) {
	n := len(arr)
	if n <= 1 {
		return
	}

	// Find max to know number of digits
	max := arr[0]
	for _, v := range arr {
		if v > max {
			max = v
		}
	}

	output := make([]int, n)

	// exp = 1, 10, 100, ...
	for exp := 1; max/exp > 0; exp *= 10 {
		count := [10]int{}

		// Counting occurrences
		for i := 0; i < n; i++ {
			digit := (arr[i] / exp) % 10
			count[digit]++
		}

		// Prefix sums → positions
		for i := 1; i < 10; i++ {
			count[i] += count[i-1]
		}

		// Build output (stable, iterate backwards)
		for i := n - 1; i >= 0; i-- {
			digit := (arr[i] / exp) % 10
			count[digit]--
			output[count[digit]] = arr[i]
		}

		// Copy back
		copy(arr, output)
	}
}

func main5() {
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

	// warm-up
	{
		arr := make([]int, len(original))
		copy(arr, original)
		radixSort(arr)
		sink ^= arr[0]
	}

	start := time.Now()

	for i := 0; i < ITER; i++ {
		arr := make([]int, len(original))
		copy(arr, original)
		radixSort(arr)
		sink ^= arr[i%len(arr)]
	}

	elapsed := time.Since(start)
	totalNs := elapsed.Nanoseconds()
	avgNs := totalNs / int64(ITER)

	fmt.Println("Total Time:", totalNs, "ns")
	fmt.Println("Avg Time :", avgNs, "ns/run")
	fmt.Println("sink:", sink)
}
