#include <iostream>

using namespace std;

string mem;
string fan;

int rec(int left, int right) {
	int sum;
	int mid;

	mid = (left + right) / 2;
	if (right <= left + 1)
		return (mid);
	sum = check(num, mid);
	return (sum < m ? rec(left, mid) : rec(mid, right));
}


void solve() {
	cin >> mem >> fan;
    cout << rec(0, fan.length() - mem.length() + 2) << endl;
}

int main() {
    int c;

    cin >> c;
    for (int i = 0; i < c; i++)
		solve();
	return (0);
}
