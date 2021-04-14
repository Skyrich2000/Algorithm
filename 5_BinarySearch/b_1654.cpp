#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
vector<long long> price;

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	pre();
	cin >> n;
	price.resize(n);
	for(int i = 0; i < n; i++)
		cin >> price[i];
	cin >> m;
}

long long check(long long limit) {
    //주어진 상한으로 배정 가능 -> 더 큰 상한으로 도전 (오른쪽)
	//주어진 상한으로 배정 불가능 -> 더 작은 상한으로 도전 (왼쪽)
	long long budget;

	budget = 0;
	for(int i = 0; i < n; i++)
		budget += min(price[i], limit);
	return (m < budget);
}

long long rec(long long left, long long right) {
	long long mid;

	mid = (left + right) / 2;
	if (right <= left + 1)
		return (mid);
	return (check(mid) ? rec(left, mid) : rec(mid, right));
}

void solve() {
	long long max_price;

	max_price = 0;
	for(int i = 0; i < n; i++)
		max_price = max(max_price, price[i]);
	cout << rec(0, max_price + 1) << endl;
}

int main() {
	input();
	solve();
	return (0);
}
