#include <iostream>

using namespace std;

int n;
int m;
int c;
int num[300][300];

void	pre(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void	input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> num[i][j];
	cin >> c;
}

void	solve() {
	int sum;
	int i, j, x, y;

	while(c--) {
		sum = 0;
		cin >> i >> j >> x >> y;
		for (int _i = i; _i <= x; _i++)
			for (int _j = j; _j <= y; _j++)
				sum += num[_i - 1][_j - 1];
		cout << sum << endl;
	}
}

int		main() {
	pre();
	input();
	solve();
	return (0);
}
