#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    multiset<int>::iterator iter;

    ms.insert(50); 
    iter = ms.insert(10); //저장된 위치를 가리키는 반복자를 반환

    //나머지는 set과 동일
}