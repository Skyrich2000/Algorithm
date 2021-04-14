#include <iostream>

namespace CAR_CONST { 
    enum { //define 마냥 사용
        ID_LEN = 20,
        MAX_SPD = 200,
        BRK_STEP = 10
    };
}

struct Car { //여기서 class Car 하면 Car 클래스 생성
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    void ShowCarState();
    void Accel();
    void Break();
};

void Car::ShowCarState() {
    
}

int main(void) {
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    return 0;
}