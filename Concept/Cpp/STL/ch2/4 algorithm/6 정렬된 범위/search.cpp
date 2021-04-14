//정렬된 구간에서만 동작하는 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int left, int right) {
    return 3 < right - left;
}

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter;

    if(binary_search(v.begin(), v.end(), 20)) //이진 검색 알고리즘으로 20이 있으면 true 반환
        cout << "20 존재" << endl;
    //같다의 기준이 == 이 아니라 !Pred(a,b) && !Pred(a,b) -> p412 참고

    sort(v.begin(), v.end(), Pred); //차가 3보다 크면 다음 위치의 원소로 이동
    if(binary_search(v.begin(), v.end(), 35, Pred)) 
        cout << "35 존재" << endl;


    includes(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>()); //v2가 v1의부분집합인지 확인


    //순차열에서 같은 원소를 찾기 위해 연관 컨테이너의 lower_bound, upper_bound 맴버 함수가 필요하다면,
    iter = lower_bound(v.begin(), v.end(), 30);
    iter = upper_bound(v.begin(), v.end(), 30);

    pair<vector<int>::iterator, vector<int>::iterator> pr;
    pr = equal_range(v.begin(), v.end(), 30);

    iter = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    //v1의 순차열과 v2의 순차열을 합병하여 v3의 순차열에 저장

    inplace_merge(v.begin(), v.begin()+5, v.end());
    // 두 구간으로 정렬된 하나의 순차열을 한구간으로 정렬

    iter = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    //두 순차열의 합집합을 v3순차열로 넣음 -> 중복되는건 안들어감

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()); //두 순차열의 교집합
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()); //두 순차열의 차집합 (v1 - v2)
    set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()); //두 순차열의 대칭 차집합 - p426
    return 0;
}