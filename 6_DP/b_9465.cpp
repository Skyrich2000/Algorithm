#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > num;
vector<vector<int> > dp;

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> n;
	num = vector<vector<int> >(2, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		cin >> num[0][i];
	for (int i = 0; i < n; i++)
		cin >> num[1][i];
	dp = vector<vector<int> >(2, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		dp[0][i] = dp[1][i] = -1;
}

int rec(int row, int index) {
	if (index < 0)
		return (0);
	if (dp[row][index] != -1)
		return (dp[row][index]);
	dp[row][index] = num[row][index] + max(rec(!row, index - 1), rec(!row, index - 2));
	return (dp[row][index]);
}

void solve() {
	cout << max(rec(0, n - 1), rec(1, n - 1)) << endl;
}

int main() {
	int t;

	pre();
	cin >> t;
	while (t--)
	{
		input();
		solve();
	}
	return (0);
}
