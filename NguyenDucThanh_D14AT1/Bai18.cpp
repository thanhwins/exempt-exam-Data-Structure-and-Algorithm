// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

struct node {
	ll val;
	node *next, *prev;
} *head, *tail;
class DQueue {
	public: 
		ll top1, top2;
		void insert_front();
		void insert_last();
		void del_front();
		void del_last();
		void display_front();
		void display_last();
		ll get_front();
		ll get_last();
		bool Empty();
		bool Full();
		DQueue() {
			top1 = top2 = 0;
			head = tail = NULL;
		}
};

bool DQueue :: Empty() {
	if (top1 + top2 <= 0) return true;
	return false;
}

bool DQueue :: Full() {
	if (top1 + top2 >= 50) return true;
	return false;
}

void DQueue :: insert_front() {
	if (Full()) {
		cout << "Tran DQueue!" << endl;
		return;
	}
	node *temp; 
	ll x;
	cout << "Nhap gia tri phan tu can them: ";
	cin >> x;
	if (Empty()) {
		head = new (node);
		head -> val = x;
		head -> next = NULL;
		head -> prev = NULL;
		tail = head;
		top1++;
	}
	else {
		temp = new (node);
		temp -> val = x;
		temp -> next = head;
		temp -> prev = NULL;
		head -> prev = temp;
		head = temp;
		top1++;
	}
}

void DQueue :: insert_last() {
	if (Full()) {
		cout << "Tran DQueue!" << endl;
		return;
	}
	node *temp; 
	ll x;
	cout << "Nhap gia tri phan tu can them: ";
	cin >> x;
	if (Empty()) {
		head = new (node);
		head -> val = x;
		head -> next = NULL;
		head -> prev = NULL;
		tail = head;
		top2++;
	}
	else {
		temp = new (node);
		temp -> val = x;
		temp -> next = NULL;
		temp -> prev = tail;
		tail -> next = temp;
		tail = temp;
		top2++;
	}
}

void DQueue :: del_front() {
	if (Empty()) {
		cout << "DQueue rong!" << endl;
		return;
	}
	node *temp = head;
	head = head -> next;
	head -> prev = NULL;
	top1--;
	free(temp);
}

void DQueue :: del_last() {
	if (Empty()) {
		cout << "DQueue rong!" << endl;
		return;
	}
	node *temp = tail;
	tail = tail -> prev;
	tail -> next = NULL;
	top2--;
	free(temp);
}

void DQueue :: display_front() {
	if (Empty()) {
		cout << "DQueue rong!" << endl;
		return;
	}
	node *temp = head;
	while (temp != NULL) {
		cout << temp -> val << " ";
		temp = temp -> next;
	}
}

void DQueue :: display_last() {
	if (Empty()) {
		cout << "DQueue rong!" << endl;
		return;
	}
	node *temp = tail;
	while (temp != NULL) {
		cout << temp -> val << " ";
		temp = temp -> prev;
	}
}

ll DQueue :: get_front() {
	return head -> val;
}

ll DQueue :: get_last() {
	return tail -> val;
}

void Menu() {
	ll c; 
	DQueue dq;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Kiem tra tinh rong cua DQueue" << endl
			 << "2. Kiem tra tinh day cua DQueue" << endl
			 << "3. Them node vao dau truoc cua DQueue" << endl
			 << "4. Them node vao dau sau cua DQueue" << endl
			 << "5. Loai nut o dau truoc cua DQueue" << endl
			 << "6. Loai nut o dau sau cua DQueue" << endl
			 << "7. Nhan nut o dau DQueue" << endl
			 << "8. Nhan nut o cuoi DQueue" << endl
			 << "9. Hien thi DQueue bat dau tu dau truoc" << endl
			 << "10. Hien thi DQueue bat dau tu dau sau" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				if (dq.Empty()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 2: {
				if (dq.Full()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 3: {
				if (dq.Full()) {
					cout << "Tran DQueue!" << endl;
				}
				dq.insert_front();
				break;
			}
			case 4: {
				if (dq.Full()) {
					cout << "Tran DQueue!" << endl;
				}
				dq.insert_last();
				break;
			}
			case 5: {
				dq.del_front();
				break;
				
			}
			case 6: {
				dq.del_last();
				break;
			}
			case 7: {
				if (dq.Empty()) {
					cout << "Dqueue rong!" << endl;
				}
				else cout << dq.get_front();
				break;
			}
			case 8: {
				if (dq.Empty()) {
					cout << "Dqueue rong!" << endl;
				}
				else cout << dq.get_last();
				break;
			}
			case 9: {
				dq.display_front();
				break;
			}
			case 10: {
				dq.display_last();
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

