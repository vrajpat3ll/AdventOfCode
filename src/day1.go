package main

import (
	"fmt"
	"log"
	"math"
	"os"
	"sort"
)

func main() {
	part1()
	part2()
}

func part2() {
	filepath := "../input/day1.txt"
	data, e := os.ReadFile(filepath)

	if e != nil {
		log.Fatal("[ERROR] while reading file: ", e)
		os.Exit(1)
	}
	fmt.Println("[INFO] file: ", filepath, " read successfully!")
	fmt.Println(string(data))

	contents := string(data)
	leftList := make([]int32, 0)
	rightList := make([]int32, 0)

	for i := 0; i < len(contents); i++ {
		fmt.Println(int(contents[i]) - '0')
		left := 0
		for ; i < len(contents) && contents[i] != ' '; i++ {
			left = 10*left + int(contents[i]) - '0'
		}
		i += 3
		right := 0
		fmt.Println(contents[i] - '0')
		for ; i < len(contents) && (contents[i] != '\n' && contents[i] != '\r'); i++ {
			right = 10*right + int(contents[i]) - '0'
		}
		if i < len(contents) && contents[i] == '\r' {
			i++
		}
		fmt.Println("L: ", left, "R: ", right)
		leftList = append(leftList, int32(left))
		rightList = append(rightList, int32(right))
		fmt.Println("L: ", leftList, "R: ", rightList)
	}
	sort.Slice(leftList, func(i, j int) bool {
		return int(leftList[i]) < int(leftList[j])
	})
	sort.Slice(rightList, func(i, j int) bool {
		return int(rightList[i]) < int(rightList[j])
	})

	fmt.Println("L: ", leftList)
	fmt.Println("R: ", rightList)
	sum := 0
	len := len(leftList)
	var mpp map[int]int = make(map[int]int)
	for i := 0; i < len; i++ {
		mpp[int(rightList[i])]++
	}
	for i := 0; i < len; i++ {
		sum += int(leftList[i]) * mpp[int(leftList[i])]
	}
	println("sum:", sum)
}

func part1() {
	filepath := "../input/day1.txt"
	data, e := os.ReadFile(filepath)

	if e != nil {
		log.Fatal("[ERROR] while reading file: ", e)
		os.Exit(1)
	}
	fmt.Println("[INFO] file: ", filepath, " read successfully!")
	fmt.Println(string(data))

	contents := string(data)
	leftList := make([]int32, 0)
	rightList := make([]int32, 0)

	for i := 0; i < len(contents); i++ {
		fmt.Println(int(contents[i]) - '0')
		left := 0
		for ; i < len(contents) && contents[i] != ' '; i++ {
			left = 10*left + int(contents[i]) - '0'
		}
		i += 3
		right := 0
		fmt.Println(contents[i] - '0')
		for ; i < len(contents) && (contents[i] != '\n' && contents[i] != '\r'); i++ {
			right = 10*right + int(contents[i]) - '0'
		}
		if i < len(contents) && contents[i] == '\r' {
			i++
		}
		fmt.Println("L: ", left, "R: ", right)
		leftList = append(leftList, int32(left))
		rightList = append(rightList, int32(right))
		fmt.Println("L: ", leftList, "R: ", rightList)
	}
	sort.Slice(leftList, func(i, j int) bool {
		return int(leftList[i]) < int(leftList[j])
	})
	sort.Slice(rightList, func(i, j int) bool {
		return int(rightList[i]) < int(rightList[j])
	})

	fmt.Println("L: ", leftList)
	fmt.Println("R: ", rightList)
	sum := 0
	len := len(leftList)
	for i := 0; i < len; i++ {
		sum += int(math.Abs(float64(int(leftList[i]) - int(rightList[i]))))
	}
	println("sum:", sum)
}
