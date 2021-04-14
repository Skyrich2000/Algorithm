woodnum, woodamount = map(int,input('').split(' '))
woodh = list(map(int,input('').split(' ')))

woodhsum = 0
avg = int((sum(woodh))/woodnum)

while(1):
    for h in woodh:
        woodhsum += max(h - avg,0)

    if -woodnum <= woodamount - woodhsum <= 0:
        print(avg)
        break
    elif woodamount - woodhsum > 0:
        avg -= 1
    else :
        avg += 1
