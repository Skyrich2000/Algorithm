import sys
sys.setrecursionlimit(100000)  # 파이썬 내부적으로 재귀 함수 사용에 제한이 있어 런타임 오류가 발생하는것을 해결

N = int(input())

mem = [[0 for _ in range(10)] for _ in range(N + 1)]

def foo(n, x):
    if n == 0:
        return 0

    if mem[n][x] != 0:
        return mem[n][x]

    summ = 0
    for i in range(x, 10):
        summ += foo(n - 1, i) + 1
    mem[n][x] = summ
    return summ

print((foo(N, 1) + 1) % 10007)