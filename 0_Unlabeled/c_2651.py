N, K = map(int, input().split())

def f(n):
    if n < 2:
        return 1
    return n * f(n-1)

print(int(f(N)/(f(K) * f(N-K))))