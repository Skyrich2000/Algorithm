#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
vector<pair<int, int>> down;
vector<pair<int, int>> up;

void pre() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void input() {
	int _t1, _t2;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> _t1 >> _t2;
		up.push_back({_t1, _t2});
	}
	for (int i = 0; i < m; i++) {
		cin >> _t1 >> _t2;
		down.push_back({_t1, _t2});
	}
}

void solve() {

}

int main() {
    pre();
    input();
    solve();
    return (0);
}
