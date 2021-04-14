import math

min = math.ceil(math.sqrt(int(input())))
max = math.floor(math.sqrt(int(input())))

sum = 0
for i in range(min,max+1):
    sum += i*i

print(sum)
print(min*min)
