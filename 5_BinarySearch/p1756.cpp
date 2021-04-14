#include <iostream>

using namespace std;

int n;
int m;
int oven[300001];
int pizza[300001];

bool check(int depth) {
	for(int i = 0; i < m; i++)
		if (oven[depth + i] < pizza[m - 1 - i]) return true;
	return false;
}

int rec(int left, int right) {
	int sum;
	int mid;

	mid = left + (right - left) / 2;
	if (right <= left + 1)
		return (mid);
	return (check(mid) ? rec(left, mid) : rec(mid, right));
}

int solve() {
	return (rec(-1, n + 1) + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> oven[i];
		if (i == 0) continue;
		oven[i] = min(oven[i], oven[i - 1]);
	}
	for (int i = 0; i < m; i++) {
        cin >> pizza[i];
		if (i == 0) continue;
		pizza[i] = max(pizza[i], pizza[i - 1]);
	}
	cout << solve() << endl;
	return (0);
}
