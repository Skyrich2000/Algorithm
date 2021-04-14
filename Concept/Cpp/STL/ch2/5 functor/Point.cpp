#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Point {
    int x;
    int y;
public:
    explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
    void print() const { cout << x << ',' << y << endl; }
};

int main() {
    vector<Point*> v;
    v.push_back(new Point(1, 1));
    v.push_back(new Point(2, 2));
    v.push_back(new Point(3, 3));
    v.push_back(new Point(4, 4));

    for_each(v.begin(), v.end(), mem_fn(&Point::print));  //멤버 함수 포인터 어댑터
    
    return 0;
}