#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int input;
    int pos = 0;
    int sum = 0;
    int *list;

    scanf("%d", &num);
    list = malloc(num * sizeof(int));
    
    for(int i = 0; i < num; i++) {
        scanf("%d", &input);
        if (input != 0) {
            list[pos++] = input;
        } else {
            list[--pos] = 0;
        }
    }

    for (int i = 0; i < pos; i++) {
        sum += list[i];
    }

    printf("%d", sum);
    free(list);
    return 0;
}