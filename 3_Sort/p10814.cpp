#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;

struct Person{
    int age;
    string name;
    int join;
};

void merge(Person* arr, int p, int q, int r) {
	int i, j, k;
	Person temp[100000];
	i = p;
	k = 0;
	j = q + 1;
	while (i <= q && j <= r) {
		if (arr[i].age < arr[j].age) {
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

void mergeSort(Person* arr, int p, int r)
{
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

bool cmp(Person u, Person v){
    if(u.age < v.age)
        return true;
    return false;
}

int main() {
    cin >> N;

    Person* user = new Person[N];

    for (int i = 0; i < N; i++){
        cin >> user[i].age >> user[i].name;
    }

    stable_sort(user, user+N, cmp);
    mergeSort(user, 0, N-1);

    for (int i = 0; i < N; i++)
        cout << user[i].age << " "<< user[i].name << "\n";

    delete user;
    return 0;
}