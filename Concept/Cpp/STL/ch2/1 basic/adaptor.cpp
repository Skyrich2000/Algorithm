#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    stack<int> st; //stack의 디폴트 컨테이너 deque를 사용하여 stack 컨테이너 객체를 생성
    stack<int,vector<int>> st2; //컨테이너 vector를 이용한 stack 컨테이너 객체를 생성ㄴ

    st.push(10); //데이터 추가
    st.top(); //top 데이터 출력
    st.pop(); //top 데이터 삭제
    st.empty(); //비었는지 확인

    return 0;
}