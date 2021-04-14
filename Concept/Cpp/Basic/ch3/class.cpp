
/*
127page에서 c언어에서 익혀할거 적혀잇음 

private나 public 선언 안하고 그냥 변수 선언하면 
class는 private 으로 선언되고
구조체는 public 으로 선언된다.

클래스의 맴버변수 선언문에서 초기화까지 하는거 허용하지 않음. -> 생성자에서 해야됨

클래스 생성 방법

ClassName objName;
CalssName* ptrObj = new ClassName;;
*/

class EasyClass {
private:
    int num;

public:
    void InitNum(int n) {
        num = n;
    }

    int GetNum() const {  // const
        return num;
    }
};

class LiveClass {
private:
    int num;

public:
    void InitNum(const EasyClass &easy) { //const로 받은 클래스의 함수를 호출하려면 그 함수도 const 선언 되어있어야함
        num = easy.GetNum(); 
    }
};