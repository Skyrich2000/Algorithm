#include <iostream>

int t;

void input() {
    scanf("%d", &t);
}

void solve() {
	int num;
	int ans;

	scanf("%d", &num);

	ans = num;
	while (num != 1) {
		if (num % 2)
			num = num * 3 + 1;
		else
			num = num / 2;
		ans = max(ans, num);
	}
	printf("%d\n", ans);
}

int main() {
    input();
	while (t--)
    	solve();
    return (0);
}
