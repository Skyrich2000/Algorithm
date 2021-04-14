#include <iostream>

using namespace std;

//동전 2개를 차례대로 던질 때 나오는 모든 경우를 출력
//먼저 트리 구조로 경우의 수를 생각하고 재귀 호출을 이용

int num = 2;
int c[2];

void coin(int n) {
    int i;

    if (n == num) {
        for(i = 0; i < num; i++) {
            if (c[i] == 1) cout<<"앞";
            else cout<<"뒤";
        }
        cout<<endl;
        return ;
    }

    for(i = 1; i <= 2; i++) {
        c[n] = i;
        coin(n+1);
    }
}

int main() {
    coin(0);
    return 0;
}