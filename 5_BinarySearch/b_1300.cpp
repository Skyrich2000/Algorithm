#include <iostream>

using namespace std;

int n;
int k;
int num[1001];

int rec(int left, int right) {
	int sum;
	int mid;

	mid = (left + right) / 2;
	if (right <= left + 1)
		return (mid);
	sum = check(num, mid);
	return (sum < m ? rec(left, mid) : rec(mid, right));
}

int solve() {
	return (rec(0, max + 1));
}

int main() {
    cin >> n >> k;
	cout << solve() << endl;
	return (0);
}
