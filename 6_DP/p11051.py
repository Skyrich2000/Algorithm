import sys
sys.setrecursionlimit(100000)  # 파이썬 내부적으로 재귀 함수 사용에 제한이 있어 런타임 오류가 발생하는것을 해결

N, K = map(int, input().split())

mem = [[-1 for _ in range(i + 1)] for i in range(N + 1)]
def c(n, r):
    if n == 1 or r == 0 or n == r:
        return 1

    if mem[n][r] == -1:
        mem[n][r] = c(n - 1, r - 1) + c(n - 1, r)
    return mem[n][r]

print(c(N, K) % 10007)