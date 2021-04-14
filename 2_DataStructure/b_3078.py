import sys
from collections import deque

N, K = map(int, sys.stdin.readline().split())
names = [deque() for _ in range(21)]
count = 0

for i in range(N):
    lenn = len(sys.stdin.readline()) - 1
    while(len(names[lenn]) and names[lenn][0] < i - K):
        names[lenn].popleft()
        
    count += len(names[lenn])
    names[lenn].append(i)

print(count)
