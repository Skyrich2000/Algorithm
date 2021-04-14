import sys

N, C = map(int, sys.stdin.readline().split())
house = sorted([int(sys.stdin.readline()) for _ in range(N)])
maxd = house[-1] - house[0]

def check(d):
    index = 0
    pos = house[0]
    for _ in range(C - 1):
        if pos + d > house[-1]:
            return False
        for _ in range(index, len(house)):
            index+=1
            if pos + d <= house[index]:
                pos = house[index]
                break
    return True

def foo(left, right):
    mid = (left + right) // 2
    if left > right:
        return mid

    if check(mid):
        return foo(mid + 1, right)
    return foo(left, mid - 1)

print(foo(1, maxd))
