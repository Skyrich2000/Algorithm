//deque 는 배열 기반
//메모리 할당에 있어서 vector와 차이가 있다.

//vector는 새로운 원소가 추가 될때 아예 새로운 배열을 새로 만들어서 이전 배열꺼를 복사하고 새로 추가하고 이전 배열을 지운다.
//deque 는 새로운 원소가 추가 될때 새로운 배열을 만들어서 새로 추가되는거만 그 배열에 넣는다.

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10); //뒤에 추가
    dq.push_front(10); //앞에 추가

    //이외에는 vector와 동일
}