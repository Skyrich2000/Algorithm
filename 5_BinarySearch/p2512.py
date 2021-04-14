import sys

N = int(sys.stdin.readline())
demands = list(map(int, sys.stdin.readline().split()))
budget = int(sys.stdin.readline())

def foo(left, right):
    mid = (left + right) // 2
    if left > right:
        return mid

    result = 0
    for d in demands:
        result += min(d, mid)
    
    if result <= budget:
        return foo(mid + 1, right)
    return foo(left, mid - 1)

print(foo(0, max(demands)))
