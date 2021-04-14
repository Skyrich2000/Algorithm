#include <iostream>
#define SQUARE(x) ((x)*(x)) //매크로 함수 -> 코드 내로 대체 되어 들어감 -> 속도 향상

inline int square(int x) { //매크로 함수와 동일한 기능 but 자료형에 있어 단점 < 탬플릿이 보완
    return x * x;
}

int adder(int a, int b=4);
//디폴트 값은 선언부분 사용시 선언부분에만 + 오른쪽부터 값을 채우는 형태로 정의해야함

int adder(int a, int b) {
    return a + b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(double *a, double *b) { //자료형, 개수가 다른거면 오버로딩 가능
    double temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int num1=10, num2=20;
    swap(&num1, &num2);
    std::cout<<num1<<","<<num2<<":"<<adder(num1)<<std::endl;

    double num3 = 112.312, num4 = 321.123;
    swap(&num3, &num4);
    std::cout << num3 << "," << num4 << std::endl;
}