#!usr/bin/env python

# coding:utf8

'''
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
'''

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        map = {}
        result = []
        
        for i in nums:
            temp = target - i
            if map.__contains__(temp):
                result.append(map[temp])
                result.append(nums.index(i))

            map[i] = nums.index(i)


        return result


