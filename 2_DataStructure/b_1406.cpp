#include <iostream>
#include <list>
#include <string>

using namespace std;

int n;
list<char> str;

void pre() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void input() {
	string s;

	cin >> s >> n;
	for (int i = 0; i < s.size(); i++)
		str.push_back(s[i]);
}

void solve() {
	char op;
	char chr;

	auto cursor = str.end();
	while(n--) {
		cin >> op;
		if (op == 'L') {
			if (cursor != str.begin())
				cursor--;
		}
		else if (op == 'D') {
			if (cursor != str.end())
				cursor++;
		}
		else if (op == 'B') {
			if (cursor != str.begin())
				cursor = str.erase(--cursor);
		}
		else if (op == 'P') {
			cin >> chr;
			str.insert(cursor, chr);
		}
	}
	for(auto i : str)
		cout << i;
}

int main() {
    pre();
    input();
    solve();
    return (0);
}


/*
	반복자는 해당 원소를 계속 가지고있음
	auto cursor = str.begin();
	cout << *cursor << endl; // a
	str.insert(cursor, '0');
	cout << *(--cursor) << endl; // 0

	insert 해도 커서의 값이 바뀌지 않음

	auto cursor = str.begin();
	cout << *cursor << endl; // a
	auto new_cursor = str.erase(cursor);
	cout << *cursor << endl; // a
	cout << *(++cursor) << endl; // 출력 x
	cout << *str.begin() << endl; // b
	cout << *new_cursor << endl; // b

	마찬가지로 erase 해도 커서의 값이 바뀌지 않음
	insert 와 다르게 erase 한 원소의 다음 값을 참조하려고하면 아무것도 없다.
	그래서 삭제되면 해당 커서가 무의미 해지기때문에 리턴으로 새로운 원소를 받아야한다.
*/
