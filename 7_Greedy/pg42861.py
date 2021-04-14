def solution(n, costs):
	def get_top(i):
		if tree[i] == i:
			return i
		return get_top(tree[i])
	answer = 0
	tree = [i for i in range(n)]
	bridge = sorted(costs, key=lambda x: x[2])
	i = 0
	for v in bridge:
		if i > n:
			break
		n1 = v[0]
		n2 = v[1]
		if n1 > n2:
			n1, n2 = n2, n1
		n1_top = get_top(n1)
		n2_top = get_top(n2)
		if n2_top != n1_top:
			tree[n2] = n1
			tree[n2_top] = n1
			answer += v[2]
			i += 1
	return answer
