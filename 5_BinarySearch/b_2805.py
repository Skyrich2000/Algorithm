import sys

N, M = map(int, sys.stdin.readline().split())
woods = list(map(int, sys.stdin.readline().split()))

def foo(left, right):
    mid = (left + right) // 2
    if left > right:
        return mid

    result = 0
    for w in woods:
        result += max(w - mid, 0)

    if result >= M:
        return foo(mid + 1, right)
    return foo(left, mid - 1)

print(foo(0, max(woods)))
