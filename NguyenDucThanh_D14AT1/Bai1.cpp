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

class Single_LL {
public: 
	node *create(ll);
	void insert_begin();
	void insert_last();
	void insert_pos();
	void delete_begin();
	void delete_last();
	void delete_pos();
	void display();
	void search();
	void sort();
	void reverse();
	Single_LL() {
		start = NULL;
	}
};

node *Single_LL :: create(ll n) {
	node *temp, *s;
	temp = new (node);	
	temp -> val = n;
	temp -> next = NULL;
	return temp;
}

void Single_LL :: insert_begin() {
	ll n;
	cout << "Nhap gia tri node can them: ";
	cin >> n;
	node *temp, *p;
	temp = create(n);
	if (start == NULL) {
		start = temp;
		start -> next = NULL;
	}
	else {
		p = start;
		start = temp;
		start -> next = p;
	}
}


void Single_LL :: insert_last() {
	ll n;
	cout << "Nhap gia tri node can them: ";
	cin >> n;
	node *temp, *p;
	temp = create(n);
	p = start;
	if (start == NULL) {
		start = temp;
		start -> next = NULL;
	}
	else {
		while (p -> next != NULL) {
			p = p -> next;
		}
		temp -> next = NULL;
		p -> next = temp;
	}
}

void Single_LL :: insert_pos() {
	ll n, pos, d = 0;
	cout << "Nhap gia tri node can them: ";
	cin >> n;
	cout << endl << "Nhap vi tri can them: ";
	cin >> pos;
	node *temp, *ptr, *s;
	temp = create(n); s = start;
	while (s != NULL) {
		s = s -> next; d++;
	}
	if (pos == 1) {
		if (start == NULL) {
			start = temp;
			start -> next = NULL;
		}
		else {
			ptr = start;
			start = temp;
			start -> next = ptr;
		}
	}
	else if (pos > 1 && pos <= d) {
		s = start;
		FOR(i, 1, pos-1) {
			ptr = s; s = s -> next;
		}
		ptr -> next = temp;
		temp -> next = s;
	}
	else cout << "Vuot qua gioi han!" << endl;
}

void Single_LL :: delete_begin() {
	if (start == NULL) {
		cout << "DSLKD rong. Khong thuc hien duoc!" << endl;
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

void Single_LL :: delete_last() {
	if (start == NULL) {
		cout << "DSLKD rong. Khong thuc hien duoc!" << endl;
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

void Single_LL :: delete_pos() {
	ll pos, d = 0; 
	if (start == NULL) {
		cout << "DSLKD rong. Khong thuc hien duoc!" << endl;
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

void Single_LL :: display() {
	node *temp;
	if (start == NULL) {
		cout << "DSLKD rong!" << endl;
		return;
	}
	temp = start;
	cout << "Noi dung DSLKD: " << endl;
	while (temp != NULL) {
		cout << temp -> val << " -> ";
		temp = temp -> next;
	}
	cout << "NULL" << endl; 
}

void Single_LL :: search() {
	ll n, pos = 0;
	bool flag = false;
	if (start == NULL) {
		cout << "DSLKD rong!" << endl;
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

void Single_LL :: sort() {
	node *ptr, *s;
	ll n;
	if (start == NULL) {
		cout << "DLSKD rong!" << endl;
		return;
	}
	ptr = start;
	while (ptr != NULL) {
		for (s = ptr -> next; s != NULL; s = s -> next) {
			if (ptr -> val > s -> val) {
				n = ptr -> val;
				ptr -> val = s -> val;
				s -> val = n;
			}
		}
		ptr = ptr -> next;
	}
}

void Single_LL :: reverse() {
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
	ll c; Single_LL SLL;
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Khoi tao DSLKD" << endl
			 << "2. Them nut vao ben trai" << endl
			 << "3. Them nut vao ben phai" << endl
			 << "4. Them nut vao vi tri pos" << endl
			 << "5. Loai nut ben trai" << endl
			 << "6. Loai nut ben phai" << endl
			 << "7. Loai nut vi tri pos" << endl
			 << "8. Tim nut co gia tri x" << endl
			 << "9. Duyet DSLKD" << endl 
			 << "10. Sap xep DSLKD" << endl
			 << "11. Dao nguoc DSLKD" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					Single_LL SLL;
					break;
				}
				case 2: {
					SLL.insert_begin();
					break;
				}
				case 3: {
					SLL.insert_last();
					break;
				}
				case 4: {
					SLL.insert_pos();
					break;
				}
				case 5: {
					SLL.delete_begin();
					break;
				}
				case 6: {
					SLL.delete_last();
					break;
				}
				case 7: {
					SLL.delete_pos();
					break;
				}
				case 8: {
					SLL.search();
					break;
				}
				case 9: {
					SLL.display();
					break;
				}
				case 10: {
					SLL.sort();
					break;
				}
				case 11: {
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

