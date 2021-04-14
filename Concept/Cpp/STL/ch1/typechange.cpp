#include <iostream>
using namespace std;

class A {

};

class B {
public:
    B() { }
    B(A& _a) {}
    B(int n) { }
    explicit B(double d) {}

    operator A() {
        return A(); //A 생성해서 넘겨줌
    }

    operator int() {
        return 10;
    }

    operator double() {
        return 5.5;
    }
};

int main() {
    A a;
    int n = 10;
    double d = 5.5;

    B b;
    b = a; //b = B(a) 암시적 생성자 호출 후 대입
    b = n; //이를 막기 위해서 인자를 갖는 생성자는 모두 explicit 생성자로 만들자.
    b = d;  //에러 나야되는데 ..?

    a = b; //b.operator A() 암시적 호출
    n = b;
    d = b;

    a = b.operator A(); //명시적 호출
    n = b.operator int();

    return 0;
}