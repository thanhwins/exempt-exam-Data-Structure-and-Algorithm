// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

ll size = 0;

class Circular_Queue {
	private:
		char node[MAX];
		ll front, rear;
	public:
		Circular_Queue() {
			front = rear = -1;
		}
		bool Empty();
		bool Full();
		void Push(char);
		char Top();
		void Pop();
		void Display();
};
bool Circular_Queue :: Empty() {
	return (front == -1);
}

bool Circular_Queue :: Full() {
	return (front == 0 && rear == MAX-1 || front == rear + 1);
}

void Circular_Queue :: Push(char n) {
	if (Full()) {
		cout << "Circular queue day!" << endl;
		return;
	}
	if (front == -1) {
		front = rear = 0;
	}
	else {
		if (rear == MAX - 1) rear = 0;
		else rear++;
	}
	node[rear] = n; size++;
}

void Circular_Queue :: Pop() {
	if (Empty()) {
		cout << "Circular queue rong!" << endl;
		return;
	}
	cout << node[front] << endl;
	if (front == rear) front = rear = -1;
	else {
		if (front == MAX - 1) front = 0;
		else front++;
	}
	size--;
}

void Circular_Queue :: Display() {
	if (Empty()) {
		cout << "Circular queue rong!" << endl;
		return;
	}
	ll front_pos = front, rear_pos = rear;
	cout << "Circular queue: ";
	if (front_pos <= rear_pos) {
		while (front_pos <= rear_pos) {
			cout << node[front_pos] << " ";
			front_pos++;
		}
	}
	else {
		while (front_pos <= MAX - 1) {
			cout << node[front_pos] << " ";
			front_pos++;
		}
		front_pos = 0;
		while (front_pos <= rear_pos) {
			cout << node[front_pos] << " ";
			front_pos++;
		}
	}
	cout << endl;
}

void Menu() {
	ll c; 
	Circular_Queue cq; 
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Kiem tra tinh rong cua hang doi vong" << endl
			 << "2. Kiem tra tinh day cua hang doi vong" << endl
			 << "3. Lay phan tu o dau hang doi vong" << endl
			 << "4. Lay kich co cua hang doi vong" << endl
			 << "5. Dua phan tu vao hang doi vong" << endl
			 << "6. Hien thi Circular queue" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				if (cq.Empty()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 2: {
				if (cq.Full()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 3: {
				if (!cq.Empty()) {
					cq.Pop();
				}
				else cout << "Circular queue rong!" << endl;
				break;
			}
			case 4: {
				cout << size << endl;
				break;
			}
			case 5: {
				char n;
				cout << "Nhap phan tu muon them: ";
				cin >> n;
				cq.Push(n);
				break;
			}
			case 6: {
				cq.Display();
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

