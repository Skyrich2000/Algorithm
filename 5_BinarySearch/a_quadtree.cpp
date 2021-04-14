#include <iostream>

using namespace std;

char input[1001];
char temp[1001];

int rec(int start) {
	int pos;
	int top_left, top_right;
	int down_left, down_right;
	int end;

	if (input[start] == 'w' || input[start] == 'b')
		return (start);
	top_left = start + 1;
	top_right = rec(top_left) + 1;
	down_left = rec(top_right) + 1;
	down_right = rec(down_left) + 1;
	end = rec(down_right);
	//printf("start : %d\n%d %d\n%d %d\nend : %d\n", start, top_left, top_right, down_left, down_right, end);

	pos = 0;
	temp[pos++] = 'x';
	for(int i = down_left; i <= end; i++)
		temp[pos++] = input[i];
	for(int i = top_left; i < down_left; i++)
		temp[pos++] = input[i];
	for(int i = start, pos = 0; i <= end; i++, pos++)
		input[i] = temp[pos];
	return (end);
}

void solve() {
    cin >> input;
    rec(0);
    cout << input << endl;
}

int main() {
    int C;

    cin >> C;
    for (int i = 0; i < C; i++)
		solve();
	return (0);
}
