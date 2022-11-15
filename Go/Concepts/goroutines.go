package Concepts

import (
	"fmt"
	"strconv"
	"sync"
	"time"
)

func someConcurrentFunction(wg *sync.WaitGroup) {
	defer wg.Done()

	time.Sleep(2 * time.Second)

	fmt.Println("Time is up - Calling no argument function")
}

func GoroutinesExample() {
	wg := sync.WaitGroup{}
	wg.Add(2)

	fmt.Println("Starting goroutines")

	go someConcurrentFunction(&wg)
	go func() {
		defer wg.Done()
		fmt.Println("Calling from a closure")
		for i := 0; i < 10; i++ {
			fmt.Println("Printing " + strconv.Itoa(i))
		}
	}()

	wg.Wait()
}
