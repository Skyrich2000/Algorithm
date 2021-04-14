#include <iostream>

using namespace std;

//모든 경로의 개수를 샌다.

int cnt = 0, n;
int r[5][5];

//1 1 1 0 0 0 0 1 1 1 1 1 1 0 1 1 0 0 0 1 1 1 1 1 1
//배열 좌표에서 y ,x 로 하는게 맞는듯

void route(int y, int x) {
    cout<<"현재 좌표: "<<x<<','<<y<<endl;
    if(y == n-1 && x == n-1) {
        cnt++;
        cout<<"도착"<<endl;
        return ;
    }

    r[y][x] = 0;

    if(x+1 < n && r[y][x+1] == 1) route(y, x+1); //오른쪽
    if(x > 0 && r[y][x-1] == 1) route(y, x-1); //왼쪽
    if(y+1 < n && r[y+1][x] == 1) route(y+1, x); //아래쪽
    if(y > 0 && r[y-1][x] == 1) route(y-1, x); //위쪽

    r[y][x] = 1;
}

int main() {
    cin >> n;
    
    int i,j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) cin >> r[i][j];
    }

    route(0, 0); //n,n까지 탐색

    cout<<cnt<<endl;
    return 0;
}