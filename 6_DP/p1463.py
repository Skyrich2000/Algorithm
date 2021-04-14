import sys
sys.setrecursionlimit(500000) #파이썬 내부적으로 재귀 함수 사용에 제한이 있어 런타임 오류가 발생하는것을 해결

num = int(input())

mem = [-1 for _ in range(num + 1)]

def foo(x):
    if x == 1:
        return 0

    if mem[x] != -1:
        return mem[x]

    # 횟수 셀때 따로 변수를 두지 않고 return값에 +1 로 계산하는거 좀 희안한듯
    minn = foo(x-1) + 1
    if x%3 == 0:
        minn = min(foo(x // 3) + 1, minn)
    if x%2 == 0:
        minn = min(foo(x // 2) + 1, minn)
    mem[x] = minn
    return minn

print(foo(num))

# mem = [num+1 for _ in range(num + 1)]
# mem[1] = 0
# for i in range(1, num):
#     mem[i+1] = min(mem[i] + 1, mem[i+1])
#     if i*3 < num+1:
#         mem[i*3] = min(mem[i] + 1, mem[i*3])
#     if i*2 < num+1:
#         mem[i*2] = min(mem[i] + 1, mem[i*2])

# print(mem[num])
