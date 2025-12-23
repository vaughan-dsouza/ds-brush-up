package tests

import (
	"fmt"

	"github.com/vaughan/go-files/mergesort"
	"github.com/vaughan/go-files/timer"
)

var testCases = [][]int{
	{5, 2, 8, 1, 9},
	{3},
	{7, 7, 7},
	{10, -1, 0},
	{2, 1},
}

// RunTests executes the requested option against a set of test arrays and prints results.
// option: 1=Swap, 2=Max, 3=MergeSort
func RunTests(option int) {
	switch option {
	case 1:
		runSwapTests()
	case 2:
		runMaxTests()
	case 3:
		runMergeSortTests()
	default:
		fmt.Println("Unknown test option")
	}
}

func runSwapTests() {
	fmt.Println("\n-- Swap Tests --")
	for i, arr := range testCases {
		fmt.Printf("Test #%d input: %v\n", i+1, arr)
		if len(arr) < 2 {
			fmt.Println("  Skipped (needs at least 2 elements)")
			continue
		}
		// Run once to show the result
		a := make([]int, len(arr))
		copy(a, arr)
		mergesort.SwapValues(&a[0], &a[1])

		// Time many iterations to get measurable average
		iterations := 100000
		avg := timer.TimeFunc(func() {
			b := make([]int, len(arr))
			copy(b, arr)
			mergesort.SwapValues(&b[0], &b[1])
		}, iterations)

		fmt.Printf("  After swap (first two elements): %v (avg %s over %d runs)\n", a, avg, iterations)
	}
}

func runMaxTests() {
	fmt.Println("\n-- Max Tests --")
	for i, arr := range testCases {
		fmt.Printf("Test #%d input: %v\n", i+1, arr)
		if len(arr) == 0 {
			fmt.Println("  Skipped (empty slice)")
			continue
		}
		m := mergesort.Max(arr)
		iterations := 100000
		avg := timer.TimeFunc(func() { _ = mergesort.Max(arr) }, iterations)
		fmt.Printf("  Max: %d (avg %s over %d runs)\n", m, avg, iterations)
	}
}

func runMergeSortTests() {
	fmt.Println("\n-- MergeSort Tests --")
	for i, arr := range testCases {
		fmt.Printf("Test #%d input: %v\n", i+1, arr)
		s := mergesort.MergeSort(arr)
		iterations := 10000
		avg := timer.TimeFunc(func() { _ = mergesort.MergeSort(arr) }, iterations)
		fmt.Printf("  Sorted: %v (avg %s over %d runs)\n", s, avg, iterations)
	}
}
