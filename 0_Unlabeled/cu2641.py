stairnum = int(input())

def count(now, st):
    if now == stairnum:
        return 1
    elif now > stairnum:
        return 0

    num = 0

    if st == 0: 
        num += count(now + 3, st + 2)
    else: st -= 1
    num += count(now + 1, st)
    num += count(now + 2, st)

    return num

print(count(0,0))
