n, m = map(int, input().split())
board = [[1 if e == "W" else -1 for e in input()] for _ in range(n)]
label = ["WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", 
        "WBWBWBWB","BWBWBWBW", "WBWBWBWB", "BWBWBWBW"]
label = [[1 if e == "W" else -1 for e in row] for row in label]

def check(y, x):
    summ = 0
    for i in range(8):
        for j in range(8):
            summ += board[y+i][x+j] * label[i][j] * board[y][x]
    out = int((64 - summ) / 2)
    return min(out, 64-out)

result = 99
for y in range(n - 7):
    for x in range(m - 7):
        out = check(y, x)
        if result > out:
            result = out

print(result)
