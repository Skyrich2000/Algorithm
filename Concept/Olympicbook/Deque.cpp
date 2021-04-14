#include <iostream>
#include <deque> //앞뒤로 뺏다 넣었다 가능 큐처럼 사용
#include <string>

using namespace std;

template <typename T>
void print(deque<T> con) {
    for (int i = 0; i < con.size(); ++i) cout << con[i] << " ";
    cout << endl;
}

int main() {
    deque<string> ss;

    ss.push_back("May");
    ss.push_back("I");
    ss.push_back("help");
    ss.push_back("you");
    ss.push_back("?");
    print(ss);

    ss.pop_back();
    ss.pop_front();

    ss.push_front("...");
    ss.push_front("T_T");
    print(ss);

    return 0;
}