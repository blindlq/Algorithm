package main

import "fmt"
import "sync"

func main()  {

	var wg sync.WaitGroup

	for _, s := range []string{"a","b","c"} {
		wg.Add(1)

		go func(s string) {
			defer wg.Done()
			fmt.Println(s)
		}(s)
	}
	wg.Wait()

	//
	//result := characterReplacement(a,k)
	//
	//fmt.Println(result)
}

//func characterReplacement(s string, k int) int {
//	if s == "" {
//		return 0
//	}
//	// 左指针 / 右指针
//	left, right := 0, 0
//	// 最长长度 / 当前窗口所有字符计数
//	maxLen, m := 0, make(map[uint8]int)
//	for right = 0; right < len(s); right++ {
//		m[s[right]]++
//		maxLen = Max(maxLen, m[s[right]]) // 当前窗口最多的字符计数
//		// 如果窗口无法满足凑成全部一样的字符，滑动左指针
//		if right-left+1 > maxLen+k {
//			m[s[left]]--
//			left++
//		}
//	}
//	return len(s) - left
//}
//
//
//func characterReplacement2(s string, k int) int {
//	var length,i,j,temp int
//	var max = 0
//	var currmax = 1
//	var sameIndex uint8
//	var arr map[uint8]int
//
//	length = len(s)
//
//	if length == 0 || length == 1 {
//		return length
//	}
//
//	if k == 0 {
//		for i=1; i <length ; i++ {
//			//println(s[i])
//			if s[i] == s[i-1] {
//				currmax++
//			} else {
//				max = Max(max, currmax)
//				currmax = 1
//			}
//		}
//
//		return Max(max,currmax)
//	}
//
//	for i=0; i< length; i++ {
//		arr = map[uint8]int{}
//		temp = k
//		sameIndex = s[i]
//		arr[s[i]-65]++
//		for j=i+1; j<length; j++ {
//			arr[s[j]-65]++
//			//判断i-j内最大个数的重复元素
//			if arr[s[j]-65] > arr[sameIndex-65] {
//				sameIndex = s[j]
//			}
//
//			if s[j] != sameIndex {
//				if temp ==0 {
//					break
//				}
//
//				temp--
//				currmax = j-i+1
//				max = Max(max, currmax)
//			} else {
//				currmax++
//			}
//
//		}
//
//		max = Max(max, currmax)
//		if max > (length-i-1) {
//			break;
//		}
//
//	}
//
//
//	return max
//}
//
//func Max(a int, b int) int {
//	if a > b {
//		return a
//	}
//
//	return b
//}