#include <iostream>
using namespace std;

/*
묵시적 변환
SoSimple sim2 = sim1; 가
SoSimple sim2(sim1) 로 묵시적으로 변환됨

AAA obj = 3;
AAA obj(3);

explicit 붙이면 
AAA obj(3); 으로만 생성 및 초기화 가능
*/

class SoSimple {
private:
    int num1;
    int num2;
public:
    explicit SoSimple(int n1, int n2) : num1(n1), num2(n2) {

    }

    SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2) { //복사 생성자

    }

    void ShowSimpleData() {
        cout<<num1<<","<<num2<<endl;
    }
};

int main(void) {
    SoSimple sim1(15, 30);
    SoSimple sim2 = sim1; //복사 생성자 호출
    sim2.ShowSimpleData();
    return 0;
}

/*
복사 생성자가 호출되는 3가지 시점
1.위의 방법
2.함수 호출 과정에서 객체를 인자로 전달하는 경우
3.객체를 반환하되, 참조형으로 반환하지 않는 경우 -> 임시객체 생성
--> 객체 인자 전달할때 , 반환할때 참조자로 전달하자
*/