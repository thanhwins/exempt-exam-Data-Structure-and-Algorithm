// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

struct item {
	float heSo;
	int soMu;	
};

struct DaThuc {
	item x;
	DaThuc *next;
};

DaThuc *creat(item n) {
	DaThuc *p = new (DaThuc);
	p -> x = n;
	p -> next = NULL;
	return p;
}

DaThuc *push_back(DaThuc *p, item n) {
	DaThuc *r = creat(n);
	if (p == NULL) return r;
	DaThuc *r1 = p;
	while (r1 -> next != NULL) 
		r1 = r1 -> next;
	r1 -> next = r;
	return p;
}

DaThuc *sort(DaThuc *p) {
	DaThuc *r = p, *r1;
	while (r != NULL) {
		for (r1 = r -> next; r1 != NULL; r1 = r1 -> next) {
			if (r -> x.soMu < r1 -> x.soMu) {
				item tmp = r1 -> x;
				r1 -> x = r -> x;
				r -> x = tmp;
			}
		}
		r = r -> next;
	}
	return p;
}
DaThuc *nhap(DaThuc *p, int &n) {
	item a;
	cout << "Nhap so phan tu cua da thuc: "; cin >> n;
	FOR(i, 1, n) {
		cout << "Phan tu thu " << i << " :\n";
		cout << "\tHe so: "; cin >> a.heSo;
		cout << "\tSo mu: "; cin >> a.soMu;
		p = push_back(p,a);
	}
	p = sort(p);
	return p;
}
void display(DaThuc *p) {
	while (p != NULL) {
		if(p -> next != NULL)
		cout << p -> x.heSo  << "x^" << p -> x.soMu << " + ";
		else cout << p -> x.heSo  << "x^" << p -> x.soMu;
		p = p -> next;
	}
	cout << endl;
}

DaThuc *sum(DaThuc *p, DaThuc *q) {
	DaThuc *t = NULL;
	while (p != NULL && q != NULL) {
		if (p -> x.soMu > q -> x.soMu) {
			t = push_back(t,p -> x);
			p = p -> next;
		}
		else if (p -> x.soMu < q -> x.soMu) {
			t = push_back(t,q -> x);
			q = q -> next;
		}
		else {
			item a;
			a.soMu = p -> x.soMu;
			a.heSo = p -> x.heSo + q -> x.heSo;
			t = push_back(t,a);
			p = p -> next;
			q = q -> next;
		}
	}
	while (p != NULL) {
		t = push_back(t,p -> x);
		p = p -> next;
	}
	while (q != NULL) {
		t = push_back(t,q -> x);
		q = q -> next;
	}
	return t;
}

void  sumx0(DaThuc *start, ll x0) {
	ll S = 0;
	DaThuc *ptr = start;
	while (ptr != NULL) {
		S += ptr -> x.heSo * pow(x0, ptr -> x.soMu);
		ptr = ptr -> next;
	}
	cout << S << endl;
}

DaThuc *sub(DaThuc *p, DaThuc *q){
	DaThuc *t = NULL;
	while(p != NULL && q != NULL){
		if(p -> x.soMu > q -> x.soMu){
			t = push_back(t,p -> x);
			p = p -> next;
		}
		else if(p -> x.soMu < q -> x.soMu){
			t = push_back(t,q -> x);
			q = q -> next;
		}else{
			item a;
			a.soMu = p -> x.soMu;
			a.heSo = p -> x.heSo - q -> x.heSo;
			if(a.heSo != 0) t = push_back(t,a);
			p = p -> next;
			q = q -> next;
		}
	}
	while(p != NULL){
		t = push_back(t,p -> x);
		p = p -> next;
	}
	while(q != NULL){
		t = push_back(t,q -> x);
		q = q -> next;
	}
	return t;
}

DaThuc *mul_1(DaThuc *p, item a){
	DaThuc *t = NULL;
	while(p != NULL){
		item tmp;
		tmp.heSo = a.heSo * p -> x.heSo;
		tmp.soMu = a.soMu + p -> x.soMu;
		t = push_back(t,tmp);
		p = p -> next;
	}
	t = sort(t);
	return t;
}
DaThuc *mul(DaThuc *p, DaThuc *q){
	DaThuc *t = NULL;
	DaThuc *tmp = NULL;
	while(q != NULL){
		item a = q -> x;
		tmp = mul_1(p,a);
		t = sum(t,tmp);
		q = q -> next;
	}
	return t;
}

void dive(DaThuc *p, DaThuc *q){
	DaThuc *thuong, *du;
	du = p;
	thuong = NULL;
	while(du -> x.soMu >= q -> x.soMu){
		item a;
		a.soMu = (du) -> x.soMu - q -> x.soMu;
		a.heSo = ((du) -> x.heSo) / (q -> x.heSo);
		thuong = push_back(thuong,a);
		DaThuc *tmp;
		tmp = mul_1(q,a);
		du = sub(du,tmp);
	}
	if (thuong == NULL) {
		cout << "R = 0" << endl; 
		cout << "Du = "; display(du);
	}
	else {
		cout << "R = "; display(thuong);
		cout << "Du = "; display(du);
	}
}

void daoHam(DaThuc *ptr) {
	DaThuc *s = ptr, *p = s;
	ll dem = 0;
	while (s != NULL) {
		dem++;
		s -> x.heSo = s -> x.heSo * s -> x.soMu;
		s -> x.soMu--;
		s = s -> next ;
	}
	FOR(i, 1, dem-1) {
		if (p -> x.soMu != 0) {
			cout << p -> x.heSo  << "x^" << p -> x.soMu << " + ";
		}
		p = p -> next;
	}
	if (p -> x.soMu != 0) cout << p -> x.heSo  << "x^" << p -> x.soMu << endl;
}

void Menu() {
	int c, n, m;
	DaThuc *p = NULL, *q = NULL, *kq = NULL;
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Tao lap da thuc Pn(x), Qm(x)" << endl
			 << "2. Tim gia tri Pn(x0), Qm(x0)" << endl
			 << "3. Tim R = P + Q" << endl
			 << "4. Tim R = P * Q" << endl
			 << "5. Tim R = P / Q va da thuc du" << endl
			 << "6. Tim dao ham bac 1 cua da thuc" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					p = NULL; q = NULL;
					cout << "Da thuc P: " << endl;
					p = nhap(p, n);
					cout << "Da thuc Q: " << endl;
					q = nhap(q, m);
					cout << "P = ";
					display(p);
					cout << "Q = ";
					display(q);
					break;
				}
				case 2: {
					ll x0; cout << "x0 = "; cin >> x0;
					cout << "P(x0) = ";
					sumx0(p, x0);
					cout << "Q(x0) = ";
					sumx0(q, x0);
					break;
				}
				case 3: {
					kq = NULL;
					kq = sum(p, q);
					cout << "R = ";
					display(kq);
					break;
				}
				case 4: {
					kq = NULL;
					kq = mul(p, q);
					cout << "R = ";
					display(kq);
					break;
				}
				case 5: {
					dive(p, q);
					break;
				}
				case 6: {
					cout << "P'(x) = ";
					daoHam(p);
					cout << "Q'(x) = ";
					daoHam(q);
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

