# 2019.7.16
# 분할 정복(Divide and Conquer)
# 종이의 개수
#

num = int(input())
numset = []
check = [0,0,0,0]
for i in range(num):
    numset.append(list(map(int,input().split())))

def rori(startx,starty,len) :
    if len == 1:
        check[numset[startx][starty]+1] += 1
        return numset[startx][starty]+1

    check_local = [0,0,0,0]
    len = int(len/3)
    for i in range(9):
        check_local[rori(startx + int(i/3)*len, starty + i%3*len,len)] += 1
    for i in range(3):
        if check_local[i] == 9:
            check[i] -= 8
            return i
    return 3


rori(0,0,num)

for i in range(3):
    print(check[i])
