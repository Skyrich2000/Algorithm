	# max_len = len(str(max(numbers)))
	# n_str = []
	# for n in numbers:
	# 	s = [int(c) for c in str(n)]
	# 	for _ in range(len(s), max_len):
	# 		s.append(s[-1])
	# 	n_str.append([str(n), s])
	# for l in reversed(range(max_len)):
	# 	n_str.sort(reverse=True, key=lambda x : x[1][l])

def comp(x, y):
	return x + y > y + x

def solution(numbers):
	answer = ''
	for s in sorted([str(n) for n in numbers], key=lambda x : x*3, reverse=True):
		answer += str(s)
	return answer

# https://programmers.co.kr/learn/courses/30/lessons/42746?language=python
