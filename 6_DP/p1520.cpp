#include <iostream>

int n;
int m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int map[501][501];
int dp[501][501];

void input() {
    scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
			//이걸 0으로 초기화하는거랑 -1로 초기화하는거랑 뭐가 다른건지 잘 이해가 안됨
			//이걸 0으로 초기화하면 아예 길이 존재하지 않는경우와 아직 탐색하지 않은경우가 구분되지 않아서 중복으로 함수가 호출될수있다.
			//탐색하지 않은곳은 -1, 길이 존재하지 않는경우는 0으로 구분하여 -1인 경우에만 새로 탐색하도록 해야한다.
		}
}

int rec(int y, int x) {
	int newx;
	int newy;

	if (y == m - 1 && x == n - 1)
		return (1);
	if (dp[y][x] != -1)
		return (dp[y][x]);
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		newx = x + dx[i];
		newy = y + dy[i];
		if (0 <= newx && newx < n && 0 <= newy && newy < m && map[y][x] > map[newy][newx])
			dp[y][x] += rec(newy, newx);
	}
	return (dp[y][x]);
}

void solve() {
	printf("%d\n", rec(0, 0));
}

int main() {
    input();
	solve();
    return (0);
}
