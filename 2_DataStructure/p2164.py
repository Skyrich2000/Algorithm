import sys
from collections import deque

N = int(sys.stdin.readline())

dq = deque()
for i in range(N):
    dq.append(i+1)

flag = True
while(len(dq) > 1):
    if flag:
        dq.popleft()
    else:
        dq.append(dq.popleft())
    flag = not flag

print(dq.popleft())