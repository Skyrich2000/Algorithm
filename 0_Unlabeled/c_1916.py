aimnum = int(input())

def re(first, second, curnum):
    curnum += 1
    if curnum == aimnum:
        return second
    return re(second, first + second, curnum)

print(re(0,1,0)%10009)
