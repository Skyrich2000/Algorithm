#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> dp;

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	pre();
	cin >> n;
	arr.resize(n);
	dp.resize(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
}

int rec(int index) {
	if (index == n)
		return (0);
	for(int i = 0; i < index; i++)
		if (arr[i] < arr[index])
			dp[index] = max(dp[index], dp[i]);
	dp[index]++;
	return (max(rec(index + 1), dp[index]));
}

void solve() {
	cout << rec(0) << endl;
}

int main() {
	input();
	solve();
	return (0);
}
