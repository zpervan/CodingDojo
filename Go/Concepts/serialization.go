package Concepts

import (
	"encoding/json"
	"fmt"
)

type Example struct {
	Name string `json:"something_else"`
	Age  int    `json:"age"`
}

func SerializationExample() {
	example := Example{
		Name: "Zvonimir",
		Age:  32,
	}

	resultMarshalled, _ := json.MarshalIndent(example, "", " ")
	fmt.Println("Marshalled:\n", string(resultMarshalled))

	var resultUnmarshalled map[string]interface{}
	err := json.Unmarshal(resultMarshalled, &resultUnmarshalled)
	if err != nil {
		panic("could not unmarshal result")
	}

	fmt.Println("Unmarshalled: ", resultUnmarshalled)
}
