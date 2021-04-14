#include <iostream>
#include <cstring>
using namespace std;

class Person {
private :
    char *name;
    int age;
public:
    Person(char *myname, int myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    void ShowPersonInfo() const {
        cout<<"name: "<<name<<endl;
        cout<<"age: "<<age<<endl;
    }

    ~Person() {
        delete []name; //이미 삭제된 문자열을 man2에서 또 지우려고 함
        cout<<"called destructor!"<<endl;
    }
};

int main(void) {
    Person man1("name1", 29);
    Person man2 = man1; //얉은 복사 (디폴트 복사)
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}