package timer

import "time"

// TimeFunc runs f for `iterations` times and returns the average duration per run.
// If iterations <= 0, it defaults to 1.
func TimeFunc(f func(), iterations int) time.Duration {
	if iterations <= 0 {
		iterations = 1
	}
	start := time.Now()
	for i := 0; i < iterations; i++ {
		f()
	}
	total := time.Since(start)
	return total / time.Duration(iterations)
}

// TimeOnce runs f once and returns the duration.
func TimeOnce(f func()) time.Duration {
	start := time.Now()
	f()
	return time.Since(start)
}
