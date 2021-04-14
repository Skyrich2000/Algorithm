#include <iostream>
using namespace std;

int& reffuc(int &ref) { //반환형이 참조형 반환하는값을 이어서 써라~
    ref++;
    return ref;
}
// int a = reffuc(b) 일경우 a에는 값이 들어감
// int &a = reffuc(b) 일경우 a에는 b의 참조가 들어감

void swap(int *n, int *n2){ //포인터를 이용한 call-by-reference
    int temp = *n;
    *n = *n2;
    *n2 = temp;
}

void swap(int &n, int &n2) { //참조자를 통한 call-by-reference n을과 n2를 그대로 이어서 쓰겠따 ㅇㅇ
    int temp = n;
    n = n2;
    n2 = temp;
}

int main(void) {
    int num1 = 2010;
    int *ptr2 = &num1; //포인터 변수에 num1의 주소를 대입
    int &num2 = num1; //num1의 참조자 num2를 선언
    //&에 대한 이해 : 이미 선언된 변수의 앞에 있으면 주소를 반환하라는뜻
    //새로 선언되는 변수의 이름 앞에 등장하면 참조자를 선언함
    //이때 참조자란 한 주소안에 다른 이름 하나 더 선언하는거 따라서 변수랑 거의 동일하게 작동
    //일종의 별칭으로 생각해도 된다.

    //선언과 동시에 변수 참조해야됨
    // int &num3; 이런건 안된다.

    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    int &ref = num;
    int *(&pref) = ptr;
    int **(&dpref) = dptr;

    cout<<&ref<<endl;
    cout<<pref<<endl; //포인터 변수 앞에 * 붙이면 그 변수가 품고 있는 주소가 품고있는 값을 가리킴 (그냥 반환 X)
    cout<<*dpref;

    swap(num, num1);



    const int &num4 = 10;
    //이렇게 const를 쓰면 10을 하나의 변수로 보고 해당 변수를 참조함
    //함수 호출 당시 상수를 참조값으로 받기 위함
    return 0;
}