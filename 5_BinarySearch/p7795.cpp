#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
vector<int> A;
vector<int> B;

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> n >> m;
	A.resize(n);
	B.resize(m);
	for(int i = 0; i < n; i++)
		cin >> A[i];
	for(int i = 0; i < m; i++)
		cin >> B[i];
}

int rec(int left, int right, int num) {
	int mid;

	mid = (left + right) / 2;
	if (right <= left)
		return (mid);
	return (num <= B[mid] ? rec(left, mid, num) : rec(mid + 1, right, num));
}

void solve() {
	int cnt;

	cnt = 0;
	sort(B.begin(), B.end());
	for(int i = 0; i < n; i++)
		cnt += rec(0, m, A[i]);
	cout << cnt << endl;
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
