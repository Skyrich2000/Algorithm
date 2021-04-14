#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
vector<vector<int>> candy;
vector<vector<int>> dp;

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	pre();
	cin >> n >> m;
	candy = vector<vector<int>>(n, vector<int>(m, 0));
	dp = vector<vector<int>>(n, vector<int>(m, -1));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> candy[i][j];
}

int is_inboundary(int y, int x) {
	return ((0 <= y && y < n) && (0 <= x && x < m));
}

int rec(int y, int x) {
	int price;

	price = 0;
	if (!is_inboundary(y, x))
		return (0);
	if (dp[y][x] != -1)
		return (dp[y][x]);
	dp[y][x] = max(dp[y][x], rec(y - 1, x));
	dp[y][x] = max(dp[y][x], rec(y, x - 1));
	dp[y][x] = max(dp[y][x], rec(y - 1, x - 1));
    dp[y][x] += candy[y][x];
	return (dp[y][x]);
}

void solve() {
	cout << rec(n - 1, m - 1) << endl;
}

int main() {
	input();
	solve();
	return (0);
}

