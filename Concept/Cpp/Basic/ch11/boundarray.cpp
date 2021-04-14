#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray {
private:
    int* arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray& arr) {} //복사생성자 방지
    BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {} //대입연산자 방지
    //private 에둬서 얉은 복사 시도시 에러가 나게함
    //얉은 복사하면 안되지 저장소의 유일성이 보장되지 못함
public:
    BoundCheckIntArray(int len) : arrlen(len) {
        arr = new int[len];
    }

    int& operator[] (int idx) {
        if (idx < 0 || idx >= arrlen) {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return arr[idx];
    }

    int& operator[](int idx) const { //const로 오버로딩하여 
        if (idx < 0 || idx >= arrlen) {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const { return arrlen; }
    ~BoundCheckIntArray() { delete []arr; }
};

void ShowAllData(const BoundCheckIntArray& ref) {
    int len = ref.GetArrLen();
    for(int idx = 0; idx<len ; idx++) 
        cout<<ref[idx]<<endl;
}

int main(void) {
    BoundCheckIntArray arr(5);
    for(int i=0; i<5; i++) {
        arr[i] = (i+1) * 11;
    }
    BoundCheckIntArray cpy1(5);
    ShowAllData(arr);
    return 0;
}