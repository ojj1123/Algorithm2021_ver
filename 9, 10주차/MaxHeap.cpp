#include <bits/stdc++.h>
using namespace std;
#define N 20
//max heap
struct Heap {
	int heap[N];
	int heap_size = 0;
};
void Insert(Heap* h, int item) { // item : inserted value
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
void Delete(Heap* h) {
	int temp = h->heap[(h->heap_size)--]; // 마지막 요소 저장하고 사이즈 줄이기 -> root로 와야함
	int parent = 1;
	int child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1])) {
			child++;
		} // 두개의 자식노드 중 큰 노드의 인덱스를 child 저장
		if (temp > h->heap[child]) break; // 더 큰 자식 노드가 마지막 노드보다 작으면
		h->heap[parent] = h->heap[child]; // 더 큰 자식 노드가 마지막 노드보다 크면
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
}
void printAll(Heap* h) {
	int size = h->heap_size;
	for (int i = 1; i <= size; i++) {
		cout << h->heap[i] << ' ';
	}
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Heap heapData;
	Insert(&heapData, 1);
	Insert(&heapData, 10);
	Insert(&heapData, 8);
	Insert(&heapData, 4);
	Insert(&heapData, 5);
	printAll(&heapData);
	Delete(&heapData);
	printAll(&heapData);
	Delete(&heapData);
	printAll(&heapData);
	Insert(&heapData, 14);
	printAll(&heapData);
}