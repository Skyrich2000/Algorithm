#include <iostream>
using namespace std;

template <typename T> //함수 템플릿과 마찬가지로, 컴파일러는 클래스 템플릿을 기반으로 템플릿 클래스를 만들어낸다.
class Point {
private:
    T xpos, ypos;
public:
    Point(T x = 0, T y = 0) : xpos(x), ypos(y) {

    }
    void ShowPosition() const;
    friend Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2);
};

template <typename T>
void Point<T>::ShowPosition() const {
    cout<<xpos<<','<<ypos<<endl;
}

Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2) {
    return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

int main(void) {
    Point<int> pos1(3,2);
    Point<double> pos2(2.4, 3.6);
    Point<int> pos3(4,5);
    Point<int> po4 = pos3 + pos1;
    return 0;
}