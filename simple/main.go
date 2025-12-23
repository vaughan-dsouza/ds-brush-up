package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func greaterThan(a int, b int) bool {
	if a > b {
		return true
	}
	return false
}

func swap(i *int, j *int) {
	temp := *i
	*i = *j
	*j = temp
}

// Quick Sort
func quickSort(a []int, low, high int) {
	if low >= high {
		return
	}
	p := partition(a, low, high)
	quickSort(a, low, p-1)
	quickSort(a, p+1, high)
}

func partition(a []int, low, high int) int {
	pivot := a[high]
	i := low
	for j := low; j < high; j++ {
		if a[j] < pivot {
			a[i], a[j] = a[j], a[i]
			i++
		}
	}
	a[i], a[high] = a[high], a[i]
	return i
}

// Merge Sort
func mergeSort(a []int) []int {
	lengthA := len(a)
	if lengthA == 1 {
		return a
	}

	partition := lengthA / 2

	left := mergeSort(a[0:partition])
	right := mergeSort(a[partition:lengthA])

	leftL := len(left)
	rightL := len(right)

	result := []int{}

	for i, j := 0, 0; i < leftL || j < rightL; {
		if i < leftL && j < rightL {
			if greaterThan(left[i], right[j]) {
				result = append(result, right[j])
				j++
			} else {
				result = append(result, left[i])
				i++
			}
		} else if i < leftL {
			result = append(result, left[i])
			i++
		} else if j < rightL {
			result = append(result, right[j])
			j++
		}
	}

	return result
}

// renaming main to main1 to temporaily run main in merge_sort
func main1() {
	const size = 5000
	arr := make([]int, size)

	r := rand.New(rand.NewSource(time.Now().UnixNano()))

	// Fill array with random numbers
	for i := 0; i < size; i++ {
		arr[i] = r.Intn(100000)
	}

	fmt.Println("Array size:", len(arr))

	// Keep original unsorted input so timings are comparable
	orig := make([]int, len(arr))
	copy(orig, arr)

	// -------------------
	// Bubble Sort timing
	// -------------------
	bubbleArr := make([]int, len(orig))
	copy(bubbleArr, orig)

	start := time.Now()

	for i := 0; i < len(bubbleArr)-1; i++ {
		for j := 0; j < len(bubbleArr)-1-i; j++ {
			if greaterThan(bubbleArr[j], bubbleArr[j+1]) {
				swap(&bubbleArr[j], &bubbleArr[j+1])
			}
		}
	}

	elapsed := time.Since(start)
	fmt.Printf("Time taken (Bubble Sort): %d ns\n", elapsed.Nanoseconds())

	// -------------------
	// Quick Sort timing
	// -------------------
	quickArr := make([]int, len(orig))
	copy(quickArr, orig)

	start = time.Now()
	quickSort(quickArr, 0, len(quickArr)-1)
	elapsed = time.Since(start)

	fmt.Printf("Time taken (Quick Sort): %d ns\n", elapsed.Nanoseconds())

	// -------------------
	// Merge Sort timing
	// -------------------
	mergeArr := make([]int, len(orig))
	copy(mergeArr, orig)

	start = time.Now()
	mergeSort(mergeArr)
	elapsed = time.Since(start)

	fmt.Printf("Time taken (Merge Sort): %d ns\n", elapsed.Nanoseconds())

	// -------------------
	// Sort timing
	// -------------------
	sortArr := make([]int, len(orig))
	copy(sortArr, orig)

	start = time.Now()
	sort.Ints(arr)
	elapsed = time.Since(start)

	fmt.Printf("Time taken (Sort): %d ns\n", elapsed.Nanoseconds())

}
