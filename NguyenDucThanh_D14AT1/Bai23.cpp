// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

ll Tree[MAX];

void MakeRoot(ll x) {
	Tree[0] = x; 
}
void swap(ll &a, ll &b) {
	ll temp = a;
	 a = b;
	 b = temp;
}

void Add() {
	ll x;
	cout << "Nhap gia tri node muon them: "; cin >> x;
	ll p, q;
	p = q = 0;
	while (Tree[q] != -1 && Tree[p] != x) {
		p = q;
		if (x < Tree[p]) 
			q = 2*p+1;
		else q = 2*p+2;
	}
	if (x == Tree[p]) {
		cout << "Node da ton tai!" << endl;
		return;
	}
	if (x < Tree[p]) {
		ll temp = Tree[2*p+1];
		Tree[2*p+1] = x;
		while (Tree[2*(2*p+1)+1] != -1) {
			swap(temp, Tree[2*(2*p+1)+1]);
			p = 2*p+1;
			temp = Tree[2*p+1];
		}
	}
	else {
		ll temp = 2*p+2;
		Tree[2*p+2] = x;
		while (Tree[2*(2*p+2)+2] != -1) {
			swap(temp, Tree[2*(2*p+1)+2]);
			p = 2*p+2;
			temp = Tree[2*p+2];
		}
	}
}

ll minValueNode() {
	ll p = 0;
	while (Tree[2*p+1] != -1) p = 2*p+1;
	return p;
}

void Remove(ll x) {
	ll temp, child;
	ll p = 0, q;
	while (Tree[p] != -1) {
		if (Tree[p] == x) {
			break;
		}
		q = p;
		if (x < Tree[2*p+1]) p = 2*p+1;
		else p = p*2+2;
	}
	if (Tree[p] == -1) cout << "x khong ton tai trong cay!" << endl;
	if (Tree[2*p+1] != -1 && Tree[2*p+2] != -1) {
		temp = p;
		q = p; p = 2*p+1;
		while (Tree[2*p+2] != -1) {
			q = p; p = 2*p+2;
		}
		Tree[temp] = Tree[p];
	}
	if (Tree[2*p+1] != -1) child = 2*p+1;
	else child = 2*p+2;
	if (p == 0) p = child;
	else {
		if (2*q+1 == p) Tree[2*q+1] = Tree[child];
		else Tree[2*q+2] = Tree[child];
	}
	Tree[p] = -1;
}

void Search(ll x) {
	bool flag = false;
	FOR(i, 0, MAX-1) {
		if (Tree[i] == x) {
			flag = true;
			cout << "YES" << endl;
			break;
		}
	}
	if (!flag) cout << "NO" << endl;
}

void NLR(ll i) {
	if (Tree[i] != -1) {
		cout << Tree[i] << " ";
		NLR(2*i+1);
		NLR(2*i+2);
	}
}

void LNR(ll i) {
	if (Tree[i] != -1) {
		LNR(2*i+1);
		cout << Tree[i] << " ";
		LNR(2*i+2);
	}
}
 
void LRN(ll i) {
	if (Tree[i] != -1) {
		LRN(2*i+1);
		LRN(2*i+2);
		cout << Tree[i] << " ";
	}
} 

void NLR1() {
	stack <ll> s;
	ll i = 0;
	while (true) {
		while (Tree[i] != -1) {
			cout << Tree[i] << " ";
			s.push(i);
			i = 2*i+1;
		}
		if (s.empty()) {
			return;
		}
		i = s.top();
		s.pop();
		i = 2*i+2;
	}
}

void LNR1() {
	stack <ll> s;
	ll i = 0;
	bool done = 0;
	while (!done) {
		if (Tree[i] != -1) {
			s.push(i);
			i = 2*i+1;
		}
		else {
			if (!s.empty()) {
				i = s.top();
				cout << Tree[i] << " ";
				s.pop();
				i = 2*i+2;
			}
			else done = 1;
		}
	}
} 

void LRN1() {
	stack <ll> s1;
	stack <ll> s2;
	ll i = 0;
	s1.push(i);
	while (!s1.empty()) {
		i = s1.top();
		s1.pop();
		s2.push(i);
		if (Tree[2*i+1] != -1) {
			s1.push(2*i+1);
		}
		if (Tree[2*i+2] != -1) {
			s1.push(2*i+2);
		}
	}
	while (!s2.empty()) {
		i = s2.top();
		cout << Tree[i] << " ";
		s2.pop();
	}
}

void Menu() {
	ll c;
	FOR(i, 0, 100) {
		Tree[i] = -1;
	}
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			     << "1. Tao nut goc cho cay" << endl
			     << "2. Them node cho cay" << endl
			     << "3. Loai node tren cay" << endl
			     << "4. Tim node co gia tri x tren cay" << endl
			     << "5. Duyet cay theo thu tu truoc bang de quy" << endl
			     << "6. Duyet cay theo thu tu giua bang de quy" << endl
			     << "7. Duyet cay theo thu tu sau bang de quy" << endl
			     << "8. Duyet cay theo thu tu truoc khong de quy" << endl
			     << "9. Duyet cay theo thu tu giua khong de quy" << endl
			     << "10. Duyet cay theo thu tu sau khong de quy" << endl
			     << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					ll x;
					cout << "Nhap gia tri cua node: "; cin >> x;
					MakeRoot(x);
					break;
				}
				case 2: {
					Add();
					break;
				}
				case 3: {
					ll x;
					cout << "Nhap gia tri node cha: "; cin >> x;
					Remove(x);
					break;
				}
				case 4: {
					ll x;
					cout << "Nhap gia tri node can tim: "; cin >> x;
					Search(x);
					break;
				}
				case 5: {
					ll i = 0;
					NLR(i);
					break;
				}
				case 6: {
					ll i = 0;
					LNR(i);
					break;
				}
				case 7: {
					ll i = 0;
					LRN(i);
					break;
				}
				case 8: {
					NLR1();
					break;
				}
				case 9: {
					LNR1();
					break;
				}
				case 10: {
					LRN1();
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

