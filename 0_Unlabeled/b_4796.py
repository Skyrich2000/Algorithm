# 2019.7.15
# 탐욕적 기법(Greedy Algorithm)
# 캠핑
# 분명맞는거같은데 좆같이 틀림 왜 그런지 모르겠따

case = []
while(True):
    use_day, con_day, holiday = map(int,input().split(' ')) 
    if use_day == 0 and con_day == 0 and holiday == 0:
        break
    num = int(holiday/con_day)*use_day + holiday%con_day
    case.append(num)

for i in range(len(case)):
    print('Case '+str(i+1)+': '+str(case[i]))