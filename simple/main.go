package main

import (
	"fmt"
	"math/rand"
	"time"
)

func compare(a int, b int) int {
	if a > b {
		return 1
	}
	if a < b {
		return -1
	}
	return 0
}

func swap(i *int, j *int) {
	temp := *i
	*i = *j
	*j = temp
}

func main() {
	const size = 5000 // Increase this further if needed
	arr := make([]int, size)

	// Seed random generator
	rand.Seed(time.Now().UnixNano())

	// Fill array with random numbers
	for i := 0; i < size; i++ {
		arr[i] = rand.Intn(100000)
	}

	length := len(arr)
	fmt.Println("Array size:", length)

	// Bubble Sort timing
	start := time.Now()

	for i := 0; i < length-1; i++ {
		for j := 0; j < length-1-i; j++ {
			if compare(arr[j], arr[j+1]) > 0 {
				swap(&arr[j], &arr[j+1])
			}
		}
	}

	elapsed := time.Since(start)

	fmt.Printf("Time taken (Bubble Sort): %d ns\n", elapsed.Nanoseconds())
}
