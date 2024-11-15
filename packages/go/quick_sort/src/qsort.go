package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// 퀵 정렬의 피벗을 기준으로 분할하는 함수
func partition(arr []int, low, high int) int {
	pivot := arr[high]
	i := low - 1

	for j := low; j < high; j++ {
		if arr[j] < pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}

// 퀵 정렬 함수
func quickSort(arr []int, low, high int) {
	if low < high {
		pi := partition(arr, low, high)
		quickSort(arr, low, pi-1)
		quickSort(arr, pi+1, high)
	}
}

func main() {
	// 파일 열기
	file, err := os.Open("input.txt")
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close()

	var data []int
	scanner := bufio.NewScanner(file)

	// 파일에서 정수 읽기
	for scanner.Scan() {
		line := scanner.Text()
		numbers := strings.Fields(line)
		for _, num := range numbers {
			value, err := strconv.Atoi(num)
			if err != nil {
				fmt.Println("Error converting string to int:", err)
				return
			}
			data = append(data, value)
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Println("Error reading file:", err)
		return
	}

	// 퀵 정렬 실행
	quickSort(data, 0, len(data)-1)

	// 정렬된 결과 출력
	fmt.Println("Sorted data:", data)
}
