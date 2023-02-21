package Concepts

import "fmt"

func incrementer() func() int {
	count := 0
	fmt.Println("incrementer is called")
	return func() int {
		count++
		return count
	}
}

func AnonymousFunctionExample() {
	sum := func(a, b int) int {
		return a + b
	}(3, 4)

	fmt.Println("Anonymous function result")
	fmt.Println(sum)
}

func ClosureExample() {
	fmt.Println("Closure result")

	inc := incrementer()
	fmt.Println(inc()) // 1
	fmt.Println(inc()) // 2
	fmt.Println(inc()) // 3
}
