#include <algorithm>
#include <iostream>

using namespace std;

int n;
int m;
int note[1000001];

int rec(int left, int right, int num) {
    int mid;

    mid = (left + right) / 2;

    if (right <= left + 1)
		return (note[mid] == num);
    return (num < note[mid] ? rec(left, mid, num) : rec(mid, right, num));
}

void solve() {
    int temp;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
		scanf("%d", note + i);
    sort(note, note + n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        printf("%d\n", rec(0, n, temp));
    }
}

int main() {
    int c;

    scanf("%d", &c);
    for (int i = 0; i < c; i++) solve();
    return (0);
}
