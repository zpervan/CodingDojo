package Concepts

import (
	"fmt"
	//	"strconv"
	"sync"
	"time"
)

func dummyFunction(wg *sync.WaitGroup) {
	defer wg.Done()

	time.Sleep(2 * time.Second)

	fmt.Println("Time is up - Calling no argument function")
}

func closureExample(wg *sync.WaitGroup) {
	go func() {
		defer wg.Done()
		fmt.Println("Calling from a closure")
		for i := 0; i < 10; i++ {
			fmt.Println("Printing ", i)
		}
	}()
}
func selectExample() {
	channelOne := make(chan int)
	channelTwo := make(chan int)

	go func() {
		time.Sleep(2 * time.Second)
		channelOne <- 10
	}()

	go func() {
		time.Sleep(1 * time.Second)
		channelTwo <- 20
	}()

	for i := 0; i < 2; i++ {
		select {
		case msgOne := <-channelOne:
			fmt.Println("Printing message one: ", msgOne)

		case msgTwo := <-channelTwo:
			fmt.Println("Printing message two: ", msgTwo)
		}
	}

	close(channelOne)
	close(channelTwo)
}

var count int
var mutex sync.Mutex
func increment() {
    mutex.Lock()
    count++
    mutex.Unlock()
}

func mutexExample() {
    fmt.Println("mutex example")
    var wg sync.WaitGroup
    for i := 0; i < 10; i++ {
        wg.Add(1)
        go func() {
            defer wg.Done()
            increment()
        }()
    }
    wg.Wait()
    fmt.Println("Count:", count)
}

func GoroutinesExample() {
	wg := sync.WaitGroup{}
	wg.Add(2)

	fmt.Println("Starting goroutines")

	dummyFunction(&wg)
	closureExample(&wg)
    mutexExample()

	selectExample()
}
