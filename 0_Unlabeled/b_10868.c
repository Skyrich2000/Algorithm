#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int init(int *arr, int *tree, int node, int start, int end);
int rori(int *tree, int node, int start, int end, int left, int right);
int min(int a, int b);

int main() {
    int *arr;
    int *tree;
    int *result;

    int num;
    int num_test;
    scanf("%d%d",&num,&num_test);
    
    int h = (int)ceil(log2(num));
    int tree_size = (1 << (h+1));

    arr = malloc(num*sizeof(int));
    tree = malloc(tree_size*sizeof(int));
    result = malloc(num_test*sizeof(int));

    for(int i = 0; i < num; i++) {
        scanf("%d",&arr[i]);
    }

    init(arr,tree,1,0,num-1);

    int start;
    int end;
    for(int i = 0; i < num_test; i++) {
        scanf("%d%d",&start,&end);
        result[i] = rori(tree,1,0,num-1,start-1,end-1);
    }

    for(int i = 0; i < num_test; i++) {
        printf("%d\n",result[i]);
    }
    
}

int init(int *arr, int *tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];        
        return tree[node];
    }
    
    int mid = (start+end)/2;
    tree[node] = min(init(arr,tree,node*2,start,mid),init(arr,tree,node*2+1,mid+1,end));
    return tree[node];
}

int rori(int *tree, int node, int start, int end, int left, int right) {
    if (left <= start && end <= right) {
        return tree[node];
    }

    if (end < left || right < start) {
        return 1000000001;
    }

    int s;
    int mid = (start+end)/2;
    s = min(rori(tree,node*2,start,mid,left,right),rori(tree,node*2+1,mid+1,end,left,right));
    return s;
}

int min(int a,int b) {
    if (a < b) {
        return a;
    }   
    return b;
}