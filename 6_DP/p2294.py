import sys
sys.setrecursionlimit(100000) #파이썬 내부적으로 재귀 함수 사용에 제한이 있어 런타임 오류가 발생하는것을 해결

n, aim = map(int, input().split())
coin = [int(input()) for _ in range(n)]

mem = [-1] * (aim + 1)
def foo(cur):
    if cur < 0:
        return aim + 1
    
    if cur == 0:
        return 0

    if mem[cur] != -1:
        return mem[cur]

    result = aim + 1
    for c in coin:
        result = min(foo(cur - c) + 1, result)

    mem[cur] = result
    return result

out = foo(aim)
if out >= aim + 1:
    print(-1)
else :
    print(out)