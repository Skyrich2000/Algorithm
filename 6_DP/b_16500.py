import sys
sys.setrecursionlimit(100000) #파이썬 내부적으로 재귀 함수 사용에 제한이 있어 런타임 오류가 발생하는것을 해결

# sentence = input()
# n = int(input())
# words = [input() for _ in range(n)]

# result = 0
# def foo(cut):
#     global result
#     if result:
#         return

#     if not len(cut):
#         result = 1
#         return

#     for w in words:
#         if cut[:len(w)] == w:
#             foo(cut[len(w):])

# foo(sentence)
# print(result)

# substr 일경우
# 여러개일경우

# mem = [0 for _ in range(len(sentence) + 1)]

# def foo(pos):
#     if pos == len(sentence):
#         return 1

#     if pos > len(sentence):
#         return 0

#     if mem[pos] != 0:
#         return mem[pos]
    
#     ch = 0
#     for w in words:
#         if sentence[pos:pos+len(w)] == w:
#             ch += foo(pos + len(w))
#     if ch:
#         mem[pos] = 1
    
#     return mem[pos]

# print(foo(0))

mem = [0 for _ in range(len(sentence) + 1)]
mem[0] = 1

for i in range(len(sentence)):
    for w in words:
        if mem[i] and sentence[i:i+len(w)] == w:
            mem[i+len(w)] = 1

print(mem[-1])
