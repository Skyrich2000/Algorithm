#include <iostream>
using namespace std;
//선언과 동시에 초기화해야되는거 : const 변수 , 참조자
//클래스 내부에서만 객체의 생성을 허용하려는 목적으로 생성자를 private로 선언하기도 한다.
//힙에 할당된 메모리 공간은 변수로 간주하여, 참조자를 통한 참조가 가능한다.ㅊ

class AAA {
public:
    AAA() {
        cout<<"empty object"<<endl;
    }

    void ShowYourName() {
        cout<<"i am class AAA"<<endl;
    }
};

class BBB {
private:
    AAA &ref;
    const int &num;
public:
    BBB(AAA &r, const int &n) : ref(r), num(n) { //이런식으로 호출과 동시에 초기화가능
    }


};


int main(void) {
    AAA obj1;
    BBB obj2(obj1, 20);
}