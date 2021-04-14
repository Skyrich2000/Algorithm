A, B, C, X, Y = map(int, input().split())

print(min(A + B, 2 * C) * min(X, Y) \
	+ min([A, B][0 if X > Y else 1], 2 * C) * abs(X - Y))

# 두 치킨을 한번에 살수있는 경우 A + B or 2 * C
# 한 치킨을 사는 법 : 남은 치킨 가격 or 2 * C
# c 가 엄청 싼경우를 고려해야함!
