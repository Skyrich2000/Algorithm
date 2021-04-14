#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    bool a[10], aa[10][10];
    char b[10], bb[10][10];
    int c[10], cc[10][10], i, j;

    cout << boolalpha;  // bool 데이터를 true, false 로 표시 아니면 0 과 1으로 출력

    fill(a, a+10, true);

    fill(b, b+10, 'A');

    fill(c, c+10, 17);

    for(i = 0; i< 10; i++) {
        fill(aa[i], aa[i]+10, true);
        for(j = 0; j < 10; j++) cout<< aa[i][j] << " ";
        cout << endl;
    }

    for (i = 0; i < 10; i++) {
        fill(bb[i], bb[i] + 10, 'B');
        for (j = 0; j < 10; j++) cout << bb[i][j] << " ";
        cout << endl;
    }

    for (i = 0; i < 10; i++) {
        fill(cc[i], cc[i] + 10, 19);
        for (j = 0; j < 10; j++) cout << cc[i][j] << " ";
        cout << endl;
    } 
    //이차원 배열도 일차원 식으로 처리해야되지만 데이터 형에 관계없이 원하는 값으로 대입할 수 있다는것이 장점이다.
    return 0;
}