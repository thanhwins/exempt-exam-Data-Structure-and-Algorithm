// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)
using namespace std;
class MaxHeap {
private:
	int *harr;
	int capacity;
	int heap_size;
public:
	MaxHeap() {
		heap_size = 0;
		capacity = MAX;
		harr = new int [MAX];
	}			
	void MaxHeapify(int i);
	int parent(int i) {
		return (i-1)/2;
	}
	int left(int i) {
		return (2*i+1);
	}
	int right(int i) {
		return (2*i+2);
	}
	void insertKey(int k);
	int extractMax();
	void decreaseKey(int i, int new_val);
	int getMax() {
		return harr[0];
	}
	void deleteKey(int i);
	void display();
	void search(int x);
};

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void MaxHeap :: MaxHeapify(int i) {
	int l = left(i), r = right(i), biggest = i;
	if (l < heap_size && harr[l] > harr[i]) biggest = l;
	if (r < heap_size && harr[r] > harr[biggest]) biggest = r;
	if (biggest != i) {
		swap(harr[i], harr[biggest]);
		MaxHeapify(biggest);
	}
}

void MaxHeap :: insertKey(int k) {
	if (heap_size == capacity) {
		cout << "Khong them duoc node!" << endl;
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
	while (i != 0 && harr[parent(i)] < harr[i]) {
		swap (harr[i], harr[parent(i)]);
		i = parent(i);
	}
}

int MaxHeap :: extractMax() {
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1) {
		heap_size--;
		return harr[0];	
	}
	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MaxHeapify(0);
	return root;
}

void MaxHeap :: decreaseKey(int i, int new_val) {
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] < harr[i]) {
		swap(harr[i], harr[parent(i)]);
		i = parent(i);
	}
}

void MaxHeap :: deleteKey(int i) {
	if (i < heap_size) {
		decreaseKey(i, INT_MAX);
		extractMax();
	}
	else cout << "Khong ton tai node" << endl;
}

void MaxHeap :: display() {
	FOR(i, 0, heap_size-1)
		cout << harr[i] << " ";
	cout << endl;
}

void MaxHeap :: search(int x) {
	bool flag = false;
	FOR(i, 0, heap_size - 1) {
		if (harr[i] == x) {
			flag = true;
			cout << "YES" << endl;
			break;
		}
	}
	if (!flag) cout << "NO" << endl;
}

void Menu() {
	ll c; MaxHeap mh;
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Tao node cho Max Heap" << endl
			 << "2. Them node vao Max Heap" << endl
			 << "3. Loai node tren Max Heap" << endl
			 << "4. Tim node tren Max Heap" << endl
			 << "5. Duyet Max Heap" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					int k;
					cout << "Nhap vao gia tri cua node: "; cin >> k;
					mh.insertKey(k);
					break;
				}
				case 2: {
					int k;
					cout << "Nhap vao gia tri cua node: "; cin >> k;
					mh.insertKey(k);
					break;
				}
				case 3: {
					int k;
					cout << "Nhap vao vi tri node muon loai bo: "; cin >> k;
					mh.deleteKey(k);
					break;
				}
				case 4: {
					int x;
					cout << "Nhap vao gia tri cua node: "; cin >> x;
					mh.search(x);
					break;
				}
				case 5: {
					mh.display();
					break;
				}
				case 0: {
					exit(1);
				}
				default: {
					cout << "Khong co chuc nang nay!" << endl;
					break;
				}
			}
	}
}

int main() {
	Menu();
	return 0;
}

