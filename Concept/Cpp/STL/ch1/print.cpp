#include <iostream>
using namespace std;

struct FuncObject {
public:
    void operator() (int arg) const {
        cout<<arg<<endl;
    }
};

void Print1(int arg) {
    cout<<arg<<endl;
}

int main() {
    void (*Print2)(int) = Print1;
    FuncObject Print3;

    Print1(10); // 함수 호출
    Print2(10); // 함수 포인터
    Print3(10); // 함수 객체
    return 0;
}