import sys

N, K, D = map(int, sys.stdin.readline().split())
rules = [list(map(int, sys.stdin.readline().split())) for _ in range(K)]

def count(box):
    num = 0
    for r in rules:
        if r[0] > box:
            continue
        num += (min(r[1],box) - r[0]) // r[2] + 1
    return num

def foo(left, right):
    mid = (left + right) // 2
    if left > right:
        return mid

    if count(mid) <= D - 1:
        return foo(mid + 1, right)
    return foo(left, mid - 1)

print(foo(0, N) + 1)
