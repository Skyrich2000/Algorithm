#include <iostream>

int n;
long long dp[1001] = {0, };

void input() {
    scanf("%d", &n);
}

long long rec(int num) {
	if (num == 1)
		return (1);
	if (num == 2)
		return (3);
	if (dp[num] != 0)
		return (dp[num]);
	dp[num] = (rec(num - 1) + rec(num - 2) * 2) % 10007;
	return (dp[num]);
}

void solve() {
	printf("%d", rec(n));
}

int main() {
    input();
	solve();
    return (0);
}
