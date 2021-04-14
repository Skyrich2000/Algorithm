// delete 자동으로 해주게 하는데 유용함
// 유용한 라이브러리가 있으니까 참고하도록

//펑터 operator() 를 이용하여 객체를 함수마냥 사용
//p486 SortFunctor.cpp 참고


//형 변환 오버로딩
//operator int() {
//    return num;
//}

#include <iostream>
using namespace std;

class Number {
private:
    int num;
public:
    Number(int n = 0) : num(n) {

    }

    Number& operator=(const Number& ref) {
        cout<<"operator"<<ref.num<<endl;
        num = ref.num;
        return *this;
    }

    void ShowNumber() { cout << num << endl;}

    operator int () { //객체가 int로 형변환 될때 호출됨 ㅇㅇ
        return num;
    }
};

int main(void) {
    Number num;
    num = 30;
    //num = Number(30);
    //Number 형 객체가 와야할 위치에 int형 데이터가 와서, int 형 데이터를 인자로 전달받는 Number 클래스의 생성자 호출을 통해서 Number 형 임시객체를 생성
    num.ShowNumber();
    return 0;
}