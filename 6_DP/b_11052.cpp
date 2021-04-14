#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cards;
vector<int> dp;

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	pre();
	cin >> n;
	cards.resize(n + 1);
	dp.resize(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> cards[i];
}

int rec(int num) {
	int price;

	price = 0;
	if (num == 0)
		return (0);
	if (dp[num])
		return (dp[num]);
	for(int i = 1; i <= n; i++)
		if (num - i >= 0)
			price = max(rec(num - i) + cards[i], price);
	dp[num] = price;
	return (dp[num]);
}

void solve() {
	cout << rec(n) << endl;
}

int main() {
	input();
	solve();
	return (0);
}
