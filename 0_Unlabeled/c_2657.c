#include <stdio.h>

int foo(int N, int now, int person, int log);

int main() {
    int N;
    int K;

    scanf("%d %d", &N, &K);
    
    printf("%d",foo(N,0,K,1));
}

int foo(int N, int now, int person, int log) {
    if (now >= N) {
        if (person == 0)
            if (log != 2)
                return 1;
        return 0;
    }

    int num = 0;
    if (person != 0) 
        if (log != 2)
            num += foo(N, now + 1, person - 1, log + 1);
    num += foo(N, now + 1, person , 0);
    return num;
}
