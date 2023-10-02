package main

import (
	"log"
	"os"
	"slices"
	"strconv"
	"strings"
)

func main() {
	part1()
	part2()
}

func parseInput() ([][]string, [][3]int64) {
	file, err := os.ReadFile("input.txt")
	checkNilErr(err)

	fileContent := string(file)
	parts := strings.Split(fileContent, "\n\n")

	crate_lines := strings.Split(parts[0], "\n")

	stack := [][]string{}

	for line_idx:=len(crate_lines)-1; line_idx>=0; line_idx-- {
		line := crate_lines[line_idx]
		stack_idx := 0

		for idx := 0; idx < len(line); idx += 4 {
			element := line[idx : idx+3]
			print(element + " ")
			if (stack_idx >= len(stack)) {
				stack = append(stack, []string{})
			}
			
			if line[idx] == '[' {
				stack[stack_idx] = append(stack[stack_idx], element)
				// stack[stack_idx][len(crate_lines)-1-line_idx-1] = element
			}
			stack_idx++
		}
		println()
	}

	for _, els := range stack {
		for _, el := range els {
			print(el, ", ")
		}
		println()
	}
	// Now parsing the changes
	// [c, a, b] => moving from a to b, count=c 
	instructions := [][3]int64{}
	for _, line := range(strings.Split(parts[1], "\n")) {
		words := strings.Split(line, " ")
		if len(words) < 5 {
			continue
		}

		c, err := strconv.ParseInt(words[1], 10, 64)
		checkNilErr(err)
		a, err := strconv.ParseInt(words[3], 10, 64)
		checkNilErr(err)
		b, err := strconv.ParseInt(words[5], 10, 64)
		checkNilErr(err)

		instructions = append(instructions, [3]int64{c, a, b})
	}

	return stack, instructions
}

func part1() {
	stack, instructions := parseInput()
	for _, ins := range(instructions) {
		c, a, b  := ins[0], ins[1], ins[2]
		a--; b--;
		slice := stack[a][len(stack[a])-int(c):]
		slices.Reverse(slice)
		stack[b] = append(stack[b], slice...)
		stack[a] = stack[a][:len(stack[a])-int(c)]

		println()
		println(ins[0], ins[1], ins[2])
		for _, els := range(stack) {
			for _, el := range(els) {
				print(el, ", ")
			}
			println()
		}
	}
	ans := ""
	for _, el := range(stack) {
		last := el[len(el)-1]
		ans += string(last[1])
	}
	println()
	println(ans)
}

func part2() {
	stack, instructions := parseInput()
	for _, ins := range(instructions) {
		c, a, b  := ins[0], ins[1], ins[2]
		a--; b--;
		slice := stack[a][len(stack[a])-int(c):]
		stack[b] = append(stack[b], slice...)
		stack[a] = stack[a][:len(stack[a])-int(c)]

		println()
		println(ins[0], ins[1], ins[2])
		for _, els := range(stack) {
			for _, el := range(els) {
				print(el, ", ")
			}
			println()
		}
	}
	ans := ""
	for _, el := range(stack) {
		last := el[len(el)-1]
		ans += string(last[1])
	}
	println()
	println(ans)

}

func checkNilErr(err error) {
	if err != nil {
		log.Fatal(err)
	}
}
