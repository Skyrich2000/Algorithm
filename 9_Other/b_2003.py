# 두 포인터

n, m = map(int, input().split())
num = list(map(int, input().split()))

count = 0
start = 0
end = 0
summ = 0
# while (1):
# 	if summ < m:
# 		if end >= n:
# 			break
# 		summ += num[end]
# 		end += 1
# 	elif summ >= m:
# 		summ -= num[start]
# 		start += 1
# 	if summ == m:
# 		count += 1
# print(count)

# 구간을 start 이상 end 미만으로 계산하는게 편함
# summ < m 인데 end 가 끝에 있으면 break 다.
# summ 연산이 다 끝난후에 m 과 같은지 확인하는 방식

summ = num[end]
while (1):
	if summ == m:
		count += 1
	if summ < m:
		end += 1
		if end >= n:
			break
		summ += num[end]
	elif summ >= m:
		summ -= num[start]
		start += 1
print(count)

# 아래꺼는 start 이상 end 이하로 계산할때
# summ == m 의 조건을 고려하는 순서가 먼저와야한다.
# 포인터가 이동되고 summ 이 연산되기 때문에
# 포인터를 이동시키기전에 m 과 같은지 확인해야함
