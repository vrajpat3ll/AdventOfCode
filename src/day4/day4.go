package main

import (
	"fmt"
	"log"
	"os"
	"strings"
)

func readFile() string {
	filepath := "../../input/day4.txt"
	data, e := os.ReadFile(filepath)
	if e != nil {
		log.Fatal("[ERROR] while reading file: ", e)
		os.Exit(1)
	}
	fmt.Println("[INFO] file: ", filepath, " read successfully!")
	// fmt.Println(string(data))

	contents := string(data)
	return contents
}

func main() {
	contents := readFile()
	part1(contents)
	part2(contents)
}

func part1(contents string) {
	lines := strings.Split(contents, "\n")
	for i := 0; i < len(contents); i++ {
		
	}
}
func part2(contents string) {

}
