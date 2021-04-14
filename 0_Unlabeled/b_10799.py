#영훈 제출

stick = input()
opens = 0
crack = 0
for i in range(len(stick)):
    if stick[i] == '(':
        opens += 1
    elif stick[i] == ')':
        opens -= 1
        crack += 1
        if stick[i-1] == '(':
            crack += opens 
            crack -= 1
print(crack)