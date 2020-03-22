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
void Add_Left() {
	ll x, y;
	bool flag = false;
	cout << "Nhap gia tri cua cha: "; cin >> x;
	FOR(i, 0, MAX-1) {
		if (Tree[i] == x) {
			flag = true;
			if (Tree[2*i+1] == -1) {
				cout << "Nhap gia tri node con muon them: "; cin >> y;
				Tree[2*i+1] = y;
			}
			else cout << "Node cha x da co nut con trai" << endl;
			break;
		}
	}
	if (!flag) cout << "Node cha khong co thuc" << endl;
}

void Add_Right() {
	ll x, y;
	bool flag = false;
	cout << "Nhap gia tri cua cha: "; cin >> x;
	FOR(i, 0, MAX-1) {
		if (Tree[i] == x) {
			flag = true;
			if (Tree[2*i+2] == -1) {
				cout << "Nhap gia tri node con muon them: "; cin >> y;
				Tree[2*i+2] = y;
			}
			else cout << "Node cha x da co nut con phai" << endl;
			break;
		}
	}
	if (!flag) cout << "Node cha khong co thuc" << endl;
}

void Remove_Left(ll x) {
	bool flag = false;
	FOR(i, 0, MAX-1) {
		if (Tree[i] == x) {
			flag = true;
			if (Tree[2*(2*i+2) + 1] == -1) {
				Tree[2*i+1] = -1;
			}
			else cout << "Node x co nhanh cay con trai. Khong loai bo duoc!" << endl;
			break;
		}
	}
	if (!flag) cout << "Node x khong co tren cay" << endl;
}

void Remove_Right(ll x) {
	bool flag = false;
	FOR(i, 0, MAX-1) {
		if (Tree[i] == x) {
			flag = true;
			if (Tree[2*(2*i+2) + 2] == -1) {
				Tree[2*i+2] = -1;
			}
			else cout << "Node x co nhanh cay con trai. Khong loai bo duoc!" << endl;
			break;
		}
	}
	if (!flag) cout << "Node x khong co tren cay" << endl;
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
	memset(Tree, -1, 100);
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			     << "1. Tao nut goc cho cay" << endl
			     << "2. Them nut la ben trai cho node x" << endl
			     << "3. Them nut la ben phai cho node x" << endl
			     << "4. Loai nut la ben trai cua nut x" << endl
			     << "5. Loai nut la ben phai cua nut x" << endl
			     << "6. Tim node co gia tri x tren cay" << endl
			     << "7. Duyet cay theo thu tu truoc bang de quy" << endl
			     << "8. Duyet cay theo thu tu giua bang de quy" << endl
			     << "9. Duyet cay theo thu tu sau bang de quy" << endl
			     << "10. Duyet cay theo thu tu truoc khong de quy" << endl
			     << "11. Duyet cay theo thu tu giua khong de quy" << endl
			     << "12. Duyet cay theo thu tu sau khong de quy" << endl
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
					Add_Left();
					break;
				}
				case 3: {
					Add_Right();
					break;
				}
				case 4: {
					ll x;
					cout << "Nhap gia tri node cha: "; cin >> x;
					Remove_Left(x);
					break;
				}
				case 5: {
					ll x;
					cout << "Nhap gia tri node cha: "; cin >> x;
					Remove_Right(x);
					break;
				}
				case 6: {
					ll x;
					cout << "Nhap gia tri node can tim: "; cin >> x;
					Search(x);
					break;
				}
				case 7: {
					ll i = 0;
					NLR(i);
					break;
				}
				case 8: {
					ll i = 0;
					LNR(i);
					break;
				}
				case 9: {
					ll i = 0;
					LRN(i);
					break;
				}
				case 10: {
					NLR1();
					break;
				}
				case 11: {
					LNR1();
					break;
				}
				case 12: {
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
