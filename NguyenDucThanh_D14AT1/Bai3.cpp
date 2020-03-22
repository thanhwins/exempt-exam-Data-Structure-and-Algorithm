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

node *Sorted_LL :: create(ll n) {
	node *temp;
	temp = new (node);
	temp -> val = n;
	temp -> next = NULL;
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
	else {
		p = start;
		if (p -> val > n) {
			temp -> next = p;
			start = temp;
			return;
		}
		while (p -> next != NULL && p -> val <= n) {
			p = p -> next;
		}
		temp -> next = p -> next;
		p -> next = temp;
	}
}

void Sorted_LL :: delete_begin() {
	if (start == NULL) {
		cout << "DSLKDSX rong. Khong thuc hien duoc!" << endl;
		return;
	}
	else {
		node *s;
		s = start;
		start = s -> next;
		s -> next = NULL;
		free(s);
	}
}

void Sorted_LL :: delete_last() {
	if (start == NULL) {
		cout << "DSLKDSX rong. Khong thuc hien duoc!" << endl;
		return;
	}
	else {
		ll d = 0;
		node *s, *temp;
		s = start;
		while (s != NULL) {
			s = s -> next; d++; 
		}
		s = start;
		FOR(i, 1, d-1) {
			temp = s;
			s = s -> next;
		}
		temp -> next = s -> next;
		free(s);
	}
}

void Sorted_LL :: delete_pos() {
	ll pos, d = 0; 
	if (start == NULL) {
		cout << "DSLKDSX rong. Khong thuc hien duoc!" << endl;
		return;
	}
	else {
		node *ptr, *s, *temp; s = start; ptr = start;
		cout << "Nhap vi tri node muon loai bo: "; cin >> pos;
		while (s != NULL) {
			s = s -> next; d++; 
		}
		if (pos == 1) {
			start = ptr -> next;
			ptr -> next = NULL;
			free(ptr);
		}
		else if (pos > 1 && pos <= d) {
			temp = start;
			FOR(i, 1, pos-1) {
				ptr = temp;
				temp = temp -> next;
			}
			ptr -> next = temp -> next;
			free(temp);
		}
		else cout << "Vi tri ngoai danh sach!" << endl;
	}
}

void Sorted_LL :: display() {
	node *temp;
	if (start == NULL) {
		cout << "DSLKDSX rong!" << endl;
		return;
	}
	temp = start;
	cout << "Noi dung DSLKDSX: " << endl;
	while (temp != NULL) {
		cout << temp -> val << " -> ";
		temp = temp -> next;
	}
	cout << "NULL" << endl; 
}

void Sorted_LL :: search() {
	ll n, pos = 0;
	bool flag = false;
	if (start == NULL) {
		cout << "DSLKDSX rong!" << endl;
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
	node *ptr1, *ptr2, *ptr3;
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
	ptr3 = ptr2 -> next;
	ptr1 -> next = NULL;
	ptr2 -> next = ptr1;
	while (ptr3 != NULL) {
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr3 -> next;
		ptr2 -> next = ptr1;
	}
	start = ptr2;
}

void Menu() {
	ll c; Sorted_LL SLL;
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Khoi tao DSLKDSX" << endl
			 << "2. Them nut vao dau DSLKDSX" << endl
			 << "3. Loai nut dau tien" << endl
			 << "4. Loai nut cuoi cung" << endl
			 << "5. Loai nut o vi tri pos" << endl
			 << "6. Tim nut co gia tri x" << endl
			 << "7. Duyet DSLKDSX" << endl 
			 << "8. Dao nguoc DSLKDSX" << endl
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

