// adjacent_find 순차열에서 인접한 원소를 찾아주는 알고리즘
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Pred(int a, int b) { //인접함의 기준을 제시할수도 있다. 
    return abs(b-a) > 10;
}

bool Compare(int a, int b) {
    return a > b;
}

bool Pred2(int el, int x) {
    return abs(el - x) <= 5 ; //30 로부터 오차 5까지는 허용한다
}

class PrintFunctor {
    char fmt;
public:
    explicit PrintFunctor(char c = ' ') : fmt(c) { }
    void operator() (int a) const {
        cout << a << endl;
    }
};

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter;
    iter = adjacent_find(v.begin(), v.end(), Pred); //구간 + 조건

    if(iter != v.end()) //실패시 구간의 마지막을 반환 (무조건 v.end 가 아니라 구간에 따라 다름에 주의)
        cout << *iter << endl;

    equal(v1.begin(), v1.end(), v2.begin(), Pred)  //두 순차열의 원소를 비교

    iter = find(v.begin(), v.end(), 20); //구간에서 20인 첫번째 원소
    iter = find_if(v.begin(), v.end(), Pred);  //구간에서 Pred를 만족하는 첫번째 원소

    //순차열 하나에 포함되는 다른 순차열이 있는지 찾는거
    find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), Pred); //마지막 순차열의 반복자를 반환
    search(v1.begin(), v1.end(), v2.begin(), v2.end(), Pred); //첫번째 순차열의 반복자를 반환

    iter = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end(), Pred); //v1의 순차열에서 v2의 원소중 하나라도 큰 첫원소를 반복자로 반환

    for_each(v.begin(), v.end(), Print); //모든 원소에 Print 함수 적용
    for_each(v.begin(), v.end(), PrintFunctor('\n')); //모든 원소에 PrintFunctor 함수 적용

    if(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), less<int>())) //문자열 비교처럼 순차열의 사전순 비교가 필요할경우 less조건자 활용
        cout << "less v1 v2 비교 : true" << endl;


    max(pt1, pt2, Compare); //객체로 비교 가능 비교 기준은 bool 반환형식의 이항 조건자

    iter = max_element(v.begin(), v.end(), Compare); //구간에 가장 큰놈 반복자 리턴 Compare는 이항 조건자

    pair<vector<int>::iterator, vector<int>::iterator> iter_pair;
    iter_pair = mismatch(v1.begin(), v1.end(), v2.begin(), Pred); //두 순차열을 비교하여 원소 값이 다른 위치를 찾음

    iter = search_n(v.begin(), v.end(), 3, 30, Pred2); //순차열에서 원소 30이 3번이상 연속한 첫 원소의 반복자를 반환



    return 0;
}