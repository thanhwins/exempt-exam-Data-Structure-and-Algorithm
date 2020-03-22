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
} *start, *last;

ll dem = 0;

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
		start = NULL;
		last = NULL;
	}
};

node *Circular_LL :: create(ll n) {
	dem++;
	node *temp, *s;
	temp = new (node);
	temp -> val = n;
	temp -> next = NULL;
	temp -> prev = NULL;
	return temp;
}

void Circular_LL :: insert_begin() {
	ll n;
	cout << "Nhap gia tri node can them: ";
	cin >> n;
	node *temp, *p;
	temp = create(n);
	if (start == last && last == NULL) {
		start = last = temp;
		start -> next = last -> next = NULL;
		start -> prev = last -> prev = NULL;
	}
	else {
		temp -> next = start;
		start -> prev = temp;
		last -> next = temp;
		temp -> prev = last;
		start = temp;
	}
}

void Circular_LL :: insert_pos() {
	ll n, pos, d = 0;
	cout << "Nhap gia tri node can them: ";
	cin >> n;
	cout << endl << "Nhap vi tri can them: ";
	cin >> pos;
	node *temp, *ptr, *s;
	temp = create(n); 
	if (pos == 1) {
		if (start == last && last == NULL) {
			start = last = temp;
			start -> next = last -> next = NULL;
			start -> prev = last -> prev = NULL;
		}
		else {
			temp -> next = start;
			start -> prev = temp;
			last -> next = temp;
			temp -> prev = last;
			start = temp;
		}
	}
	else {
		if (dem < pos) {
			cout << "Vuot qua gioi han!" << endl;
			return;
		}
		s = start;
		FOR(i, 1, dem) {
			ptr = s;
			s = s -> next;
			if (i == pos - 1) {
				ptr -> next = temp;
				temp -> prev = ptr;
				temp -> next = s;
				s -> prev = temp;
				break;
			}
		}
	}
}

void Circular_LL :: delete_pos() {
	ll pos;
	if (start == last && last == NULL) {
		cout << "Danh sach rong! Khong co gi de loai bo!" << endl;
		return;
	}
	cout << "Nhap vi tri nut muon loai bo: "; cin >> pos;
	if (dem < pos) {
		cout << "Nut ban muon loai khong ton tai trong danh sach!" << endl;
		return;
	}
	node *temp, *s, *ptr;
	s = start;
	if (pos == 1) {
		dem--;
		last -> next = s -> next;
		s -> next -> prev = last;
		start = s -> next;
		free(s);
		return;
	}
	FOR(i, 1, pos-1) {
		s = s -> next;
		ptr = s -> prev;
	}
	ptr -> next = s -> next;
	s -> next -> prev = ptr;
	if (pos == dem) last = ptr;
	dem--;
	s -> next = s -> prev = NULL;
	free(s);
}

void Circular_LL :: display() {
	node *temp;
	if (start == last && last == NULL) {
		cout << "DKLKDV rong!" << endl;
		return;
	}
	temp = start;
	cout << "Noi dung DKLKDV: " << endl;
	FOR(i, 1, dem-1) {
		cout << temp -> val << " <-> ";
		temp = temp -> next;
	}
	cout << temp -> val<< endl; 
}

void Circular_LL :: search() {
	ll n, pos = 0;
	if (start == last && last == NULL) {
		cout << "DSLKKV rong!" << endl;
		return;
	}
	cout << "Noi dung node can tim: "; cin >> n;
	node *s; s = start;
	FOR(i, 1, dem-1) {
		pos++;
		if (s -> val == n) {
			cout << endl << "Tim thay " << n << " tai vi tri " << pos << endl;
			return;
		}
		s = s -> next;
	}
	cout << "Khong tim thay node can tim!" << endl;
}

void Circular_LL :: sort() {
	node *ptr, *s, *temp;
	ll n;
	if (start == last && last == NULL) {
		cout << "DLSKD rong!" << endl;
		return;
	}
	s = start;
	FOR(i, 1, dem-1) {
		temp = s -> next;
		while (temp != start) {
			if (s -> val > temp -> val) {
				n = s -> val;
				s -> val = temp -> val;
				temp -> val = n;
			}
			temp = temp -> next;
		}
		s = s -> next;
	}
}

void Menu() {
	ll c; Circular_LL CLL;
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Khoi tao DSLKKV" << endl
			 << "2. Them nut dau tien cho DSLKKV" << endl
			 << "3. Them nut vao sau vi tri pos" << endl
			 << "4. Loai nut trong DSLKKV" << endl
			 << "5. Tim nut co gia tri x" << endl
			 << "6. Duyet DSLKKV" << endl 
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

