// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

ll n, size = 0;
struct node {
	ll val, priority;
	node *next;
};

class Priority_Queue {
	private:
		node *front;
	public:
		Priority_Queue() {
			front = NULL;
		}
		bool Empty();
		bool Full();
		void Push(ll, ll);
		void Pop();
		void Display();
};

bool Priority_Queue :: Empty() {
	if (front == NULL) return true;
	return false;
}

bool Priority_Queue :: Full() {
	if (size == n) return true;
	return false;
}

void Priority_Queue :: Push(ll x, ll pri) {
	node *temp, *q;
	temp = new (node);
	temp -> val = x;
	temp -> priority = pri;
	temp -> next = NULL;
	if (front == NULL || front -> priority > pri) {
		temp -> next = front;
		front = temp;
	} 
	else {
		q = front;
		while (q -> next != NULL && q -> next -> priority <= pri) {
			q = q -> next;
		}
		temp -> next = q -> next;
		q -> next = temp;
	}
	size++;
}

void Priority_Queue :: Pop() {
	if (Empty()) {
		cout << "Priority queue rong!" << endl;
		return;
	}
	node *temp = front;
	cout << temp -> val << endl;
	front = front -> next;
	free(temp);
	size--;
}

void Priority_Queue :: Display() {
	if (Empty()) {
		cout << "Priority queue rong!" << endl;
		return;
	}
	node *ptr = front;
	cout << "Priority queue: " << endl;
	while (ptr != NULL) {
		cout << setw(8) << ptr -> val << "(" << ptr -> priority << ")\n";
		ptr = ptr -> next;
	}
	cout << endl;
}

void Menu() {
	ll c; 
	cout << "Nhap so phan tu toi da cua Priority queue: "; 
	cin >> n; 
	cout << endl; 
	Priority_Queue prq;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Kiem tra tinh rong cua hang doi uu tien" << endl
			 << "2. Kiem tra tinh day cua hang doi uu tien" << endl
			 << "3. Lay phan tu o dau hang doi uu tien" << endl
			 << "4. Lay kich co cua hang doi uu tien" << endl
			 << "5. Dua phan tu vao hang doi uu tien" << endl
			 << "6. Hien thi Queue" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				if (prq.Empty()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 2: {
				if (prq.Full()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 3: {
				prq.Pop();
				break;
			}
			case 4: {
				cout << size << endl;
				break;
			}
			case 5: {
				if (prq.
				Full()) {
					cout << "Tran priority queue!" << endl;
					break;
				}
				ll n, pri;
				cout << "Nhap phan tu muon them: ";
				cin >> n;
				cout << "\nNhap do uu tien: ";
				cin >> pri;
				prq.Push(n, pri);
				break;
			}
			case 6: {
				prq.Display();
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

