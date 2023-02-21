package Concepts

import (
	"fmt"
	"reflect"
	"strconv"
)

func GenericFunction[T string | int](data []T) {

	switch reflect.TypeOf(data).String() {
	case "[]string":
		fmt.Println("It's a slice with strings")

	case "[]int":
		fmt.Println("It's a slice with ints")

	default:
		fmt.Println("Not a supported data type")
	}

	for i, k := range data {
		fmt.Println("Position: " + strconv.Itoa(i))
		fmt.Println(k)
	}
	fmt.Println(data)
}

func InterfaceDataType(anyData... any) {
	for _, v := range anyData{
		fmt.Println(v)
	}
}

func GenericsExample() {
    GenericFunction([]string{"ajnc", "cvaj"})
    GenericFunction([]int{10, 20})
	InterfaceDataType([]string{"was", "ist", "das"})
}
