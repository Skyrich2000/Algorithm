#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int N;
    cin >> N;

    pair<int, int>* classes = new pair<int, int>[N];
    for (int i = 0; i < N; i++){
        cin >> classes[i].first >> classes[i].second;
    }
    sort(classes, classes + N);


    priority_queue<int, deque<int>, greater<int>> q;
    q.push(classes[0].second);
    for (int i = 1; i < N; i++){
        if (q.top() <= classes[i].first) q.pop();
        q.push(classes[i].second);
    }

    cout << q.size();

    delete classes;
    return 0;
}