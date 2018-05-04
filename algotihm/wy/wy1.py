#!/usr/bin/env python
#_*_coding:utf-8_*_

'''
为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。
牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。
在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，
牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你

对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。


输入例子1:
3 3 
1 100 
10 1000 
1000000000 1001 
9 10 1000000000

输出例子1:
100 
1000 
1001
'''

import sys
import bisect

task = {}
lines = sys.stdin.readlines()
n, m = map(int, lines[0].strip().split())

for line in lines[1:-1]:


	if not line.strip().split():
		continue
	a, b = map(int, line.strip().split())
	task[a] = b
	

arr = sorted(task.keys())
for i in range(1, len(arr)):
    if task[arr[i]] < task[arr[i -1]]:
        task[arr[i]] = task[arr[i -1]]

		
		
	
skills = map(int, lines[-1].strip().split())
for skill in skills:
	if skill in task:
		print(task[skill])
	else:
		ind = bisect.bisect(arr, skill)

		# if ind == 0:
			# print 0
		# else:
			# print(task[arr[ind -1]])


