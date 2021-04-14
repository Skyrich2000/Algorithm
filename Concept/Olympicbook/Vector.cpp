#include <iostream>
#include <vector> //스택이랑 똑같은거 ㅇㅇ
#include <string>

using namespace std;

template <typename T>
void print(vector<T> con) { //배열식으로 출력 con.at(idx) 를 통해서 출력해도 된다.
    for (int i = 0; i < con.size(); ++i) cout << con[i] << " ";
    cout << endl;
}

int main() {
    vector<string> ss; //문자열을 원소로하는 벡터 생성
    ss.reserve(5); //원소 개수 5개로 예약

    ss.push_back("May");
    ss.push_back("I");
    ss.push_back("help");
    ss.push_back("you");
    ss.push_back("?");
    print(ss);

    ss.pop_back();
    ss.push_back("...");
    ss.push_back("T_T");
    print(ss);

    cout<<ss.front() << " " << ss.back() << endl;

    return 0;
}