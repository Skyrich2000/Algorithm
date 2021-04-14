#include <iostream>

using namespace std;

int mem[2000][10] = {0};

int foo(int n, int x) {
    if (n == 0) return 0;

    if (mem[n][x] != 0) return mem[n][x];

    int summ = 0;
    for (int i = x; i < 10; i++) {
        summ += foo(n - 1, i) + 1;
    }
    mem[n][x] = summ;
    return summ;
}

int main() {
    int N;
    cin >> N;
    
    cout << (foo(N, 1) + 1) % 10007;

    return 0;
}