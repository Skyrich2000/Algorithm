#include <iostream>
using namespace std;

template <typename T, int len>
class SimpleArray {
private:
    T arr[len]; //생성자로 했으면 T* arr;
public:
    //생성자 없음 ㅋㅋ 레전드
    T& operator[] (int idx) {
        return arr[idx];
    }

    SimpleArray<T, len>& operator= (const SimpleArray<T, len>& ref) { 
        for(int i=0; i<len; i++)
            arr[i] = ref.arr[i];
        return *this;
    }
    //template <typename U, int len2> //위에 선언된 템플릿때문에 friend는 외부에서 오는거니까? 새롭게 정의해줘야한다? 이상하네 ㄹㅇ;;
    //friend ostream& operator<< (ostream& os, const SimpleArray<U, len2>& ref);
    friend ostream& operator<< (ostream& os, const SimpleArray<T, len>& ref);
};

template <typename T, int len>
ostream& operator<<(ostream& os, const SimpleArray<T, len>& ref) {
    for(int i=0; i<len; i++)
        cout<<ref.arr[i]<<',';
    return os;
}

int main(void) {
    SimpleArray<int, 5> i5arr1;
    SimpleArray<int, 5> i5arr2;
    for(int i=0; i<5; i++)
        i5arr1[i] = i *10;
    i5arr2 = i5arr1;
    cout<<i5arr2<<endl;

    SimpleArray<int, 7> i7arr1;
    SimpleArray<int, 7> i7arr2;
    for(int i=0; i<7; i++)
        i7arr1[i] = i *10;
    i7arr2 = i7arr1;
    //cout<<i7arr2<<endl;

    return 0;
}