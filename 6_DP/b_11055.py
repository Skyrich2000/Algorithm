import sys
sys.setrecursionlimit(100000)

n = int(input())
nums = list(map(int, input().split()))

dp = [0] * n

def rec(index):
	if index == n:
		return 0
	for i in range(index):
		if nums[i] < nums[index]:
			dp[index] = max(dp[i], dp[index])
	dp[index] += nums[index]
	return max(dp[index], rec(index + 1))

print(rec(0))
