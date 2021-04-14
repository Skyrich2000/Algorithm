#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main() {
    priority_queue<int, deque<int>, greater<int>> q;  //내부적으로 힙 알고리즘으로 되어있어 기본컨테이너로 vector 랑 deque 만 사용가능
    q.push(10);
    q.push(20);
    q.push(40);

    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }

    return 0;
}