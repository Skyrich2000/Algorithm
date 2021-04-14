#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Accumulatoin {
    int total;
public:
    explicit Accumulatoin(int init = 0) : total(init) { }
    void operator() (int& r) { //r값을 수정해야되니까 참조자로 선언해야됨
        total += r;
        r = total;
    }
};

template <typename T>
struct Greater {
    bool operator() (const T& left, const T& right) const {
        return left > right ;
    }
};

int main() {
    vector<int> v;
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    
    vector<int> v2(5);
    vector<int> v3;
    vector<int>::iterator iter;
    vector<int>::iterator iter2;
    iter = copy(v1.begin(), v1.end(), v2.begin()); //v2.begin() 자리부터 v1 원소 덮어쓰기
    iter = copy_backward(v1.begin(), v1.end(), v2.end())); // v2.end() 자리 뒤에서부터 v1 원소 덮어쓰기

    fill(v.begin(), v.end(), 0); //구간에 0으로 채우기
    fill_n(v.begin(), 3, 55); //시작점으로부터 3개칸만큼 55로 채우기

    for_each(v.begin(), v.end(), Accumulatoin(0));


    generate(v.begin(), v.end(), Integer(1)); //구간만큼 매 원소마다 Integer가 호출된 리턴값이 들어감
    generate_n(v.begin(), 3, Integer(1));

    int a = 10;
    int b = 20;
    swap(a, b);

    swap(iter, iter2); //반복자가 가리키는 값을 서로 바꿔주기도함
    swap_ranges(v1.begin(), v1.end(), v2.begin()); // 순차열과 순차열의 모든 원소를 교환

    iter = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), greater<int>()); //정렬된 두 순차열을 하나의 정렬된 순차열로 합병 끝 반복자를 반환

    replace(v.begin(), v.end(), 30, 0); //순차열의 특정 원소를 다른 값으로 수정하고자 할떄 30을 0으로 대체
    replace(v.begin(), v.end(), Pred, 0); //Pred에 해당하는 원소를 0으로 대체 

    iter = replace_copy(v1.begin(), v1.end(), v2.begin(), 30, 0); //30인 원소를 0으로 변환해서 v2 순차열에 저장
    iter = replace_copy_if(v1.begin(), v1.end(), v2.begin(), Pred, 0); //30인 원소를 0으로 변환해서 v2 순차열에 저장

    iter = transform(v1.begin(), v1.end(), v2.begin(), Func); //Func 적용해서 나온 결과를 3번째 인자 반복자에 하나씩 넣음
    iter = transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>()); //v1 와 v2의 순차열의 합을 v3에 넣음
    // 이거 다 덮어쓰기 모드로 작동
    // 삽입 하려면 insert_iterator 써야된다.
    return 0;
}