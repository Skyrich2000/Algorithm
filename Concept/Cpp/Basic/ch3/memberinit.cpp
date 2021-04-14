class Rectangle {
private:
    Point upLeft;
    Point lowRight;
public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) :upLeft(x1, y1), lowRight(x2, y2) { //member initializer 
        //맴버 이니셜라이저는 생성자 코드로 private 에서 선언과 동시에 초기화 가능 -> const 맴버 변수도 이를 통해 가능
    }
}