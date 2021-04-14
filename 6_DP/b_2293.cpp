#include <iostream>
#include <vector>

using namespace std;

int n;
int k;
vector<int> coins;
vector<int> dp;

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> n >> k;
	coins.resize(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	dp.resize(k + 1);
	for (int i = 0; i <= k; i++)
		dp[i] = 0;
}

void solve() {
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j <= k; j++)
			dp[j] = dp[j] + dp[j - coins[i]];
	cout << dp[k] << endl;
}

int main() {
	pre();
	input();
	solve();
	return (0);
}
