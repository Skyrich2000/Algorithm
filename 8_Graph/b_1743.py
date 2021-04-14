import sys
sys.setrecursionlimit(500000) #파이썬 내부적으로 재귀 함수 사용에 제한이 있어 런타임 오류가 발생하는것을 해결

N, M, K = map(int, sys.stdin.readline().split())
room = [[-1 for _ in range(M)] for _ in range(N)]
for _ in range(K):
    x, y = map(int, sys.stdin.readline().split())
    room[x - 1][y - 1] = 1

def foo(x, y):
    if x < 0 or x >= N or y < 0 or y >= M:
        return 0
    if room[x][y] == -1:
        return 0

    room[x][y] = -1
    result = 1
    result += foo(x + 1, y)
    result += foo(x, y + 1)
    result += foo(x - 1, y)
    result += foo(x, y - 1)
    return result

result = 0
for i in range(N):
    for j in range(M):
        result = max(result, foo(i, j))

print(result)