#include <iostream>
using namespace std; //std::cout 하는거에서 std 빼고 쓰겠다.

int val=200;

namespace com2 {
    int a = 10;

    void fuc(void) {
        std::cout<<"com2의 fuc"<<std::endl;
    }

    namespace com2_1 {        
        void fuc(void) {
            int val = 10;
            val += 3;    //지역변수 val 증가
            ::val += 3;  //전역변수 val 증가
            std::cout<<::val<<"/"<<val<<com2::a;
        }
    }
}

namespace com1 {
    void fuc(void);
    void fuc2(void) {
        std::cout<<"com1의 fuc2"<<std::endl;
    }
}

void com1::fuc(void) {
    std::cout<<"com1의 fuc1"<<std::endl;
    fuc2(); //같은 namespace 에 있는거는 앞에 명시 안해도 됨
    com2::fuc();
}


int main(void) {
    com1::fuc();

    namespace com2A = com2::com2_1; //별칭 선언
    com2A::fuc();
    return 0;
}