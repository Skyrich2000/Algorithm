#include <iostream>
using namespace std;

int main(void) {
    int num1, num2;
    cout<<"두 개의 숫자 입력 : ";
    cin>>num1>>num2;

    try {
        if(num2 == 0) throw num2;
        cout<<"나눗셈의 몫: "<< num1/num2 <<endl;
    }
    catch (int expn){
        cout<<"제수는" <<expn<<"이 될 수 없습니다."<<endl;
    }
    return 0;
}