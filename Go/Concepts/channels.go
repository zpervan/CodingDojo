package Concepts

import "fmt"

func IncrementingValueChannelsExample() {
	counter := make(chan int)
	done := make(chan bool)

	for i := 0; i <= 5; i++ {
		go func(i int) {
			fmt.Println("starting worker thread ", i)

			value := <-counter
			value++

			if value == 6 {
				fmt.Println("arrived at the end")
				done <- true
				return
			}

			fmt.Println("value ", value)

			counter <- value
			fmt.Println("passed counter channel ", i)
		}(i)
	}
	// Writing to the "counter" channel will start the workers processing the data
	counter <- 0

	// Wait for all data to be processed
	<-done

	close(counter)
	close(done)
}

const dividableValue = 1024

func MultipleGoroutinesOneChannelExample() {
	value := make(chan int)
	done := make(chan bool)

	defer close(value)
	defer close(done)

	go func() {
		for {
			newValue := <-value
			println("[1] Received value: ", newValue)

			if newValue%dividableValue == 0 {
				println("Found value")
				done <- true
				break
			}

		}
	}()

	go func() {
		for {
			newValue := <-value
			println("[2] Received value: ", newValue)

			if newValue%dividableValue == 0 {
				println("Found value")
				done <- true
				break
			}

		}
	}()

	go func() {
		for {
			newValue := <-value
			println("[3] Received value: ", newValue)

			if newValue%dividableValue == 0 {
				println("Found value")
				done <- true
				break
			}

		}
	}()

	for i := 1; i <= dividableValue; i++ {
		println(i)
		value <- i
	}

	<-done
}
