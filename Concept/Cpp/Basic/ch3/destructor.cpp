#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;
    int age;
public:
    Person(char* myname, int myage) : age(myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
    }

    Person(char* myname) : name(myname) {
        age = 10;
    }

    void ShowPersonInfo() const {
        cout<<name<<":"<<age<<endl;
    }

    ~Person() {
        delete []name;
    }
};

int main(void) {    
    Person man1("asdf");
    Person man2("asdf2", 42);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}