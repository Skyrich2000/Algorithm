# 2019.7.10 
# 완전탐색 Brute-force Search
# 부분수열의 합
# 성공!

n, aim = map(int,input().split(' '))
num = list(map(int,input().split(' ')))
count = 0

def find(index,size,sum):
    global count, n, aim
    sum += num[index]
    if size == 1:
        if sum == aim:
            count += 1
        return
    size -= 1
    index += 1
    for i in range(n - index - size + 1) :
        find(index+i,size,sum)

s = 0
for size in range(n) : 
    for i in range(n - size) : 
        find(i,size+1,0)

print(count)