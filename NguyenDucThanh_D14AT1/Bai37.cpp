// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

ll w[MAX][MAX], cx[MAX], n, p[MAX], T[MAX], k = 0;

fstream f ("data.txt", ios :: in);

void Nhap() {
	f >> n;
	FOR(i, 1, n) {
		FOR(j, 1, n) 
			f >> w[i][j];
	}
	f.close();
}

void Init() {
	FOR(i, 1, n) cx[i] = true;
}

void DFS(ll u) {
	stack <ll> s;
	s.push(u);
	T[++k] = u;
	cx[u] = false;
	while (!s.empty()) {
		ll v = s.top();
		s.pop();
		FOR(i, 1, n) {
			if (cx[i] && w[v][i]) {
				T[++k] = i;
				cx[i] = false;
				p[i] = v;
				s.push(v);
				s.push(i);
				break;
			}
		}
	}
}

void Display() {
	FOR(i, 1, n) {
		FOR(j, 1, n) 
			cout << w[i][j] << " ";
		cout << endl;
	}	
}

int DemLT() {
	int dem = 0;
	FOR(v, 1, n) {
		if (cx[v]) {
			dem++;
			DFS(v);
		}
	}
	return dem;
}

void DuongDi() {
	Init();
	DFS(1);
	int a, b;
	cout << "Nhap dinh s: "; cin >> a;
	cout << "Nhap dinh t: "; cin >> b;
	if (p[b] == 0) {
		cout << "Khong co duong di tu " << a << " toi " << b << endl;
	}
	else {
		cout << "Duong di: " << endl << b << " <- ";
		int u = p[b];
		while (u != a) {
			cout << u << " <- ";
			u = p[u];
		}
		cout << a << endl << endl;;
	}
}

bool KTTru(int u) {
	Init();
	int temp = DemLT();
	Init();
	cx[u] = false;
	if (DemLT() > temp) return true;
	return false;
}

void LKeTru() {
	Init();
	int dem = 0;
	cout << "Liet ke dinh tru: " << endl << "\t";
	FOR(u, 1, n) {
		if (KTTru(u)) {
			cout << u << " ";
			dem++;
		}
	}
	if (!dem) cout << "Khong co!";
	cout << endl;
}

bool KTraCC(int a, int b) {
	Init();
	int temp1 = DemLT();
	w[a][b] = 0; w[b][a] = 0;
	Init();
	int temp2 = DemLT();
	w[a][b] = 1; w[b][a] = 1;
	if (temp2 > temp1) return true;	
	return false;	
}

int cau = 0;

void LKeCau() {
	cout << "Liet ke canh cau: " << endl << "\t";
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (w[i][j] && KTraCC(i, j)) {
				cau++;
				cout << "(" << i << ", " << j << ") ";
			}	
		}
	}
	cout << endl << endl; 	
}

bool KTDC() {
	FOR(i, 1, n-1) 
		FOR(j, i+1, n) 
			if (w[i][j] && KTraCC(i, j)) 
				return false;
	return true;
}

bool LTManh() {
	Init();
	FOR(u, 1, n) {
		DFS(u);
		FOR(j, 1, n) {
			if (cx[j]) 
				return false;
		}
		Init();
	}
	return true;
}
void DinhThat() {
	int a, b, dem = 0;
	Init();
	cout << "Nhap dinh u: "; cin >> a;
	cout << "Nhap dinh v: "; cin >> b;	
	cout << "Dinh that la: ";
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			p[j] = 0;
		if (i != a && i != b) {
			cx[i] = false; 
			DFS(a);
			if (p[b] == 0) dem++, cout << i << " " << endl;
			Init();	
		}
	}
	if (!dem) cout << "Khong co!";
	cout << endl;
}

void CayKhung() {
	ll u;
	cout << "Cay khung bat dau tu dinh: "; cin >> u; 
	Init();
	stack <ll> s;
	ll sc = 0;
	s.push(u);
	cx[u] = false;
	while (!s.empty()) {
		ll v = s.top();
		s.pop();
		FOR(i, 1, n) {
			if (cx[i] && w[v][i]) {
				cout << "(" << v << "-" << i << ")" << " ";
				sc++;
				cx[i] = false;
				s.push(v);
				s.push(i);
				break;
			}
		}
	}
	if (sc < n-1) cout << "Do thi khong lien thong" << endl;
}

void Menu() {
	ll c; 
	Nhap();
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Bieu dien do thi bang ma tran ke" << endl
			 << "2. Duyet cac dinh bang DFS" << endl
			 << "3. Xac dinh so thanh phan lien thong" << endl
			 << "4. Tim duong di tu dinh s den dinh t" << endl
			 << "5. Kiem tra tinh lien thong manh cua do thi" << endl
			 << "6. Xac dinh cac dinh tru" << endl
			 << "7. Xac dinh cac canh cau" << endl
			 << "8. Xac dinh cac dinh that cua cap canh u,v" << endl
			 << "9. Kiem tra tinh dinh chieu duoc" << endl 
			 << "10. Xay dung cay khung" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					Display();
					break;
				}
				case 2: {
					Init();
					if (DemLT() != 1) cout << "Do thi khong lien thong";
					else {
						FOR(i, 1, k) cout << T[i] << " ";
					}
					cout << endl;
					break;
				}
				case 3: {
					Init();
					cout << DemLT() << endl;
					break;
				}
				case 4: {
					DuongDi();
					break;
				}
				case 5: {
					if (LTManh()) cout << "YES" << endl;
					else cout << "NO" << endl;
					break;
				}
				case 6: {
					LKeTru();
					break;
				}
				case 7: {
					LKeCau();
					break;
				}
				case 8: {
					DinhThat();
					break;
				}
				case 9: {
					if (KTDC()) cout << "YES" << endl;
					else cout << "NO" << endl;
					break;
				}
				case 10: {
					CayKhung();
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

