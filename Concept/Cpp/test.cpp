#include <iostream>

using namespace std;

class Test {
    int a;
    int b;
public:
    int* arr;
    Test(int a, int b) : a(a), b(b) { 
        cout << "create" << endl;
        arr = new int[10];
    }

    Test& show() {
        cout << a << " " << b << endl;
        return *this;
    }

    ~Test() {
        cout << "end" << endl;
        delete arr;
    }
};

Test& create_test() {
    Test* a = new Test(1,2);
    cout << a << endl;
    cout << &(*a) << " in " << a->arr << endl;
    return *a;
}

int main() {
    Test& a = create_test();
    cout << &(a.show()) << endl;
    cout << &a << " in " << a.arr << endl;;

    delete &a;

    return 0;
}