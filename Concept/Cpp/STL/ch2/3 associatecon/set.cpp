//모든 연관 컨테이너는 생성자, 맴버 함수, 연산자가 동일
//set은 모든 원소가 유일해야함 중복을 원한다면 multiset
//균형 이진 트리를 사용하기 때문에 삽입, 찾기연산이 로그시간복잡도를 보인다.

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int, less<int>> s; //정렬기준으로 less<int> 조건자를 사용
    pair<set<int>::iterator, bool> pair1;
    set<int>::iterator iter;

    s.insert(50);
    pair1 = s.insert(50); //반환으로 이미 삽입되어있는 원소의 반복자와 실패여부
    if(false == pair1.second) 
        cout << *pair1.first << endl;

    s.insert(pair1.first, 85); //pair.first 가 가리키는 위치부터 탐색을 시작하여 85를 삽입한다.

    //set은 value값이 곧 key가 된다.

    set<int, less<int>>::key_compare l_cmp = s.key_comp(); //set의 조건자를 반환
    cout << l_cmp(1, 2) << endl; 

    s.count(50); //원소 50의 갯수를 반환 로그시간복잡도
    iter = s.find(30); //30의 반복자를 반환
    if(iter != s.end()) 
        cout << "존재함" << endl;

    //같다(equivalence) 의 기준이 그냥 == 가 아니다 
    //정렬 기준으로 a가 b보다 앞서있지 않고 b가 a보다 앞서있지 않다면 a와 b는 같다고 판단한다.
    cout << (!s.key_comp()(30,50) && !s.key_comp()(50,30)) << endl; //다름 
    cout << (!s.key_comp()(30,30) && !s.key_comp()(30,30)) << endl; //같음

    pair<set<int>::iterator, set<int>::iterator> pair2;
    iter = s.lower_bound(30); //30이 시작하는 구간의 반복자 즉 30그자체
    iter = s.upper_bound(30); //30이 끝나는 구간의 반복자 즉 30다음꺼
    pair2 = s.equal_range(30); //pair2.first = lower_bound, pair2.second = upper_bound
    
    //set은 삭제/추가만 되지 값 변경은 없다
    return 0;
}
