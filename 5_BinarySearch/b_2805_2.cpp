#include <iostream>

using namespace std;

int n;
long long m;
int wood[1000001];
int wood_max;

int rec(long long left, long long right) {
	long long sum;
	long long mid;

	mid = (left + right) / 2;
	if (right <= left + 1)
		return (mid);
	sum = 0;
	for (int i = 0; i < n; i++)
		if (wood[i] - mid > 0) sum += wood[i] - mid;
	return (sum < m ? rec(left, mid) : rec(mid, right));
}

int solve() {
	return (rec(0, wood_max + 1));
}

int main() {
    wood_max = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> wood[i];
		if (wood_max < wood[i]) wood_max = wood[i];
	}
	cout << solve() << endl;
	return (0);
}
