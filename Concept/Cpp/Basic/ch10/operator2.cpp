#include <iostream>
using namespace std;

class Point {
private:
    int xpos;
    int ypos;
public:
    friend ostream& operator<<(ostream& os, Point& pos);
    friend istream& operator>>(istream& os, Point& pos);
};

ostream& operator<<(ostream& os, Point& pos) {
    cout<<pos.xpos<<','<<pos.ypos<<endl;
    return os;

}

istream& operator>>(istream& os, Point& pos) {
    cin>>pos.xpos>>pos.ypos;
    return os;
}

int main() {
    Point pos1;
    cin>>pos1;
    cout<<pos1;
    return 0;
}