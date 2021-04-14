import sys

N = int(sys.stdin.readline())
user = [(i, sys.stdin.readline().split()) for i in range(N)]
user.sort(key = lambda x : (x[1][0], x[0]))

for u in user:
    print(u[1][0], u[1][1])