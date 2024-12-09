package main

import (
	"fmt"
	"log"
	"math"
	"os"
	"strconv"
	"strings"
)

func readFile() string {
	filepath := "../../input/day2.txt"
	data, e := os.ReadFile(filepath)
	if e != nil {
		log.Fatal("[ERROR] while reading file: ", e)
		os.Exit(1)
	}
	fmt.Println("[INFO] file: ", filepath, " read successfully!")
	fmt.Println(string(data))

	contents := string(data)
	return contents
}

func main() {
	contents := readFile()
	part1(contents)
	part2(contents)
}

func isIncreasing(array []int) bool {
	for i := range len(array) - 1 {
		if array[i] > array[i+1] {
			return false
		}
	}
	return true
}
func isDecreasing(array []int) bool {
	for i := range len(array) - 1 {
		if array[i] < array[i+1] {
			return false
		}
	}
	return true
}

func part1(contents string) {
	reports := strings.Split(contents, "\r\n")
	safe := 0
	for i := range len(reports) {
		rep := strings.Split(reports[i], " ")
		report := make([]int, 0)
		for j := range len(rep) {
			val, e := strconv.ParseInt(rep[j], 10, 0)
			if e != nil {
				println("Error parsing report: ", e)
				os.Exit(1)
			}
			report = append(report, int(val))
		}
		check := isSafe(report, i)
		if check {
			safe++
		}
		continue
	}
	println("safe: ", safe)
}
func isSafe(report []int, index int) (check bool) {
	check = true
	isI := isIncreasing(report)
	isD := isDecreasing(report)
	if !isI && !isD {
		println("Neither decreasing nor increasing report found!", index)
		check = false
		return check
	}
	for j := range len(report) - 1 {
		diff := math.Abs(float64(report[j] - report[j+1]))
		if diff < 1 || diff > 3 {
			check = false
			return check
		}
	}
	return check
}
func part2(contents string) {
	reports := strings.Split(contents, "\r\n")
	safe := 0
	for i := range len(reports) {
		rep := strings.Split(reports[i], " ")
		report := make([]int, 0)
		for j := range len(rep) {
			val, e := strconv.ParseInt(rep[j], 10, 0)
			if e != nil {
				println("Error parsing report: ", e)
				os.Exit(1)
			}
			report = append(report, int(val))
		}
		fmt.Println("report: ", report)

		check := isSafe(report, i)
		if check {
			safe++
			continue
		}
		x := true
		for j := 0; j < len(report); j++ {
			arr := make([]int, 0)
			for k := 0; k < len(report); k++ {
				if j == k {
					continue
				}
				arr = append(arr, report[k])
			}
			fmt.Println(arr)
			check = isSafe(arr, i)
			if check {
				x = false
				break
			}
		}
		if !x {
			safe++
		}
	}
	println("safe: ", safe)
}
