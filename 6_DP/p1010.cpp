#include <iostream>
#include <vector>

using namespace std;

int west;
int east;
int dp[31][31];

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> west >> east;
}

int rec(int n, int r) {
	if (dp[n][r])
		return (dp[n][r]);
    if (n == r || r == 0)
		return (1);
	dp[n][r] = rec(n - 1, r) + rec(n - 1, r - 1);
	return (dp[n][r]);
}

void solve() {
    cout << rec(east, west) << endl;
}

int main() {
	int t;

	pre();
	cin >> t;
	while(t--) {
		input();
		solve();
	}
	return (0);
}
