#include <stdio.h>

int init(int *arr, int *arr_pos, int *tree, int node, int start, int end);
int sum(int *tree, int node, int start, int end, int left, int right);
void update(int *tree, int node, int diff);

int main() {
    int arr[6] = {3,5,4,6,7,2};
    int arr_pos[6];
    int tree[16];

    init(arr,arr_pos,tree,1,0,5);
    for(int i = 0; i < 16; i++) {
        printf("%d ",tree[i]);
    }
    printf("\n-----------------------");
    printf("\n%d ",sum(tree,1,0,5,1,3));
    printf("\n-----------------------");
    update(tree,arr_pos[3],3);

    printf("\n-----------------------");
    printf("\n%d ",sum(tree,1,0,5,1,3));
    return 0;
}

int init(int *arr, int *arr_pos, int *tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        arr_pos[start] = node;
        printf("%d : %d \n",node,tree[node]);
        return tree[node];
    }
    
    int mid = (start+end)/2;
    tree[node] = init(arr,arr_pos,tree,node*2,start,mid) + init(arr,arr_pos,tree,node*2+1,mid+1,end);
    printf("%d : %d \n",node,tree[node]);
    return tree[node];
}

int sum(int *tree, int node, int start, int end, int left, int right) {
    if (left <= start && end <= right) {
        return tree[node];
    }

    if (end < left || right < start) {
        return 0;
    }

    int s;
    int mid = (start+end)/2;
    s = sum(tree,node*2,start,mid,left,right) + sum(tree,node*2+1,mid+1,end,left,right);
    return s;
}

void update(int *tree, int node, int diff) {
    tree[node] += diff;

    if (node == 1) return;
    int next = node/2;
    update(tree,next,diff);
}