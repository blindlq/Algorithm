package main

import "fmt"

func main()  {
	var nums = []int{2,4,11,2}
	var target = 4

	var result = twoSum(nums,target)

	fmt.Println(result)
}

func twoSum(nums []int, target int) []int {
	m := map[int]int{}
	for i,v := range nums {
		if k,ok := m[target-v]; ok {
			return []int{k,i}
		}

		m[v] = i
	}

	return nil
}