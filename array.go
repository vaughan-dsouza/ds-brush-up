package main

import "fmt"

// Swap two integer values via pointers
func swapValues[T any](a, b *T) {
	temp := *a
	*a = *b
	*b = temp
}

// Find maximum value in a slice
func max(arr []int) int {
	maximum := arr[0]
	for _, v := range arr {
		if v > maximum {
			maximum = v
		}
	}
	return maximum
}

func main() {
	// Initialize slice
	arr := []int{5, 2, 8, 1, 9}
	fmt.Println("Slice:", arr)

	// Find maximum
	maximum := max(arr)
	fmt.Println("Maximum value:", maximum)

	// Test swap
	x, y := 5, 10
	swapValues(&x, &y)
	fmt.Println("After swap: x =", x, "y =", y)
}
