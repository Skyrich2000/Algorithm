#include <iostream>
#include <list>
 
using namespace std;
 
int main() {
    int N, K;
    list<int> l;
 
    cin >> N >> K;
 
    for (int i = 1; i <= N; i++)
        l.push_back(i);
 
    cout << "<";
    while (l.size()) {
        if (l.size() == 1) //the last one
        {
            cout << l.front() << ">";
            l.pop_front();
            break;
        }
        for (int i = 1; i < K; i++) {
            l.push_back(l.front());
            l.pop_front();
        }
        cout << l.front() << ", ";
        l.pop_front();
    }
    cout << endl;
    return 0;
}