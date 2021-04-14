#include <stdio.h>

int re(int num,int sum){
    sum += 1;
    if(num==1){
        return sum;
    }
    else if(num % 3==0){
        return re(num/3,sum);
    } 
    else if ((num-1) % 3 == 0) {
        return re(num-1,sum);
    } else if (num % 2 == 0) {
         return re(num/2,sum);
    }
    else{
         return re(num-1,sum);
    }
}
int main(){
    int num,result;
    scanf("%d", &num);
    result = re(num,-1);
    printf("%d", result);
    return 0;
}
