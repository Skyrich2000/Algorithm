#include <string>

template <typename T>
//template <class T, class T2> //둘다 같은뜻
T add(T a, T b) { //함수 템플릿
    return a + b;
}

template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

template <>
char* max(
    char* a,
    char* b) {  //컴파일러가 만드는 함수를 미리 정의해서 특수화 시킬수있따.
    return strlen(a) > strlen(b) ? a : b; 
}

int main(void) {
    int a = add<int>(15, 20); //호출 당시 컴파일러가 int add<int>(int a, int b) 함수를 만든다. -> 일반 int add(int a, int b)랑은 차이가 잇음 
    int b = add(15, 20);
    return 0;
}