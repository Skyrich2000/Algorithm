#include <iostream>

using namespace std;

void merge(int* arr, int p, int q, int r) {
	int i, j, k;
	int temp[1000];
	i = p;
	k = 0;
	j = q + 1;
	while (i <= q && j <= r) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= q) {
		temp[k++] = arr[i++];
	}
	while (j <= r) {
		temp[k++] = arr[j++];
	}
	for (i = p; i <= r; i++) {
		arr[i] = temp[i - p];
	}
}

void mergeSort(int* arr, int p, int r)
{
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

int main() {
    int N;
    cin >> N;

    int* time = new int[N];
    for (int i = 0; i < N; i++){
        cin >> time[i];
    }
    mergeSort(time, 0, N-1);

    int total = 0;
    int wait = 0;
    for (int i = 0; i < N; i++){
        wait += time[i];
        total += wait;
    }

    cout << total;

    delete time;
    return 0;
}