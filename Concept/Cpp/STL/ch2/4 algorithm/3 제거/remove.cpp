#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n) {
    return 30 <= n && n <= 40;
}

bool Pred2(int left, int right) {
    return abs(right - left) < 10;
}

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter;

    iter = remove(v.begin(), v.end(), 30);//순차열에서 원소 30 제거 
    iter = remove_if(v.begin(), v.end(), Pred);
    //실제 제거는 아니고 그냥 뒤에서 앞으로 덮어씀 크기는 그대로

    v.erase(iter, v.end()); //삭제할 순차열 반복자 구간

    iter = remove_copy(v1.begin(), v1.end(), v2.begin(), 30);
    iter = remove_copy(v1.begin(), v1.end(), v2.begin(), Pred);
    //순차열에서 30원소를 제외한 모든 원소를 목적지 순차열에 복사

    iter = unique(v.begin(), v.end());
    //인접한 중복 원소를 제거
    //인접하지 않은 중복 원소는 남게 된다.
    //따라서 정렬후 unique를 하면 중복 원소 다 제거 가능

    iter = unique(v.begin(), v.end(), Pred2);
    //인접한 원소의 차가 10미만인 원소를 논리적으로 제거

    unique_copy() //인접한 중복 원소를 제거하여 목적지 순차열로 복사

    return 0;
}