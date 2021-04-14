str1, str2 = input(), input()
dp = [[0 for _ in range(len(str2) + 1)] for _ in range(len(str1) + 1)]

_max = 0
for i in range(len(str1)):
	for j in range(len(str2)):
		if str1[i] == str2[j]:
			dp[i + 1][j + 1] = dp[i][j] + 1
	_max = max(_max, max(dp[i + 1]))
print(_max)
