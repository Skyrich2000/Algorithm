#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter;
    iter = find(v.begin(), v.end(), 20);
    cout << *iter << endl;

    iter = find(v.begin(), v.end(), 100);
    if(iter == v.end())
        cout << "no result" << endl;

    sort(v.begin(), v.end()); //오름차순 정렬 - 임의 접근 반복자이므로 vector 랑 deque만 sort알고리즘 가능ㄴ

    sort(v.begin(), v.end(), less<int>()); //오름차순 정렬
    sort(v.begin(), v.end(), greater<int>()); //내림차순 정렬

    return 0;
}