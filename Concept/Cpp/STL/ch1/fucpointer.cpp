#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

void For_each(int* begin, int* end, void (*pf)(int)) {
    while(begin != end) {
        pf(*begin++);
    }
}

void Print1(int n) { cout << n << " "; }

void Print2(int n) { cout << n * n << " "; }

void Print3(int n) { cout << n << endl; }

struct Functor1 {
    void operator()(int n) { cout << n << " "; }
};

struct Functor2 {
    void operator()(int n) { cout << n * n << " "; }
};

struct Functor3 {
    void operator()(int n) { cout << n << endl; }
};

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    For_each(arr, arr + 5, Print1); //함수 콜백 주소를 던져줌
    cout << endl << endl;
    For_each(arr, arr + 5, Print2);
    cout << endl << endl;
    For_each(arr, arr + 5, Print3);
    cout << endl << endl;

    for_each(arr, arr + 5, Functor1());  //임시 객체 던져줌
    cout << endl << endl;
    for_each(arr, arr + 5, Functor2());
    cout << endl << endl;
    for_each(arr, arr + 5, Functor3());
    cout << endl << endl;

    cout << less<int>()(10, 20) <<endl; //앞에꺼가 작으면 true
    cout << greater<int>()(10, 20) << endl; //앞에꺼가 크면 true

    cout << plus<int>()(10, 20) << endl;
    cout << minus<int>()(10, 20) << endl;

    return 0;
}