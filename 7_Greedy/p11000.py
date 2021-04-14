import sys
import heapq as h

N = int(sys.stdin.readline())
classes = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
classes.sort(key = lambda x: x[0])

rooms = []
h.heappush(rooms, classes[0][1])
for ci in classes[1:]:
    if rooms[0] <= ci[0]:
        h.heappop(rooms)
    h.heappush(rooms, ci[1])
    
print(len(rooms))
