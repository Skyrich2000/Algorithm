n, m, r = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]
operates = list(map(int, input().split()))

def operate_1():
	for i in range(int(n/2)):
		arr[i], arr[-i - 1] = arr[-i - 1], arr[i]

def operate_2():
	for j in range(int(m/2)):
		for i in range(n):
			arr[i][j], arr[i][-j - 1] = arr[i][-j - 1], arr[i][j]

def operate_3():
	global arr, n, m

	tmp = [[] for _ in range(m)]
	for j in reversed(arr):
		for i, v in enumerate(j):
			tmp[i].append(v)
	n, m = m, n
	arr = tmp

def operate_4():
	global arr, n, m

	tmp = [[] for _ in range(m)]
	for j in arr:
		for i, v in enumerate(reversed(j)):
			tmp[i].append(v)
	n, m = m, n
	arr = tmp

def operate_5():
	_n = int(n/2)
	_m = int(m/2)
	for i in range(_n):
		for j in range(_m):
			arr[i][j], arr[i][_m + j], arr[_n + i][j], arr[_n + i][_m + j] = \
			arr[_n + i][j], arr[i][j], arr[_n + i][_m + j], arr[i][_m + j]

def operate_6():
	_n = int(n/2)
	_m = int(m/2)
	for i in range(_n):
		for j in range(_m):
			arr[i][j], arr[i][_m + j], arr[_n + i][j], arr[_n + i][_m + j] = \
			arr[i][_m + j], arr[_n + i][_m + j], arr[i][j], arr[_n + i][j]

func = [operate_1, operate_2, operate_3, operate_4, operate_5, operate_6]
for v in operates:
	func[v - 1]()

for a in arr:
	for v in a:
		print(v, end=" ")
	print()

# 회전 하면 가로 세로 길이가 바뀐다는점을 조심해야한다.
