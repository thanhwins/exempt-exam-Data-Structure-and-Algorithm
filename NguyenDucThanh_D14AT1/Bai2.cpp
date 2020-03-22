// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)
using namespace std;
struct node {
	ll val;
	node *next;
} *last;

class Circular_LL {
public: 
	node *create(ll);
	void insert_begin();
	void insert_pos();
	void delete_pos();
	void display();
	void search();
	void sort();
	void reverse();
	Circular_LL() {
		last = NULL;
	}
};

node *Circular_LL :: create(ll n) {
	node *temp, *s;
	temp = new (node);
	temp -> val = n;
	temp -> next = NULL;
	return temp;
}

void Circular_LL :: insert_begin() {
	ll n;
	cout << "Nhap gia tri node can them: ";
	cin >> n;
	node *temp, *p;
	temp = create(n);
	if (last == NULL) {
		last = temp;
		temp -> next = last;
	}
	else {
		temp -> next = last -> next;
		last -> next = temp;
		last = temp;
	}
}

void Circular_LL :: insert_pos() {
	ll n, pos, d = 0;
	cout << "Nhap gia tri node can them: ";
	cin >> n;
	cout << endl << "Nhap vi tri can them: ";
	cin >> pos;
	node *temp, *ptr, *s;
	temp = create(n); s = last -> next;
	if (pos == 1) {
		if (last == NULL) {
			last = temp;
			temp -> next = last;
		}
		else {
			temp -> next = last -> next;
			last -> next = temp;
			last = temp;
		}
	}
	else {
		FOR(i, 1, pos-1) {
			s = s-> next;
			if (s == last -> next) {
				cout << "Vuot qua gioi han!" << endl;
				return;
			}
		}
		temp -> next = last -> next;
		s -> next = temp;
		if (s == last) {
			last = temp;
		}
	}
}

void Circular_LL :: delete_pos() {
	ll n;
	if (last == NULL) {
		cout << "Danh sach rong! Khong co gi de loai bo!" << endl;
		return;
	}
	cout << "Nhap nut muon loai bo: "; cin >> n;
	node *temp, *s;
	s = last -> next;
	if (last -> next == last && last -> val == n) {
		temp = last;
		last = NULL;
		free(temp);
		return;
	}
	if (s -> val == n) {
		temp = s;
		last -> next = s -> next;
		free(temp);
		return;
	}
	while (s -> next != NULL) {
		if (s -> next -> val == n) {
			temp = s -> next;
			s -> next = temp -> next;
			free(temp);
			return;
		}
		s = s -> next;
	}
	if (s -> next -> val == n) {
		temp = s -> next;
		s -> next = last -> next;
		free(temp);
		last = s;
		return;
	}
	cout << "Nut ban muon loai khong ton tai trong danh sach!" << endl;
}

void Circular_LL :: display() {
	node *temp;
	if (last == NULL) {
		cout << "DKLKDV rong!" << endl;
		return;
	}
	temp = last -> next;
	cout << "Noi dung DKLKDV: " << endl;
	while (temp != last) {
		cout << temp -> val << " -> ";
		temp = temp -> next;
	}
	cout << temp -> val<< endl; 
}

void Circular_LL :: search() {
	ll n, pos = 0;
	if (last == NULL) {
		cout << "DSLKDV rong!" << endl;
		return;
	}
	cout << "Noi dung node can tim: "; cin >> n;
	node *s; s = last -> next;
	while (s != last) {
		pos++;
		if (s -> val == n) {
			cout << endl << "Tim thay " << n << " tai vi tri " << pos << endl;
			return;
		}
		s = s -> next;
	}
	if (s -> val == n) {
		pos++;
		cout << endl << "Tim thay " << n << " tai vi tri " << pos << endl;
		return;
	}
	cout << "Khong tim thay node can tim!" << endl;
}

void Circular_LL :: sort() {
	node *ptr, *s;
	ll n;
	if (last == NULL) {
		cout << "DLSKD rong!" << endl;
		return;
	}
	ptr = last -> next;
	while (ptr != last) {
		s = ptr -> next;
		while (s != last -> next) {
			if (s != last -> next) {
				if (ptr -> val > s -> val) {
					n = s -> val;
					s -> val = ptr -> val;
					ptr -> val = n;
				}
			}
			else break;
			s = s -> next;
		}
		ptr = ptr -> next;
	}
}

void Menu() {
	ll c; Circular_LL CLL;
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Khoi tao DSLKDV" << endl
			 << "2. Them nut dau tien cho DSLKDV" << endl
			 << "3. Them nut vao sau vi tri pos" << endl
			 << "4. Loai nut trong DSLKDV" << endl
			 << "5. Tim nut co gia tri x" << endl
			 << "6. Duyet DSLKDV" << endl 
			 << "7. Sap xep DSLKV" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					Circular_LL CLL;
					break;
				}
				case 2: {
					CLL.insert_begin();
					break;
				}
				case 3: {
					CLL.insert_pos();
					break;
				}
				case 4: {
					CLL.delete_pos();
					break;
				}
				case 5: {
					CLL.search();
					break;
				}
				case 6: {
					CLL.display();
					break;
				}
				case 7: {
					CLL.sort();
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

