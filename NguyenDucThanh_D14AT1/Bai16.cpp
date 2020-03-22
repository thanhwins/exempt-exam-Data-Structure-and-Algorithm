/// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

using namespace std;

ll n, size = 0;
struct node {
	ll val;
	node *next;
} *front = NULL, *rear = NULL, *p = NULL, *np = NULL;

bool Empty() {
	if (front == NULL ) return true;
	return false;
}

bool Full() {
	if (size == n) return true;
	return false;
}

void Push(ll x) {
	if (Full()) cout << "Tran Circular queue!" << endl;
	else {
		np = new (node);
   		np -> val = x;
   		np -> next = NULL;
   		if (front == NULL) {
       	    front = rear = np;
       		rear -> next = front;
    	}
    	else {
        	rear -> next = np;
        	rear = rear -> next;;
        	rear -> next = front;
    	}
    	size++;
	}
}

ll Top() {
	return front -> val;
}

void Pop() {
	if (front == NULL) {
		cout << "Circular queue rong!" << endl;
		return;
	}
	if (front -> next == rear -> next) {
		front = rear = NULL;
	}
	else {
		node *p = front;
		front = front -> next;
		free(p);
		rear -> next = front;
	}
	size--;
}

void Display() {
	if (front == NULL) cout << "Circular queue rong!" << endl;
	else {
		node *q = front;
		cout << "Circular queue: ";
		cout << q -> val << " ";
		while (q -> next != front) {
			q = q -> next;
			cout << q -> val << " "; 
		}
	}
}

void Menu() {
	ll c; 
	cout << "Nhap so phan tu toi da cua Circular Queue: "; 
	cin >> n; 
	cout << endl; 
	
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Kiem tra tinh rong cua hang doi vong" << endl
			 << "2. Kiem tra tinh day cua hang doi vong" << endl
			 << "3. Lay phan tu o dau hang doi vong" << endl
			 << "4. Lay kich co cua hang doi vong" << endl
			 << "5. Dua phan tu vao hang doi vong" << endl
			 << "6. Hien thi Queue" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				if (Empty()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 2: {
				if (Full()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 3: {
				if (!Empty()) {
					cout << Top() << endl;
					Pop();
				}
				else cout << "Circular queue rong!" << endl;
				break;
			}
			case 4: {
				cout << size << endl;
				break;
			}
			case 5: {
				ll n;
				cout << "Nhap phan tu muon them: ";
				cin >> n;
				Push(n);
				break;
			}
			case 6: {
				Display();
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
