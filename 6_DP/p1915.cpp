#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
vector<vector<int>> map;

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	char temp;

	pre();
	cin >> n >> m;
	map.resize(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}
}

void solve() {
	int ans;

	ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]) {
				map[i][j] = min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1])) + 1;
				ans = max(ans, map[i][j]);
			}
		}
	}
	cout << ans * ans << endl;
}

int	main(void) {
	input();
	solve();
	return (0);
}
