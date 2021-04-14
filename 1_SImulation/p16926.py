N, M, r = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def get_index(i, n, m):
	return ((i % (n + m - 2)) > (m - 2)) + 2 * int(i / (n + m - 2))

def rotate(y, x, n, m):
	if (n < 2 or m < 2):
		return
	tmp = []
	size = (n + m - 2) * 2
	_x, _y = x, y
	for i in range(size):
		tmp.append(arr[_y][_x])
		_y += dy[get_index(i, n, m)]
		_x += dx[get_index(i, n, m)]
	_x, _y = x, y
	for i in range(size):
		arr[_y][_x] = tmp[(i + r) % size]
		_y += dy[get_index(i, n, m)]
		_x += dx[get_index(i, n, m)]
	rotate(y + 1, x + 1, n - 2, m - 2)

rotate(0, 0, N, M)

for i in arr:
	for j in i:
		print(j, end=" ")
	print()
