package mergesort

// SwapValues swaps two values using generics.
func SwapValues[T any](a, b *T) {
	temp := *a
	*a = *b
	*b = temp
}

// Max returns the maximum value from a non-empty slice of ints.
func Max(arr []int) int {
	if len(arr) == 0 {
		panic("slice is empty")
	}
	m := arr[0]
	for _, v := range arr {
		if v > m {
			m = v
		}
	}
	return m
}

// MergeSort performs a merge sort on a slice of ints and returns a sorted copy.
func MergeSort(a []int) []int {
	if len(a) <= 1 {
		return append([]int(nil), a...)
	}
	mid := len(a) / 2
	left := MergeSort(a[:mid])
	right := MergeSort(a[mid:])
	return merge(left, right)
}

func merge(a, b []int) []int {
	res := make([]int, 0, len(a)+len(b))
	i, j := 0, 0
	for i < len(a) && j < len(b) {
		if a[i] <= b[j] {
			res = append(res, a[i])
			i++
		} else {
			res = append(res, b[j])
			j++
		}
	}
	if i < len(a) {
		res = append(res, a[i:]...)
	}
	if j < len(b) {
		res = append(res, b[j:]...)
	}
	return res
}
