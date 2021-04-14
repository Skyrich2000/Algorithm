#include <iostream>
using namespace std;

class AAA {
public:
    void Func1() {
        cout<<"Func1"<<endl;
    }

    void Func2() {
        cout<<"Func2"<<endl;
    }
};

class BBB: public AAA {
public:
    void Func1() {
        cout<<"BBB:Func1"<<endl;
    }

    void Func3() {
        cout<<"BBB:Func3"<<endl;
    }
};

int main(void) {
    AAA *aptr = new AAA();
    aptr->Func1();

    AAA *bptr = new BBB();
    bptr->Func1();

    delete aptr;
    delete bptr;
    return 0;
}

//다중상속은 p390을 참조