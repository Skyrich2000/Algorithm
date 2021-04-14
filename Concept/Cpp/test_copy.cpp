#include <iostream>

using namespace std;

class Test {
public:
    friend ostream& operator<<(ostream& os, Test& self);
};

ostream& operator<<(ostream& os, Test& self) {
    cout << "Test";
    return os;
}

class Test2 {
public:
    friend ostream& operator<<(ostream& os, Test2& self);
};


ostream& operator<<(ostream& os, Test2& self) {
    cout << "Test2";
    return os;
}

int main() {
    Test t;
    Test2 t2;
    cout << t << t2;
    return 0;
}