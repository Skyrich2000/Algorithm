#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int num[4001][4];
vector<int> absum;
vector<int> cdsum;

int rec_min(int left, int right, int findnum) {
	int mid;

	mid = (left + right) / 2;
	if (right <= left)
		return (cdsum[mid] == findnum ? mid : -1);
	return (findnum <= cdsum[mid] ? rec_min(left, mid, findnum) : rec_min(mid + 1, right, findnum));
}

int rec_max(int left, int right, int findnum) {
	int mid;

	mid = (left + right) / 2;
	if (right <= left)
		return (cdsum[mid] == findnum ? mid : -1);
	return (findnum < cdsum[mid] ? rec_max(left, mid, findnum) : rec_max(mid + 1, right, findnum));
}

long long solve() {
	int min;
	int max;
	long long cnt;

	cnt = 0;
	for (int i = 0; i < n * n; i++) {
		min = rec_min(0, n * n - 1, -absum[i]);
		max = rec_max(0, n * n - 1, -absum[i]);
		if (min != -1) {
			cnt++;
			if (max != -1) cnt += max - min;
		}
	}
	return (cnt);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d", &num[i][0], &num[i][1], &num[i][2], &num[i][3]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			absum.push_back(num[i][0] + num[j][1]);
			cdsum.push_back(num[i][2] + num[j][3]);
		}
	sort(cdsum.begin(), cdsum.end());
	printf("%lld\n", solve());
	return (0);
}
