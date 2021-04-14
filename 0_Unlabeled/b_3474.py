CASE_nUM = int(input())
LIst = []
for i in range(CASE_nUM):
    a = int(input())
    s = 0
    j = 1
    b = 1
    while(b != 0):
        b = int(a/pow(5,j))
        s += b
        j += 1
    LIst.append(s)

for num in LIst:
    print(num)