#include <iostream>
using namespace std;
// friend 개념 + static 개념 + const 함수 내에서 값의 변경을 예외적으로 허용하는 mutable
// friend는 뭐드라
class SoSimple {
private:
    int num;
public:
    SoSimple(int n) : num(n) {

    }

    void SimpleFunc() {
        cout << "SimpleFunc" << num << endl;
    }

    void SimpleFunc() const { //const 로 오버로딩 가능
        cout << "const SimpleFunc" << num << endl;
    }
};

void YourFunc(const SoSimple &obj) { //const 로 받은 인자는 const 선언된 함수가 호출됨
    obj.SimpleFunc();
}

int main(void) {
    SoSimple obj1(2);
    const SoSimple obj2(7); //const 붙여서 선언하면 const 선언된 함수가 호출됨

    obj1.SimpleFunc();
    obj2.SimpleFunc();

    YourFunc(obj1);
    YourFunc(obj2);
    return 0;
}