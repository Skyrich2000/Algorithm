#include <iostream>
using namespace std;

class Point {
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
    void Print() const { cout << x << y << endl; }
};

class PointPtr {// *, -> 연산자는 iterator 객체에서 자주 쓰임 따라서 이거 오버로딩 할줄 알아야한다. (스마트 포인터)
    Point *ptr;
public:
    PointPtr(Point *p) : ptr(p) { }
    ~PointPtr() {
        delete ptr;
    }
    Point* operator->() const{
        return ptr;
    }
    Point& operator*() const {
        return *ptr;
    }
};

int main() {
    Point* p1 = new Point(2, 3); //일반 포인터
    PointPtr p2 = new Point(5, 5); //스마트 포인터 

    p1->Print();
    p2->Print();
    cout << endl;

    (*p1).Print();
    (*p2).Print();

    delete p1;

    return 0;
}

