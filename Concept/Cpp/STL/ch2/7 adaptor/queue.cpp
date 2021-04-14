#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main() {
    queue<int, list<int>> q; //컨테이너 형식을 따로 지정해줄수도있다.

    q.push(10);
    q.push(10);
    q.push(10);

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
        
    }

    return 0;
}
