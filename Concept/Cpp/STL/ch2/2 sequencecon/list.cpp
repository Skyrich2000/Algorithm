//list는 노드 기반 삽입 제거가 빈번하게 발생한다면 list를 사용
//기본적인 사용법은 deque랑 동일
//원소가 추가, 삭제(현재 가리키는 원소 제외) 되어도 기존 반복자를 계속 사용 가능
#include <iostream>
#include <list>
using namespace std;

bool Predicate(int n) { //단항 조건자
    return 10 <= n && n <= 30;
}

bool Predicate2(int first, int second) {
    return second - first <= 0;
}

int main() {
    list<int> lt;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(10);

    //반복자를 이용해 원소를 제거하는 erase 말고도 원소의 값으로 원소를 제거하는 remove
    lt.remove(10); //원소 10 노드를 모두 제거

    lt.remove_if(Predicate) //조건자가 참인 모든 원소를 제거

    lt1.splice(iter, lt2) //iter가 가리키는 곳에 lt2를 갖다 붙임

    lt.reverse() //거꾸로
    lt.unique() // 인접한 원소 삭제

    lt.unique(Predicate2); //이항 조건자가 참이면 원소를 제거

    //그냥 알고리즘헤더안의 sort는 임의 접근 반복자를 지원하는 컨테이너에서만 사용가능 
    //따라서 list는 자체 맴버 함수를 제공

    lt.sort(); //오름차순
    lt.sort(greater<int>()); //내림차순

    lt1.merge(lt2) //lt2를 lt1으로 합병 정렬, 두 list 모두 같은 정렬기준으로 정렬되어야하며 합병 될때도 같은 정렬기준이여야함
}