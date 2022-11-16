package Concepts

import (
	"fmt"
	"sync"
)

func SyncExamples() {
	once := sync.Once{}
	for i := 0; i < 10; i++ {
		once.Do(func() { fmt.Println("Called from closure. Called: ", i) })

		fmt.Println("Index: ", i)
	}
}
