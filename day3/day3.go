package main

import (
	"bufio"
	"os"
	"fmt"
	"unicode"
)

const upperFactor = 38
const lowerFactor = 96

func main() {
	part1()
	part2()
}

func part2() {
	file, err := os.Open("input.txt")

	if err != nil {
		panic("Couldn't read file")
	}

	scanner := bufio.NewScanner(file)
	total := 0

	linesGroup := make([]string, 0)
	for scanner.Scan() {
		text := scanner.Text()
		linesGroup = append(linesGroup, text)
		if (len(linesGroup) == 3) {
			value := parseGroupBackpack(linesGroup)
			total += value
			linesGroup = []string{}
		}
	}

	fmt.Println(total)
}

func part1() {
	file, err := os.Open("input.txt")

	if err != nil {
		panic("Couldn't read file")
	}

	scanner := bufio.NewScanner(file)
	totalPriority := 0

	for scanner.Scan() {
		text := scanner.Text()
		priority := parseBackpack(text)
		totalPriority += priority
	}

	fmt.Println("TOTAL priority of itemTypes, ", totalPriority)
}

func parseGroupBackpack(s []string) int {
	mapping := make(map[rune]int)

	var commonValue rune

	for _, value := range s[0] {
		mapping[value] = mapping[value] + 1
	}

	for _, value := range s[1] {
		if (mapping[value] != 0) {
			mapping[value] = -1
		}
	}

	for _, value := range s[2] {
		if (mapping[value] == -1) {
			commonValue = value
		}
	}

	fmt.Println("common: ", commonValue)

	return getPriorityValue(commonValue)
}

func parseBackpack(s string) int {
	mapping := make(map[rune]int)

	var commonValue rune
	half := len(s) / 2
	firstHalf := s[half:]
	secondHalf := s[:half]

	for _, value := range firstHalf {
		mapping[value] = mapping[value] + 1
	}

	for _, value := range secondHalf {
		if (mapping[value] != 0) {
			commonValue = value
		}
	}

	return getPriorityValue(commonValue)
}

func getPriorityValue(s rune) int {
	if (unicode.IsUpper(s)) {
		return int(s - upperFactor)
	} else {
		return int(s - lowerFactor)
	}
}
