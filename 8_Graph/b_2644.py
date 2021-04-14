import sys
from collections import deque

N = int(sys.stdin.readline())
x, y = map(int, sys.stdin.readline().split())
adj = [list() for _ in range(N)]
visited = [False for _ in range(N)]
depth = [0 for _ in range(N)]

for _ in range(int(sys.stdin.readline())):
    p, c = map(int, sys.stdin.readline().split())
    adj[p - 1].append(c - 1)
    adj[c - 1].append(p - 1)

q = deque()
visited[x - 1] = True
q.append(x - 1)
while(len(q)):
    cur = q.popleft()
    if cur == y - 1:
        break
    for node in adj[cur]:
        if not visited[node]:
            visited[node] = True
            q.append(node)
            depth[node] = depth[cur] + 1

if depth[y - 1]:
    print(depth[y - 1])
else:
    print(-1)

