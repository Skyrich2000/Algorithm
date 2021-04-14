#include <iostream>

int n;
int k;
long long dp[201][201];

void input() {
	scanf("%d %d", &n, &k);
}

int rec(int num, int cnt) {
	if (num == 0)
		return (1);
	if (cnt == 1)
		return (1);
	if (cnt == 2)
		return (num + 1);
	if (dp[num][cnt])
		return(dp[num][cnt]);
	dp[num][cnt] = 0;
	for (int i = 0; i <= num; i++)
		dp[num][cnt] += rec(num - i, cnt - 1);
	dp[num][cnt] %= 1000000000;
	return(dp[num][cnt]);
}

void solve() {
	printf("%d\n", rec(n, k));
}

int main() {
	input();
	solve();
	return (0);
}
