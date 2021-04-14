#include <iostream>
#include <algorithm>

using namespace std;

int n;
int m;
int l;
int pos[101];

int rec(int left, int right) {
	int cnt;
	int mid;

	mid = (left + right) / 2;
	if (right <= left + 1)
		return (mid);
	cnt = 0;
	for (int i = 0, prev = 0; i < n; ) {
      if (pos[i] - prev > mid) {
          prev += mid;
          cnt++;
      }
      else {
         prev = pos[i];
         i++;
      }
   }
   return (cnt <= m ? rec(left, mid) : rec(mid, right));
}

int solve() {
	return (rec(0, l + 1) + 1);
}

int main() {
   cin >> n >> m >> l;
   for (int i = 0; i < n; i++)
      cin >> pos[i];
   pos[n++] = l;
	sort(pos, pos + n);
	cout << solve() << endl;
	return (0);
}
