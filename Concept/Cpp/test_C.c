#include <stdio.h>
#include <string.h>

char* make_word() {
    char word[] = "asdf";
    //strcpy(word, "asdf");
    return word;
}

int main() {
    printf("%s", make_word());
}