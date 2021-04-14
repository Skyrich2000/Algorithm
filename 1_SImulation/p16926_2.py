N, M, r = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
result = [[0 for _ in range(M)] for _ in range(N)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

rdx = [0, 1, 0, -1]
rdy = [1, 0, -1, 0]

def get_index(i, n, m):
	return ((i % (n + m - 2)) > (m - 2)) + 2 * int(i / (n + m - 2))

def get_index_r(i, n, m):
	return ((i % (n + m - 2)) > (n - 2)) + 2 * int(i / (n + m - 2))

def rotate(y, x, n, m):
	if (n < 2 or m < 2):
		return
	size = (n + m - 2) * 2
	_x, _y = x, y
	for i in range(size):
		_rx, _ry = _x, _y
		for _r in range(r % size):
			j = (size - (i - _r)) % size
			_ry += rdy[get_index_r(j, n, m)]
			_rx += rdx[get_index_r(j, n, m)]
		result[_ry][_rx] = arr[_y][_x]
		_y += dy[get_index(i, n, m)]
		_x += dx[get_index(i, n, m)]
	rotate(y + 1, x + 1, n - 2, m - 2)


rotate(0, 0, N, M)

for i in result:
	for j in i:
		print(j, end=" ")
	print()

