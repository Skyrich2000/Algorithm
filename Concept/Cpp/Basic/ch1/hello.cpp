#include <iostream>

int main(void) {
    int num, num2;
    std::cout<<"변수 두개 입력 : ";
    std::cin>>num>>num2;
    std::cout<<"입력 한 변수 : "<<num<<","<<num2<<std::endl;

    char name[100];

    std::cout<<"이름? : ";
    std::cin>>name;
    std::cout<<"아~ "<<name<<"씨 군요?";
    return 0;
}