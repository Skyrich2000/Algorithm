//for each 를 템플릿으로 직접 구현해보기

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf) {
    while(begin != end) {
        pf(*begin++);
    }
}

template <typename T>
void Print(T data) {
    cout << data << endl;
}

template <typename T>
class PrintFunctor {
public:
    string sep;

    explicit PrintFunctor(const string& _sep = "\n"): sep(_sep) { }

    void operator() (T data) {
        cout << data << sep;
    }
};

int main() {
    int arr1[5] = {10,20,30,40,50};
    string arr2[3] = {"abc","ABC","hello!"};

    For_each(arr1, arr1 + 5, Print<int>);
    cout<<endl;
    For_each(arr2, arr2 + 3, Print<string>);
    cout << endl;
    For_each(arr1, arr1 + 5, PrintFunctor<int>());
    cout << endl;
}