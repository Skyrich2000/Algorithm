#include <deque>
#include <iostream>

using namespace std;

int n;
int a[5][5];

template <typename T>
void print(deque<T> x, deque<T> y, deque<T> l) {
    int i;

    cout << "X : ";
    for (i = 0; i < x.size(); i++) {
        cout << x.at(i) << " ";
    }
    cout << endl;

    cout << "Y : ";
    for (i = 0; i < x.size(); i++) {
        cout << y.at(i) << " ";
    }
    cout << endl;

    cout << "L : ";
    for (i = 0; i < x.size(); i++) {
        cout << l.at(i) << " ";
    }
    cout << endl << endl;
    return ;
}

    void BFS() {
    deque<int> y, x, l;

    y.push_back(0);
    x.push_back(0);
    l.push_back(0);

    while (!x.empty() && (x.front() != n - 1 || y.front() != n - 1)) {
        a[y.front()][x.front()] = 0;

        if (y.front() > 0 && a[y.front() - 1][x.front()] == 1) {  //위쪽
            x.push_back(x.front());
            y.push_back(y.front() - 1);
            l.push_back(l.front() + 1);
        }

        if (y.front() < n-1 && a[y.front() + 1][x.front()] == 1) {  //아래쪽
            x.push_back(x.front());
            y.push_back(y.front() + 1);
            l.push_back(l.front() + 1);
        }

        if (x.front() > 0 && a[y.front()][x.front() - 1] == 1) {  //왼쪽
            x.push_back(x.front() - 1);
            y.push_back(y.front());
            l.push_back(l.front() + 1);
        }

        if (x.front() < n-1 && a[y.front()][x.front() + 1] == 1) {  //오른쪽
            x.push_back(x.front() + 1);
            y.push_back(y.front());
            l.push_back(l.front() + 1);
        }

        print(x,y,l);
        
        x.pop_front();
        y.pop_front();
        l.pop_front();
    }

    if (!x.empty()) cout << l.front() << endl;
}

int main() {
    cin >> n;

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) cin >> a[i][j];
    }  // 1 1 1 0 0 0 0 1 1 1 1 1 1 0 1 1 0 0 0 1 1 1 1 1 1

    BFS();
    return 0;
}