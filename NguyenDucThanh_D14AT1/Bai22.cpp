// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;
class MinHeap {
private:
	int *harr;
	int capacity;
	int heap_size;
public:
	MinHeap() {
		heap_size = 0;
		capacity = MAX;
		harr = new int [MAX];
	}			
	void MinHeapify(int i);
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
	int extractMin();
	void decreaseKey(int i, int new_val);
	int getMin() {
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

void MinHeap :: MinHeapify(int i) {
	int l = left(i), r = right(i), smallest = i;
	if (l < heap_size && harr[l] < harr[i]) smallest = l;
	if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
	if (smallest != i) {
		swap(harr[i], harr[smallest]);
		MinHeapify(smallest);
	}
}

void MinHeap :: insertKey(int k) {
	if (heap_size == capacity) {
		cout << "Khong them duoc node!" << endl;
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap (harr[i], harr[parent(i)]);
		i = parent(i);
	}
}

int MinHeap :: extractMin() {
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1) {
		heap_size--;
		return harr[0];	
	}
	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);
	return root;
}

void MinHeap :: decreaseKey(int i, int new_val) {
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap(harr[i], harr[parent(i)]);
		i = parent(i);
	}
}

void MinHeap :: deleteKey(int i) {
	decreaseKey(i, INT_MIN);
	extractMin();
}

void MinHeap :: display() {
	FOR(i, 0, heap_size-1)
		cout << harr[i] << " ";
	cout << endl;
}

void MinHeap :: search(int x) {
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
	ll c; MinHeap mh;
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Tao node cho Min Heap" << endl
			 << "2. Them node vao Min Heap" << endl
			 << "3. Loai node tren Min Heap" << endl
			 << "4. Tim node tren Min Heap" << endl
			 << "5. Duyet Min Heap" << endl
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

