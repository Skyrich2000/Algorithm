n, s = map(int, input().split())
lst = list(map(int, input().split()))

count = 0
def check(pick, newflag):
    newpick = [e for e in pick]
    newpick[newflag] = 1

    global count
    summ = 0
    for i in range(n):
        summ += lst[i] * newpick[i]
    if summ == s:
        count += 1

    for i in range(newflag + 1, n): #새로운 원소 오른쪽에 있는것부터 원소 추가
        check(newpick, i)

_pick = [0 for _ in range(n)]
for i in range(n):
    check(_pick, i)

print(count)
