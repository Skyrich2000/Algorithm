#include <iostream>

using namespace std;

int n;
int m;
int num[100001];
int num_sum = 0;
int num_max = 0;

int check(int mid) {
	int sum;
	int used;

	sum = 0;
	used = 1;
	for (int i = 0; i < n; i++) {
		sum += num[i];
		if (sum > mid) {
			used++;
			sum = num[i];
		}
		if (used > m)
			break;
	}
	return (used <= m);
}

int rec(int left, int right) {
	int mid;

	mid = (left + right) / 2;
	if (right <= left)
		return (mid);
	return (check(mid) ? rec(left, mid) : rec(mid + 1, right));
}

int solve() {
	return (rec(num_max, num_sum));
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
        num_sum += num[i];
        num_max = max(num_max, num[i]);
	}
	printf("%d\n", solve());
	return (0);
}
