#include <stdio.h>
#include <stdlib.h>

int foo(int list[], int now, int len, int result, int aim);

int main() {
    int N;
    int aim;
    int *numlist;
    int re;

    scanf("%d %d", &N, &aim);
    numlist = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", numlist + i);
    }

    re = foo(numlist, 0, N, 0, aim);
    if (aim == 0) re -= 1;
    printf("%d", re);

    free(numlist);
}

int foo(int list[], int now, int len, int result, int aim) {
    if (now >= len) {
        if (result == aim) return 1;
        return 0;
    }

    int num = 0;
    num += foo(list, now + 1, len, result, aim);
    num += foo(list, now + 1, len, result + list[now], aim);
    return num;
}
