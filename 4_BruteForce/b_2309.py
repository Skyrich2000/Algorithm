height = [int(input()) for _ in range(9)]
height.sort()

flag = 0
for b1 in range(9):
    for b2 in range(b1+1, 9):
        newheight = []
        for e in height:
            newheight.append(e)
        newheight[b1] = 0
        newheight[b2] = 0
        if sum(newheight) == 100:
            flag = 1
            break
    if flag == 1:
        break

for e in newheight:
    if e != 0:
        print(e)    