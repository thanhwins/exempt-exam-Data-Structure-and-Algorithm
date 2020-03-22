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
	node *prev;
} *start;

class Double_LL {
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
	Double_LL() {
		start = NULL;
	}
};

node *Double_LL :: create(ll n) {
	node *temp, *s;
	temp = new (node);	
	temp -> val = n;
	temp -> next = NULL;
	return temp;
}

void Double_LL :: insert_begin() {
	ll n;
	cout << "Nhap gia tri node can them: ";
	cin >> n;
	node *temp, *p;
	temp = create(n);
	if (start == NULL) {
		temp -> prev = NULL;
		start = temp;
	}
	else {
		p = start;
		p -> prev = temp;
		start = temp;
		start -> next = p;
	}
}


void Double_LL :: insert_last() {
	ll n;
	cout << "Nhap gia tri node can them: ";
	cin >> n;
	node *temp, *p;
	temp = create(n);
	p = start;
	if (start == NULL) {
		temp -> prev = NULL;
		start = temp;
	}
	else {
		while (p -> next != NULL) {
			p = p -> next;
		}
		p -> next = temp;
		temp -> prev = p;
	}
}

void Double_LL :: insert_pos() {
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
			temp -> prev = NULL;
			start = temp;
		}
		else {
			ptr = start;
			ptr -> prev = temp;
			start = temp;
			start -> next = ptr;
		}
	}
	else if (pos > 1 && pos <= d) {
		s = start;
		FOR(i, 1, pos-1) {
			ptr = s; s = s -> next;
		}
		temp -> next = ptr -> next;
		temp -> next -> prev = temp;
		ptr -> next = temp;
		temp -> prev = ptr;
	}
	else cout << "Vuot qua gioi han!" << endl;
}

void Double_LL :: delete_begin() {
	if (start == NULL) {
		cout << "DSLKK rong. Khong thuc hien duoc!" << endl;
		return;
	}
	else {
		node *s;
		s = start;
		start = s -> next;
		start -> prev = NULL;
		s -> next = NULL;
		s -> prev = NULL;
		free(s);
	}
}

void Double_LL :: delete_last() {
	if (start == NULL) {
		cout << "DSLKK rong. Khong thuc hien duoc!" << endl;
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
		s -> prev = NULL;
		free(s);
	}
}

void Double_LL :: delete_pos() {
	ll pos, d = 0; 
	if (start == NULL) {
		cout << "DSLKK rong. Khong thuc hien duoc!" << endl;
		return;
	}
	else {
		node *ptr, *s, *temp; s = start; ptr = start;
		cout << "Nhap vi tri node muon loai bo: "; cin >> pos;
		while (s != NULL) {
			d++; 
			s = s -> next; 
		}
		if (pos == 1) {
			start = ptr -> next;
			start -> prev = NULL;
			ptr -> next = NULL;
			ptr -> prev = NULL;
			free(ptr);
		}
		else if (pos == d) {
			FOR(i, 1, d-1) {
				ptr = temp;
				temp = temp -> next;
			}
			ptr -> next = temp -> next;
			temp -> prev = NULL;
			free(temp);
		}
		else if (pos > 1 && pos < d) {
			temp = start;
			FOR(i, 1, pos-1) {
				ptr = temp;
				temp = temp -> next;
			}
			ptr -> next = temp -> next;
			temp -> next = NULL;
			temp -> prev = NULL;
			ptr -> next -> prev = ptr;
			free(temp);
		}
		else cout << "Vi tri ngoai danh sach!" << endl;
	}
}

void Double_LL :: display() {
	node *temp;
	if (start == NULL) {
		cout << "DSLKK rong!" << endl;
		return;
	}
	temp = start;
	cout << "Noi dung DSLKK: " << endl;
	while (temp != NULL) {
		cout << temp -> val << " <-> ";
		temp = temp -> next;
	}
	cout << "NULL" << endl; 
}

void Double_LL :: search() {
	ll n, pos = 0;
	bool flag = false;
	if (start == NULL) {
		cout << "DSLKK rong!" << endl;
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

void Double_LL :: sort() {
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

void Double_LL :: reverse() {
	node *ptr1, *ptr2;
	if (start == NULL) {
		cout << "DSLKK rong!" << endl;
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
	ll c; Double_LL DLL;
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Khoi tao DSLKK" << endl
			 << "2. Them nut vao ben trai" << endl
			 << "3. Them nut vao ben phai" << endl
			 << "4. Them nut vao vi tri pos" << endl
			 << "5. Loai nut ben trai" << endl
			 << "6. Loai nut ben phai" << endl
			 << "7. Loai nut vi tri pos" << endl
			 << "8. Tim nut co gia tri x" << endl
			 << "9. Duyet DSLKK" << endl 
			 << "10. Sap xep DSLKK" << endl
			 << "11. Dao nguoc DSLKK" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					Double_LL DLL;
					break;
				}
				case 2: {
					DLL.insert_begin();
					break;
				}
				case 3: {
					DLL.insert_last();
					break;
				}
				case 4: {
					DLL.insert_pos();
					break;
				}
				case 5: {
					DLL.delete_begin();
					break;
				}
				case 6: {
					DLL.delete_last();
					break;
				}
				case 7: {
					DLL.delete_pos();
					break;
				}
				case 8: {
					DLL.search();
					break;
				}
				case 9: {
					DLL.display();
					break;
				}
				case 10: {
					DLL.sort();
					break;
				}
				case 11: {
					DLL.reverse();
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

