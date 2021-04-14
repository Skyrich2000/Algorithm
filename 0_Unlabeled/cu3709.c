#include <stdio.h>
#include <stdlib.h>

int foo(int now, int N, long long list[]);

int main() {
    int N;
    long long *list;
    scanf("%d", &N);

    list = malloc(N * sizeof(long long));
    for(int i = 0; i < N ; i++)
        list[i] = -1;
    
    printf("%d \n", foo(0,N,list) % 100000007);

    for (int i = 0; i < N; i++)
        printf("%llu \n", list[i]);

    free(list);
    return 0;
}

int foo(int now, int N, long long list[]) {
    if (now == N)
        return 1;
    if (now > N)
        return 0;

    int num = 0;
    if (list[now] == -1) {
        num += foo(now + 1, N, list);
        num += foo(now + 2, N, list);
        list[now] = num;
    }
    return list[now];
}