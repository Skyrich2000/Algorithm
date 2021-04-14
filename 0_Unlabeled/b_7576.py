num = int(input())
lista = list(map(int,input().split(' ')))
listb = list(map(int,input().split(' ')))

sum = 0
j = 0
for i in range(len(lista)):
    for k in range(j,len(listb)):
        if listb[k] == lista[i]:
            sum += k - i
            j = k
            break
    if j == num-1:
        break
print(sum)