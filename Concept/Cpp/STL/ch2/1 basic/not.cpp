#include <iostream>
#include <functional> //not2 사용
using namespace std;

int main() {
    cout << less<int>() (10, 20) << endl;
    cout << not2(less<int>()) (10, 20) << endl;
    //not2 반대 의미가 있는 함수 객체를 반환한다.
}