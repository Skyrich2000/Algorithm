import sys

N = int(sys.stdin.readline())
time = list(map(int, sys.stdin.readline().split()))
time.sort()

total = 0
wait = 0
for t in time:
    wait += t
    total +=  wait
print(total)