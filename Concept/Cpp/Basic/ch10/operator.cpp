#include <iostream>
using namespace std;

class Point {
private:
    int xpos;
    int ypos;
public:
    Point(int x, int y) : xpos(x), ypos(y) {

    }

    Point& operator+=(const Point &ref) {
        xpos += ref.xpos;
        ypos += ref.ypos;
        return *this;
    }

    Point& operator-=(const Point &ref) {
        xpos -= ref.xpos;
        ypos -= ref.ypos;
        return *this;
    }

    Point operator~() {
        return Point(ypos, xpos);
    }

    const Point operator++(int) { //앞에 붙은 const는 임시생성된 객체를 const 하겠다는 의미
        const Point retobj(xpos, ypos); //이건 그냥 객체를 const로 생성하겠다는 의미
        xpos++;
        ypos++;
        return retobj; //const로 하는 이유는 (pos++)++ 를 허용하지 않기 위함
    }

    friend bool operator==(const Point &pos1, const Point &pos2);
    friend bool operator!=(const Point &pos1, const Point &pos2);
    friend Point operator-(const Point &pos1, const Point &pos2); //friend를 붙여서 전역함수가 private에 접근가능 
};

Point operator-(const Point &pos1, const Point &pos2) {
    return Point(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

bool operator==(const Point &pos1, const Point &pos2) {
    return (pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos);
}

bool operator!=(const Point &pos1, const Point &pos2) {
    return !(pos1 == pos2);
}



int main(void) {
    Point pos1(0,0);
    Point pos2(10,10);

    pos1 += pos2;

    return 0;
}