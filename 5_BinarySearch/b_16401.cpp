#include <iostream>

using namespace std;

int n;
int m;
int snack[1000000];

bool check(int len) {
	int cnt;

	cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt += snack[i] / len;
		if (cnt >= n)
			return true;
	}
	return false;
}

int rec(int left, int right) {
	int mid;

	mid = (left + right) / 2;
	if (right <= left + 1)
		return (mid);
	return (!check(mid) ? rec(left, mid) : rec(mid, right));
}

int solve(int max) {
	return (rec(0, max + 1));
}

int main() {
    int num_max;

    num_max = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> snack[i];
		num_max = max(snack[i], num_max);
	}
	cout << solve(num_max) << endl;
	return (0);
}
