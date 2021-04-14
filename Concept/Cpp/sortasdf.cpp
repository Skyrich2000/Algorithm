#include <iostream>

using namespace std;

void bubble_sort(int list[], int n){
    int temp;

    for(int i=n-1; i>0; i--) {
        // 0 ~ (i-1)까지 반복
        for(int j=0; j<i; j++) {
            // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
            if(list[j] > list[j+1]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* list = new int[n];
    for(int i=0; i<n; i++) cin >> list[i];

    bubble_sort(list, n);

    for(int i=0; i<n; i++) cout << list[i] << endl;

    delete list;
    return 0;
}