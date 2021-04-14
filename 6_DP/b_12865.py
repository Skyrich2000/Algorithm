n, maxw = map(int, input().split())
items = [list(map(int, input().split())) for _ in range(n)]
items.sort(key=lambda x:x[1], reverse=True)

mem = [-1 for _ in range(maxw + 1)]
def foo(w, item_index):
    if w > maxw:
        return -items[item_index][1]
    
    if w == maxw:
        return 0

    if mem[w] != -1:
        return i

    maxx = 0
    for i in range(n, item_index, -1):
        out = foo(w + items[i][0], i) + items[i][1]
        maxx = max(out, maxx)
    mem[w] = maxx
    return maxx

print(foo(0, -1))
