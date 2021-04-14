//key - value 로 구성
//key는 유일해야함
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int, less<int>> m;
    map<int, int>::iterator iter;
    m.insert(pair<int, int>(5, 100)); //반환은 set마냥 해당원소가 있는 반복자랑 성공여부
    m[5] = 200; //값변경 가능
    for(iter = m.begin(); iter != m.end(); ++iter) {
        cout << (*iter).first << iter->second << endl;
    }
    return 0;
}