#include <iostream>
#include <algorithm>

using namespace std;

long long N, M;

int foo(int* woods, long long left, long long right) {
    long long mid = (left + right) / 2;
    if (left > right) return mid;

    long long result = 0;
    for (int i = 0; i < N; i++) {
        if (woods[i] - mid > 0) result += woods[i] - mid;
    }

    if (result >= M) return foo(woods, mid + 1, right);
    return foo(woods, left, mid - 1);
}

int main() {
    cin >> N >> M;
    
    int* woods = new int[N];
    long long max = -1;
    for (int i = 0; i < N; i++) {
        cin >> woods[i];
        if (max < woods[i]) max = woods[i];
    }
    
    cout << foo(woods, 0, max);

    delete woods;
    return 0;
}