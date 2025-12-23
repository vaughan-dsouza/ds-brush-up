package mergesort

import (
	"fmt"
	"math/rand"
	"testing"
)

var rnd = rand.New(rand.NewSource(42))

func makeRandom(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = rnd.Intn(1000000)
	}
	return a
}

func BenchmarkMax(b *testing.B) {
	sizes := []int{5, 100, 1000, 10000}
	for _, n := range sizes {
		b.Run(fmt.Sprintf("Max_%d", n), func(b *testing.B) {
			arr := makeRandom(n)
			b.ReportAllocs()
			b.ResetTimer()
			for i := 0; i < b.N; i++ {
				_ = Max(arr)
			}
		})
	}
}

func BenchmarkMergeSort(b *testing.B) {
	sizes := []int{5, 100, 1000, 10000}
	for _, n := range sizes {
		b.Run(fmt.Sprintf("MergeSort_%d", n), func(b *testing.B) {
			arr := makeRandom(n)
			b.ReportAllocs()
			b.ResetTimer()
			for i := 0; i < b.N; i++ {
				_ = MergeSort(arr)
			}
		})
	}
}

func BenchmarkSwap(b *testing.B) {
	arr := makeRandom(2)
	b.ReportAllocs()
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		// operate on a small copy to avoid aliasing across iterations
		a := make([]int, 2)
		copy(a, arr)
		SwapValues(&a[0], &a[1])
	}
}
