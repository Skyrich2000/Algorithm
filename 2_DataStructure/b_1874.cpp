#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int n;
queue<int> nums;
stack<int> tmp;
vector<char> result;

void pre() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void input() {
	int _t;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> _t;
		nums.push(_t);
	}
}

void print_q(queue<int> q) {
    while (q.size()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void print_s(stack<int> q) {
    while (q.size()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

void solve() {
	int i;

	i = 1;
	while (nums.size()) {
		for (; i <= nums.front(); i++) {
			tmp.push(i);
			result.push_back('+');
		}
		if (tmp.top() == nums.front()) {
			nums.pop();
			tmp.pop();
			result.push_back('-');
		} else
			break;
	}


	if (nums.size() > 1) {
		cout << "NO";
	} else {
		for(auto& i : result)
			cout << i << "\n";
	}
}

int main() {
    pre();
    input();
    solve();
    return (0);
}
