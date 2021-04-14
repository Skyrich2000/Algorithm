result = []
while(True):
    nlist =list(map(int,input().split(' ')))
    if nlist[0] == -1:
        break
    nlist.remove(0)
    num = 0
    for item in nlist:
        if item*2 in nlist:
            num += 1
    result.append(num)

for n in result:
    print(n)