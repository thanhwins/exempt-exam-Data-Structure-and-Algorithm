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
} *start;

class Sorted_LL {
public: 
	node *create(ll);
	void insert_begin();
	void delete_begin();
	void delete_last();
	void delete_pos();
	void display();
	void search();
	void reverse();
	Sorted_LL() {
		start = NULL;
	}
};

ll dem = 0;

node *Sorted_LL :: create(ll n) {
	node *temp, *s;
	dem++;
	temp = new (node);
	temp -> val = n;
	temp -> next = temp -> prev = NULL;
	return temp;
}

void Sorted_LL :: insert_begin() {
	ll n;
	cout << "Nhap gia tri node can them: ";
	cin >> n;
	node *temp, *p;
	temp = create(n);
	if (start == NULL) {
		temp -> next = start;
		start = temp;
	}
	else if (n < start -> val) {
		temp -> next = start;
		start -> prev = temp;
		start = temp;
	}
	else {
		node *q;
		p = start;
		while (p -> next != NULL && p -> val <= n) {
			q = p;
			p = p -> next;
		}
		if (p -> val > n) {
			p -> prev = temp;
			temp -> next = p;
			temp -> prev = q;
			q -> next = temp;
		}
		else {
			p -> next = temp;
			temp -> prev = p;
		}
	}
}

void Sorted_LL :: delete_begin() {
	if (start == NULL) {
		cout << "DSLKKSX rong. Khong thuc hien duoc!" << endl;
		return;
	}
	else {
		node *s;
		s = start;
		start = s -> next;
		start -> prev = NULL;
		s -> next = NULL;
		free(s);
		dem--;
	}
}

void Sorted_LL :: delete_last() {
	if (start == NULL) {
		cout << "DSLKKSX rong. Khong thuc hien duoc!" << endl;
		return;
	}
	else {
		node *s, *temp;
		s = start;
		FOR(i, 1, dem-1) {
			temp = s;
			s = s -> next;
		}
		temp -> next = s -> next;
		s -> prev = NULL;
		free(s);
		dem--;
	}
}

void Sorted_LL :: delete_pos() {
	ll pos; 
	if (start == NULL) {
		cout << "DSLKKSX rong. Khong thuc hien duoc!" << endl;
		return;
	}
	else {
		node *ptr, *s, *temp; ptr = start;
		cout << "Nhap vi tri node muon loai bo: "; cin >> pos;
		if (pos == 1) {
			start = ptr -> next;
			start -> prev = NULL;
			ptr -> next = NULL;
			free(ptr);
			dem--;
		}
		else if (pos == dem) {
			temp = start;
			FOR(i, 1, pos-1) {
				s = temp;
				temp = temp -> next;
			}
			s -> next = NULL;
			temp -> prev = NULL;
			free(temp);
			dem--;
		}
		else if (pos > 1 && pos < dem) {
			temp = start;
			FOR(i, 1, pos-1) {
				s = temp;
				temp = temp -> next;
			}
			s -> next = temp -> next;
			temp -> next -> prev = s;
			temp -> prev = NULL;
			free(temp);
			dem--;
		}
		else cout << "Vi tri ngoai danh sach!" << endl;
	}
}

void Sorted_LL :: display() {
	node *temp;
	if (start == NULL) {
		cout << "DSLKKSX rong!" << endl;
		return;
	}
	temp = start;
	cout << "Noi dung DSLKKSX: " << endl;
	while (temp != NULL) {
		cout << temp -> val << " <-> ";
		temp = temp -> next;
	}
	cout << "NULL" << endl; 
}

void Sorted_LL :: search() {
	ll n, pos = 0;
	bool flag = false;
	if (start == NULL) {
		cout << "DSLKKSX rong!" << endl;
		return;
	}
	cout << "Noi dung node can tim: "; cin >> n;
	node *s; s = start;
	while (s != NULL) {
		pos++;
		if (s -> val == n) {
			flag = true;
			cout << endl << "Tim thay " << n << " tai vi tri " << pos << endl;
		}
		s = s -> next;
	}
	if (!flag) cout << "Khong tim thay gia tri can tim!" << endl;
}

void Sorted_LL :: reverse() {
	node *ptr1, *ptr2;
	if (start == NULL) {
		cout << "DSLKD rong!" << endl;
		return;
	}
	if (start -> next == NULL) {
		cout << "Dao nguoc la chinh no!" << endl;
		return;
	}
	ptr1 = start;
	ptr2 = ptr1 -> next;
	ptr1 -> next = NULL;
	ptr1 -> prev = ptr2;
	while (ptr2 != NULL) {
		ptr2 -> prev = ptr2 -> next;
		ptr2 -> next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2 -> prev;
	}
	start = ptr1;
}

void Menu() {
	ll c; Sorted_LL SLL;
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Khoi tao DSLKKSX" << endl
			 << "2. Them nut vao dau DSLKKSX" << endl
			 << "3. Loai nut dau tien" << endl
			 << "4. Loai nut cuoi cung" << endl
			 << "5. Loai nut o vi tri pos" << endl
			 << "6. Tim nut co gia tri x" << endl
			 << "7. Duyet DSLKKSX" << endl 
			 << "8. Dao nguoc DSLKKSX" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					Sorted_LL SLL;
					break;
				}
				case 2: {
					SLL.insert_begin();
					break;
				}
				case 3: {
					SLL.delete_begin();
					break;
				}
				case 4: {
					SLL.delete_last();
					break;
				}
				case 5: {
					SLL.delete_pos();
					break;
				}
				case 6: {
					SLL.search();
					break;
				}
				case 7: {
					SLL.display();
					break;
				}
				case 8: {
					SLL.reverse();
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

