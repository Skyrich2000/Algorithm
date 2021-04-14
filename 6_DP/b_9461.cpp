#include <iostream>
#include <vector>

using namespace std;


int t;
vector<long long> dp;

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	pre();
	cin >> t;
	dp.resize(101);
}

void solve() {
	int n;

	for (int i = 1; i <= 5; i++)
		dp[i] = "011122"[i] - '0';
	for (int i = 5; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];
	while (t--) {
		cin >> n;
		cout << dp[n] << endl;
	}
}

int main() {
	input();
	solve();
	return (0);
}
