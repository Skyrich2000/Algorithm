//힙 자료구조 = 완전 2진 트리 p391쪽 참고
//노드들에 들어가는 숫자는 항상 특정 규칙에 의해 들어가야함

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
    v.push_back(60);

    make_heap(v.begin(), v.end(), greater<int>()); //순차열을 힙(완전 2진 트리)로 정렬
    //모든 힙 알고리즘은 힙 구조일때만 작동함

    v.push_back(35); 
    push_heap(v.begin(), v.end(), greater<int>()); //힙 구조 유지

    pop_heap(v.begin(), v.end(), greater<int>()); //힙에서 루트 노드를 제거
    // 제거 알고리즘은 p397 쪽 참고 (간단히 : 루트의 와 마지막 노드를 교환후 힙 정렬)

    sort_heap(v.begin(), v.end(), greater<int>()); //정렬

    nth_element(v.begin(), v.begin()+20, v.end());
    //상위 20개를 첫번째 인자부터 두번째 인자에 놓이게 함

    nth_element(v.begin(), v.begin()+20, v.end(), greater<int>()); //조건자를 넣어서 비교가능

    sort(v.begin(), v.end(), greater<int>()); //퀵정렬
    stable_sort(v.begin(), v.end(), greater<int>()); //머지정렬 -> 상대적인 순서가 유지 된다.
    partial_sort(v.begin(), v.begin()+20, v.end(), greater<int>()); // 힙정렬 -> 퀵정렬보다는 성능이 떨어짐, 상위 20개의 원소를 정렬
    //순차열에 따라서 적정한 알고리즘을 선택해서 정렬해야됨

    vector<int> v2(20);
    partial_sort_copy(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>());
    //상위 20개를 정렬하여 v2순차열에 복사

    return 0;
}