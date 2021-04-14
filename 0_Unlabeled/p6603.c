#include <stdio.h>

void printarray(int *index, int *indexp, int *eraser, int tc);

int main (){
    int tc, *index,i,*eraser,*indexp;
    while(1){
        scanf("%d", &tc);
        if(tc==0) {
            break;
        }
        index=malloc(tc*sizeof(int));
        indexp=malloc(tc*sizeof(int));
        eraser=malloc((tc-6)*sizeof(int));
        for(i=0;i<tc;i++){
            scanf("%d", index[i]);
            indexp[i] = index[i];
        }
        for(i=0;i<tc-6;i++){
            eraser[i] = i+6;
        }

        printarray(index,indexp,eraser,tc);
    }
}

void printarray(int *index, int *indexp, int *eraser, int tc) {
    int i;
    for(i=0;i<tc-6;i++){
        indexp[eraser[i]] = -1;
    }
    for(i=0;i<tc;i++){
        if (indexp[i] != -1) printf("%d ",indexp[i]);
    }
    for(i=0;i<tc-6;i++){
        indexp[eraser[i]] = index[eraser[i]];
    }
}