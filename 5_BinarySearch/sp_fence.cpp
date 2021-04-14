#include <iostream>

using namespace std;

int n;
int fence[20001];

int find_mid(int left_limit, int right_limit) {
	int sum;
	int height;
	int left, mid, right;

	sum = 0;
	mid = (left_limit + right_limit) / 2;
	left = mid;
	right = mid;
	height = fence[mid];
	//printf("find start :: left : %d, right : %d\n", left_limit, right_limit);
	while (left_limit < left || right < right_limit) {
		//printf("find :: left : %d, right : %d\n", left, right);
		if (left_limit < left && fence[left - 1] > fence[right + 1]) {
			left--;
			height = min(height, fence[left]);
		} else {
			right++;
			height = min(height, fence[right]);
		}
		sum = max(sum, (right - left + 1) * height);
	}
	//printf("find end :: sum : %d, height : %d\n", sum, height);
	return (sum);
}

int rec(int left, int right) {
	int ret;
	int mid;
	//printf("left : %d, right : %d\n", left, right);
	mid = (left + right) / 2;

	if (left + 1 >= right)
		return (0);
	ret = max(rec(left, mid), rec(mid, right));
	return (max(ret , find_mid(left, right - 1)));
}

void solve() {
	int ret;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> fence[i];
    cout << rec(0, n + 1) << endl;
}

int main() {
    int C;

    cin >> C;
    for (int i = 0; i < C; i++)
        solve();
    return (0);
}
