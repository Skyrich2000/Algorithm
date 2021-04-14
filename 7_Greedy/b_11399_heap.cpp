#include <iostream>

using namespace std;

const int MAX = 1001;
int heap[MAX];

void swap(int a, int b)
{
	int temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void max_heap(int root, int bottom) {
	int max_child;	
	int left_child = root * 2 + 1;
	int right_child = root * 2 + 2;

	if (left_child <= bottom)
	//bottom 값을 통해 leaf node를 판단한다. 무한재귀호출방지.
	//자식노드가 0개가 아닌경우(1개 또는 2개).
	{
		if (left_child == bottom)
		//right_child가 없는 경우. == 자식노드가 1개인 경우.
			max_child = left_child;

		else {
		// 자식 노드가 2개인 경우.
			if (heap[left_child] <= heap[right_child])
				max_child = right_child;
			else max_child = left_child;
		}

		if (heap[root] < heap[max_child]) {
			swap(root, max_child);
			max_heap(max_child, bottom);
			//swap을 하고 나서 하위 서브트리에서 heap 조건 만족하지 않을 수 있기 때문에
			// swap한 max_child가 root인 서브트리를 모두 재귀적으로 재검사, heap화.
		}
	}
}

void heap_sort(int size)
{
	int index;

	for (index = size / 2 - 1; index >= 0; index--)
		// 비정렬된 배열을 heap 형태로 만들어줌.
		//모든 부모-자식간 관계(1세대 차이)에 적용.
		// 완전 이진 트리이기 때문에 사용할 수 있는 수식.
		max_heap(index, size - 1);


	for (index = size - 1; index >= 0; index--)  // 이진탐색트리x.'이진트리', left, right 정렬x. 
	{
		swap(0, index); //0(root)가 최대값.
		max_heap(0, index - 1); //다시 heap화.
	}
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> heap[i];
    }
	heap_sort(N);

    int total = 0;
    int wait = 0;
    for (int i = 0; i < N; i++){
        wait += heap[i];
        total += wait;
    }

    cout << total;

    return 0;
}