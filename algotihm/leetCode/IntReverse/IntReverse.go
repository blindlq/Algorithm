package main

import "fmt"

func main()  {

	a := -123

	 result := reverse(a)

	fmt.Println(result)
}

func reverse(x int) int {
	INT_Max := int(^uint32(0) >> 1)
	INT_Min := ^INT_Max

	rev := 0
	for {
		if x == 0 {
			break
		}

		pop := x % 10

		//大于最大整数2^32 -1
		if rev > INT_Max/10 || ( rev == INT_Max/10 && pop > 7) {
			return 0
		}
		//小于最小整数-2^32
		if rev < INT_Min/10 || (rev == INT_Min/10 && pop < -8) {
			return 0
		}

		x /= 10

		rev = rev * 10 + pop

	}

	return rev
}

func reverse2(x int) int {
	var rev int
	for x != 0 {

		if temp := int32(rev); (temp*10)/10 != temp {
			return 0
		}

		rev = rev * 10 + x % 10
		x /= 10

	}

	return rev
}


