#include <stdio.h>
#include <stdlib.h>

int foo(int list[], int now, int len, int result, int aim);

int main() {
    int N;
    int K;
    int *numlist;

    scanf("%d", &N);
    scanf("%d", &K);
    numlist = malloc(K * sizeof(int));

    for(int i = 0; i < K; i ++) {
        scanf("%d", numlist + i);
    }

    printf("%d", foo(numlist, 0, K, 0, N));

    free(numlist);
}

int foo(int list[], int now, int len, int result, int aim) {
    if (now >= len) {
        if (result == aim)
            return 1;
        return 0;
    }

    int num = 0;
    num += foo(list, now + 1, len, result + list[now], aim);
    num += foo(list, now + 1, len, result - list[now], aim);
    return num;
}
