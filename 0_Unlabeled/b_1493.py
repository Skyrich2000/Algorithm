# 2019.7.15
# 탐욕적 기법(Greedy Algorithm)
# 박스채우기
# 

num = int(input())
days = [0 for i in range(1000)]

for i in range(num):
    start_pos, point = map(int,input().split())
    current_pos = start_pos - 1
    while(current_pos >= 0) :
        if days[current_pos] < point:
            days[current_pos] = point
            break
        current_pos -= 1

sum = 0
for n in days:
    sum += n
print(sum)
