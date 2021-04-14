#include <iostream>
#include <memory> // shared_ptr을 사용하기 위해 

class Car {
public: 
    void Go() { std::cout << "Go" << std::endl; } 
    ~Car() { std::cout << "~Car" << std::endl; } 
}; 

void test(Car* c) {
    Car* cc = c;
    cc->Go();
}

int main() { 
    std::shared_ptr<Car> p(new Car); // = 생성자는 지원하지 않음
    p->Go();

    test(&(*p));
    
}