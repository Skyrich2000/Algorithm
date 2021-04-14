#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    int n, i, j, t, x;

    t = GetTickCount();
    cin >> n;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            x = i + j;
        }
    }

    cout << (GetTickCount()- t)/1000. <<endl;
}

//O(N) 은 걸리는 시간중에서 가장 많이 걸리는 시간으로 표시한다. 
//실제 대회에서는 무시할 수 없는 시간들까지 모두 계산해서 제한시간 내에 통과되도록 프로그램을 작성해야 된다.