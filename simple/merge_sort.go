package main

import (
	"fmt"
	"time"
)

func merge_Sort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}

	mid := len(arr) / 2
	left := merge_Sort(arr[:mid])
	right := merge_Sort(arr[mid:])

	i, j := 0, 0
	result := make([]int, 0, len(arr))

	for i < len(left) || j < len(right) {
		if i < len(left) && j < len(right) {
			if left[i] > right[j] {
				result = append(result, right[j])
				j++
			} else {
				result = append(result, left[i])
				i++
			}
		} else if i < len(left) {
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}

	return result
}

func main() {
	arr := []int{
		73, 12, 88, 45, 6, 91, 34, 17, 59, 2,
		84, 26, 67, 9, 53, 41, 98, 21, 75, 14,
		62, 8, 90, 33, 57, 19, 86, 4, 48, 71,
		25, 64, 11, 97, 38, 5, 82, 29, 69, 16,
		55, 93, 7, 44, 80, 23, 61, 10, 76, 35,
		89, 1, 52, 68, 18, 95, 27, 60, 13, 83,
		40, 99, 20, 72, 31, 56, 94, 15, 65, 46,
		3, 87, 24, 58, 70, 36, 92, 22, 79, 50,
	}

	start := time.Now()
	sorted := merge_Sort(arr)
	elapsed := time.Since(start)

	fmt.Println("Sorted:", sorted)
	fmt.Println("Execution Time:", elapsed.Nanoseconds(), "ns")

}
