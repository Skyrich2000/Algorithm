#include <iostream>

using namespace std;

void selection_sort(int list[], int n){
    int least, temp;

    // 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1) 만큼 반복한다.
    for(int i=0; i<n-1; i++){ // i 가 맨앞
        least = i;

        // 최솟값을 탐색한다.
        for(int j=i+1; j<n; j++){
            if(list[j] < list[least]) least = j;
        }

        // 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
        if(i != least){
            temp = list[i];
            list[i] = list[least];
            list[least] = temp;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* list = new int[n];
    for(int i=0; i<n; i++) cin >> list[i];

    selection_sort(list, n);

    for(int i=0; i<n; i++) cout << list[i] << endl;

    delete list;
    return 0;
}