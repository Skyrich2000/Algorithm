//해당내용은 구조체 뿐만 아니라 클래스에서도 그대로 적용된다.

#include <iostream>
// #include <string.h> 앞에c를 붙이고 .h를 빼서 씀
#include <cstring>
using namespace std;

typedef struct __Point { 
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2) { //const는 변수의 변화가 없다는걸 명시
    Point* pp = new Point;
    pp->xpos = p1.xpos+p2.xpos;
    pp->ypos = p1.ypos+p2.ypos;
    return *pp;
} 

char* MakeStrAdr(int len) {
    char* str = new char[len];
    return str;
}

int main(void) {
    char* str = MakeStrAdr(20);
    strcpy(str,"I am so happy~");
    cout<<str<<endl;
    delete []str;

    Point* pptr1 = new Point; //구조체 포인터
    (*pptr1).xpos = 3; 
    pptr1 -> ypos = 30;

    Point pptr2;  //구조체 변수
    pptr2.xpos = 70;
    pptr2.ypos = 7;

    Point& pref = PntAdder(*pptr1, pptr2);
    cout<<"["<<pref.xpos<<", "<<pref.ypos<<"]"<<endl;
    return 0;
}