#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n;
int m;
int num[5001];
int num_max;

int gapMaxMin(vector<int>& k) {
	auto p = minmax_element(k.begin(), k.end());
	return * p.second - * p.first;
}

bool is_possible(int score) {
	vector<int> tmp;
	int count;

	count = 1;
	for (int i = 0; i < n; i++) {
		tmp.push_back(num[i]);
		int gap = gapMaxMin(tmp);
		if (gap > score) {
			count++;
			tmp.clear();
			tmp.push_back(num[i]);
		}
	}
	return (count <= m);
}

int rec(int left, int right) {
	int sum;
	int mid;

	mid = (left + right) / 2;
	if (right <= left)
		return (mid);
	if (is_possible(mid)) {
		return (rec(left, mid));
	}
	return (rec(mid + 1, right));
}

int solve() {
	return (rec(0, num_max + 1));
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
		num_max = max(num[i], num_max);
	}
	cout << solve() << endl;
	return (0);
}
