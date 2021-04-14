#include <memory.h>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    bool a[10], aa[10][10];
    char b[10], bb[10][10];
    int c[10], cc[10][10], i, j;

    cout << boolalpha;  // bool 데이터를 true, false 로 표시 아니면 0 과 1으로 출력

    memset(a, true, sizeof(a));
    for (i = 0; i < 10; i++) cout << a[i] << " ";
    cout << endl;

    memset(b, 'A', sizeof(b));
    for (i = 0; i < 10; i++) cout << b[i] << " ";
    cout << endl;

    memset(c, 1, sizeof(c)); //memset 은 1바이트 기준으로 초기화한다. 따라서 1넣으면 이상한값 나옴 따라서 1바이트 이외의 데이터는 0으로 초기화
    for (i = 0; i < 10; i++) cout << c[i] << " ";
    cout << endl;

    memset(aa, true, sizeof(aa));
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++) cout << aa[i][j] << " ";
    cout << endl;

    memset(bb, 'B', sizeof(bb));
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++) cout << bb[i][j] << " ";
    cout << endl;

    memset(cc, 0, sizeof(cc));
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++) cout << cc[i][j] << " ";
    cout << endl;

    return 0;
}