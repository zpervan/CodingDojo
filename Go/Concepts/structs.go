package Concepts

import (
	"fmt"
	"strconv"
)

type Entity interface {
	Eat(food interface{})
	Sleep(amount int)
}

// Children structs which implements the Entity interface
type Dog struct {
	name string
	age  int
}

type Cat struct {
	name string
	age  int
}

// Interface method implementations
func (d Dog) Eat(food interface{}) {
	switch food.(type) {
	case int:
		fmt.Println("Oh no, the dog is eating the math homework!")
	case string:
		fmt.Println("The dog is eating " + food.(string))
	}
}

func (d Dog) Sleep(amount int) {
	fmt.Println("The dog sleeps " + strconv.Itoa(amount) + " hours")
}

func (d Dog) Bark() {
	fmt.Println("woof")
}

func (c Cat) Eat(food interface{}) {
	switch food.(type) {
	case int:
		fmt.Println("Oh no, the cat is eating the math homework!")
	case string:
		fmt.Println("The cat is eating " + food.(string))
	}
}

func (c Cat) Sleep(amount int) {
	fmt.Println("The cat sleeps " + strconv.Itoa(amount) + " hours")
}

func UseEntityMethods(entity Entity) {
	entity.Eat("meat")
	entity.Sleep(10)
}

func StructInterfaceExample() {
	var dog Dog
	UseEntityMethods(dog)

	var cat Cat
	UseEntityMethods(cat)
}

//////////////////////////////////////////////////////////////////////////////

type Base struct {
    data     string
    moreData string
}

func (b Base) TheBaseFunction() {
    fmt.Println("Helou")
}

type Derived struct {
    Base
    whoDis string
}

func StructEmbeddedExample() {
    derivedData := &Derived{}
    derivedData.TheBaseFunction()
}