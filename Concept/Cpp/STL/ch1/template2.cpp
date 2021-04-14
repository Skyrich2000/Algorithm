#include <iostream>
#include <string>
using namespace std;

template <typename RetType, typename ArgType>
class Functor {
public:
    RetType operator() (ArgType arg) {
        cout << arg << endl;
    }
};

int main() {
    Functor<void, int> functor1;
    functor1(10);
    Functor<void, string> functor2;
    functor2("asdf");
    return 0;
}