stairnum = int(input())
stair = []
for i in range(stairnum):
    stair.append(int(input()))

def step(pos, sum, check):
    if pos == stairnum - 1:
        return sum
    elif pos == stairnum - 2:
        return step(pos + 1, sum + stair[pos + 1], 1)
    elif pos == stairnum - 3:
        return step(pos + 2, sum + stair[pos + 2], 0)

    goto = pos + 1
    if check == 1:
         goto += 1
         check = 0
    elif stair[goto] <= stair[goto+1]:
        goto += 1
        check = 0
    else:
        check = 1

    sum += stair[goto]
    return step(goto, sum, check)

print(step(0,stair[0],0))
