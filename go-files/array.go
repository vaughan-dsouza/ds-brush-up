package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"

	"github.com/vaughan/go-files/tests"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Println("\n=== Main Menu ===")
		fmt.Println("1) Swap (swap first two elements if present)")
		fmt.Println("2) Max (find maximum value)")
		fmt.Println("3) MergeSort (sort array)")
		fmt.Println("4) Run tests for all options")
		fmt.Println("0) Exit")
		fmt.Print("Select option: ")

		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		if input == "" {
			continue
		}
		sel, err := strconv.Atoi(input)
		if err != nil {
			fmt.Println("Invalid input:", err)
			continue
		}

		switch sel {
		case 0:
			fmt.Println("Goodbye.")
			return
		case 1, 2, 3:
			tests.RunTests(sel)
		case 4:
			for i := 1; i <= 3; i++ {
				tests.RunTests(i)
			}
		default:
			fmt.Println("Unknown option")
		}
	}
}
