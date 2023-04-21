package Concepts

import (
	"fmt"
	"math/rand"
	"sort"
)

const numberOfSlicesWithRandomNumbers = 5
const numberOfElementsWithRandomNumbers = 5

func GenerateSlicesWithRandomNumbers() [][]int {
	println("Generating slices with random numbers")

	slices := make([][]int, numberOfSlicesWithRandomNumbers)

	for i, slice := range slices {
		slice = make([]int, numberOfElementsWithRandomNumbers)

		for j := 0; j < numberOfElementsWithRandomNumbers; j++ {
			slice[j] = rand.Intn(1000)
		}

		slices[i] = slice
	}

	// Print all values
	//for i, slice := range slices {
	//	println("Slice #", i)
	//
	//	for _, value := range slice {
	//		println("Value: ", value)
	//	}
	//}

	return slices
}

func SortValues(values *[]int) {
	println("Sorting values")
	sort.Ints(*values)
}

func Process(channel <-chan []int, done chan<- bool) {
	for {
		values, more := <-channel

		if more {
			SortValues(&values)

			message := "Sorted values: "
			for _, value := range values {
				message += fmt.Sprintf("%d,", value)
			}

			println(message)
		} else {
			println("Jobs done...")
			done <- true
			return
		}
	}
}

func ExampleWithChannelsAndSortingSlices() {
	slices := GenerateSlicesWithRandomNumbers()

	channelOne := make(chan []int)
	channelTwo := make(chan []int)
	channelThree := make(chan []int)

	done := make(chan bool)
	defer close(done)

	go Process(channelOne, done)
	go Process(channelTwo, done)
	go Process(channelThree, done)

	for i, slice := range slices {
		select {
		case channelOne <- slice:
			println("Sending to channelOne")
		case channelTwo <- slice:
			println("Sending to channelTwo")
		case channelThree <- slice:
			println("Sending to channelThree")
		}

		println("Sent slice #", i)
	}

	close(channelOne)
	close(channelTwo)
	close(channelThree)

	<-done
}
