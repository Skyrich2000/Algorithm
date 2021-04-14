//모든 원소의 누적을 구하거나, 원소에 연산이 필요한경우
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter;

    accumulate(v.begin(), v.end(), 100); //초기값 100으로 구간을 다 더해
    accumulate(v.begin(), v.end(), 0, plus<int>()); //합
    accumulate(v.begin(), v.end(), 0, multiplies<int>()); //곱

    inner_product(v1.begin(), v1.end(), v2.begin(), 100); //초기값 100으로 원소의 내적
    inner_product(v1.begin(), v1.end(), v2.begin(), 0, plus<int>(), minus<int>()); //두 원소의 차의 합

    iter = adjacent_difference(v1.begin(), v1.end(), v2.begin()); // 순차열 인접 원소간의 차를 목적지 순차열에 저장 -> 첫번째는 그대로 그다음부터는 인접한 원소의 차를 넣음
    //10 20 30 40 50 
    //10 10 10 10 10 
    iter = adjacent_difference(v1.begin(), v1.end(), v2.begin(), plus<int>()); //인접 원소의 합을 저장
    //10 20 30 40 50
    //10 30 50 70 90

    iter = partial_sum(v1.begin(), v1.end(), v2.begin()); //순차열에서 현재 원소까지의 합을 목적지 순차열에 저장
    //10 20 30 40 50
    //10 30 60 100 150
    iter = partial_sum(v1.begin(), v1.end(), v2.begin(), multiplies<int>());
    //10 20 30 40 50
    //10 200 6000 240000 12000000
    

    return 0;
}