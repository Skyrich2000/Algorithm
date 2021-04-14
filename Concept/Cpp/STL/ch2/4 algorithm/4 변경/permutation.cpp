#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

bool Pred(const int& left, const int& right) {
    return left < right;
}

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    vector<int>::iterator iter;

    next_permutation(v.begin(), v.end(), Pred);
    //사전순으로 정렬하는데 더이상 정렬할게 없으면 0 더 정렬해야되면 1 
    //사전순 마지막 순열 일경우 0을 반환
    //조건자 넣어서 정렬기준 바꿀수있음

    prev_permutation(v.begin(), v.end(), Pred);
    //위에꺼랑 거의 똑같은데 반대로 정렬함
    //사전순 첫번째 순열 일경우 0을 반환

    iter = partition(v.begin(), v.end(), Pred);
    //Pred 값을 기준으로 원소를 분리함 분리된 원소의 중앙은 iter 반복자
    //순서가 어긋날수있음

    iter = stable_partition(v.begin(), v.end(), Pred);
    //partition 이랑 같은데 순서가 그대로 대신에 성능이 조금 떨어짐

    srand((unsigned)time(NULL));
    random_shuffle(v.begin(), v.end()); //원소를 뒤섞는다.

    reverse(v.begin(), v.end()); //순차열 뒤집기
    iter = reverse(v1.begin(), v1.end(), v2.begin()); //뒤집은 순차열을 목적지 순차열로
    //덮어쓰기 이므로 v2는 v1이상의 원소를 가져야함

    vector<int>::iterator middle = v.begin() + 2;
    rotate(v.begin(), middle, v.end());
    //모든 원소를 왼쪽으로 2만큼씩 회전

    iter = rotate_copy(v1.begin(), middle, v1.end(), v2.begin());   
    //회전해서 목적지 순차열로 복사
    return 0;
}