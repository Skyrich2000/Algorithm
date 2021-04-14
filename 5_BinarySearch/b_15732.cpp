#include <iostream>

using namespace std;

int n;
int k;
long long d;
int rule[10001][3];

int rec(int left, int right) {
	long long sum;
	int mid;

	mid = (left + right) / 2;
	if (right <= left + 1)
		return (mid);
	sum = 0;
	for (int i = 0; i < k; i++)
		if (mid >= rule[i][0]) sum += (min(mid, rule[i][1]) - rule[i][0]) / rule[i][2] + 1;
	return (d <= sum ? rec(left, mid) : rec(mid, right));
}

int solve() {
	return (rec(0, n + 1) + 1);
}

int main() {
    cin >> n >> k >> d;
    for (int i = 0; i < k; i++)
        cin >> rule[i][0] >> rule[i][1] >> rule[i][2];
	cout << solve() << endl;
	return (0);
}
