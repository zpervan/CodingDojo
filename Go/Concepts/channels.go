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