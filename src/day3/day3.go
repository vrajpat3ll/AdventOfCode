package main

import (
	"fmt"
	"log"
	"os"
)

func readFile() string {
	filepath := "../../input/day3.txt"
	data, e := os.ReadFile(filepath)
	if e != nil {
		log.Fatal("[ERROR] while reading file: ", e)
		os.Exit(1)
	}
	fmt.Println("[INFO] file: ", filepath, " read successfully!")

	contents := string(data)
	return contents
}

func main() {
	contents := readFile()
	part1(contents)
	part2(contents)
}

func part1(contents string) {
	// fmt.Println(contents)
	var sum uint64 = 0
	x := 0
	for i := 0; i+3 < len(contents); i++ {
		// parse mul instruction
		if contents[i:i+3] == "mul" {
			i += 3
			var num1 uint64 = 0
			var num2 uint64 = 0
			if i < len(contents) && contents[i] == '(' {
				i++
				// parse int
				for ; i < len(contents) && '0' <= contents[i] && contents[i] <= '9'; i++ {
					num1 = 10*num1 + uint64(contents[i]-'0')
				}
				if contents[i] == ',' {
					i++
					// parse int
					for ; i < len(contents) && '0' <= contents[i] && contents[i] <= '9'; i++ {
						num2 = 10*num2 + uint64(contents[i]-'0')
					}
					if num1 >= 1000 || num2 >= 1000 {
						continue
					}
					if contents[i] == ')' {
						x++
						// fmt.Println(x, num1, num2)
						sum += num1 * num2
					}
				}
			}
		}
	}
	// fmt.Println("sum: ", sum)
}
func part2(contents string) {
	var sum uint64 = 0
	x := 0
	do := true
	for i := 0; i+3 < len(contents); i++ {
		// activate mul parsing
		if i+4 < len(contents) && contents[i:i+4] == "do()" {
			do = true
		}
		// deactivate mul parsing
		if i+7 < len(contents) && contents[i:i+7] == "don't()" {
			do = false
		}
		if do {
			// parse mul instruction
			if contents[i:i+3] == "mul" {
				i += 3
				var num1 uint64 = 0
				var num2 uint64 = 0
				if i < len(contents) && contents[i] == '(' {
					i++
					// parse int
					for ; i < len(contents) && '0' <= contents[i] && contents[i] <= '9'; i++ {
						num1 = 10*num1 + uint64(contents[i]-'0')
					}
					if contents[i] == ',' {
						i++ 
						// parse int
						for ; i < len(contents) && '0' <= contents[i] && contents[i] <= '9'; i++ {
							num2 = 10*num2 + uint64(contents[i]-'0')
						}
						if num1 >= 1000 || num2 >= 1000 {
							continue
						}
						if contents[i] == ')' {
							x++
							fmt.Println(x, num1, num2)
							sum += num1 * num2
						}
					}
				}
			}
		}
	}
	fmt.Println("sum: ", sum)

}
