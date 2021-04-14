#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main() {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2;
    copy(v1.begin(), v1.end(), v2.begin()); // 일반적인 덮어쓰기 모드로는 에러남
    copy(v1.begin(), v1.end(), inserter<vector<int>>(v2, v2.begin())); // 삽입모드로 바꿔서 넣음


    list<int> lt1;
    lt1.assign(3, 1);
    
    list<int> lt2;
    lt2.assign(3, 1);

    copy(v1.begin(), v1.end(), back_inserter<list<int>>(lt1)); //lt1 뒤에 v추가
    copy(v1.begin(), v1.end(), back_inserter<list<int>>(lt2));  // lt2 앞에 v추가

    return 0;
}
