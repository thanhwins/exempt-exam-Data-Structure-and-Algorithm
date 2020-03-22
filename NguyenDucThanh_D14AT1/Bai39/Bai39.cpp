// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

ll w[MAX][MAX], g[MAX][MAX], n, CE[MAX], cx[MAX], B[MAX];
ll vh, u = 1, x, k = 0, x2, y, m = 0, d1 = 0, d2 = 0;

fstream f ("data.txt", ios :: in);

void Nhap() {
	f >> n;
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			f >> w[i][j];
			g[i][j] = w[i][j];
		}
	}
	f.close();
}

void Init() {
	FOR(i, 1, n) cx[i] = true;
}

void Display() {
 	FOR(i, 1, n) {
 		FOR(j, 1, n) {
 			cout << w[i][j] << " ";
 		}
 		cout << endl;
 	}
}

void DFS(ll u) {
	stack <ll> s;
	s.push(u);
	cx[u] = false;
	while (!s.empty()) {
		ll v = s.top();
		s.pop();
		FOR(i, 1, n) {
			if (cx[i] && w[v][i] + w[i][v] > 0) {
				cx[i] = false;
				s.push(v);
				s.push(i);
				break;
			}
		}
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

ll Check_VoHuong() {
	Init();
	if (DemLT() == 1) {
		ll h;
		ll chan = 0, le = 0;
		FOR(u, 1, n) {
			h = 0;
			FOR(v, 1, n) {
				h += w[u][v];
			}
			if (h % 2 == 0) chan++;
			else {
				le++;
				x = u;
			}
		}
		if (chan == n) return 1;
		else if (le == 2) return (-1);
		else return 0;
	}
	else return 0;
}
 
ll Check_CoHuong() {
	Init();
	if (DemLT() == 1) {
		ll h, c;
		ll dem1 = 0, dem2 = 0, dem3 = 0;
		FOR(u, 1, n) {
			h = 0, c = 0;
			FOR(v, 1, n) {
				h += w[u][v];
				c += w[v][u];
			}
			if (h == c) dem1++;
			else if (h - c == 1) {
				dem2++;
				x2 = u;
			}
			else if (c - h == 1) {
				dem3++;
				y = u;
			}
		}
		if (dem1 == n) return 1;
		else if (dem2 == 1 && dem3 == 1) return (-1);
		else return 0;
	}
	else return 0;
} 

void KTVoHuong(){
	vh = 1;
	FOR(i, 1, n - 1){
		FOR(j, i + 1, n){
			if (w[i][j] != w[j][i]){
				vh = 0;
				return;
			}
		}
	}
}
 
void ttEuler(ll u) {
 	stack <int> st;
 	st.push(u);
 	ll nCE = 0;
 	while (!st.empty()) {
 		ll h = st.top();
 		st.pop();
		bool ck = true;
 		FOR(v, 1, n) {
 			if (g[h][v]) {
	 			st.push(h);
 				st.push(v);
 				g[h][v] = 0;
 				if (vh) g[v][h] = 0;
				if (ck) ck = false;	
				break;
 			}
 		}
 		if (ck) CE[++nCE] = h;
 	}
 	cout << endl << "Chu trinh Euler: " << endl;
 	FORD(i, nCE, 2) cout << CE[i] << " -> ";
 	cout << CE[1] << endl;
}

void HienThiCT() {
	d1++;
	cout << endl << "Chu trinh Hamilton: ";
	FOR(i, 0, n-1) cout << B[i] << " -> ";
	cout << B[n] << endl;
}

void HienThiDD() {
	d2++;
	cout << endl << "Duong di: ";
	FOR(i, 0, n-2) cout << B[i] << " -> ";
	cout << B[n-1] << endl;
}

void ctHamilton(ll i) {
	FOR(j, 1, n) {
		if (w[B[i-1]][j] && cx[j]) {
			B[i] = j;
			cx[j] = false;
			if (i < n) ctHamilton(i+1);
			else if (B[i] == B[0]) {
				HienThiCT();
			}
			cx[j] = true;
		}
	}
}

void ddHamilton(ll i) {
	FOR(j, 1, n) {
		if (w[B[i-1]][j] && cx[j]) {
			B[i] = j;
			cx[j] = false;
			if (B[i] != B[0]) {
				if (i < n-1) ddHamilton(i+1);
				HienThiDD();
			}
			cx[j] = true;
		}
	}
}

void Menu() {
	ll c; 
	Nhap(); KTVoHuong();
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Bieu dien do thi bang ma tran ke" << endl
			 << "2. Tim mot chu trinh Euler tren do thi vo huong bat dau tai dinh u bang DFS" << endl
			 << "3. Tim mot chu trinh Euler tren do thi co huong bat dau tai dinh u bang DFS" << endl
			 << "4. Tim mot duong di Euler tren do thi vo huong bang DFS " << endl
			 << "5. Tim mot duong di Euler tren do thi vo huong bang DFS" << endl
			 << "6. Liet ke tat ca chu trinh Hamilton tren do thi bat dau tai dinh u" << endl
			 << "7. Liet ke tat ca duong di Hamilton tren do thi bat dau tai dinh u" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					Display();
					break;
				}
				case 2: {
					if (vh) {
						if (Check_VoHuong() == 0) {
							cout << "Do thi khong ton tai chu trinh Euler!" << endl;
						}
						else if (Check_VoHuong() == 1) {
							ll u;
							cout << "Nhap dinh u: "; cin >> u; cout << endl;
							ttEuler(u);
						}
						else cout << "Do thi la nua Euler!" << endl;
					}
					else cout << "Day khong phai do thi vo huong!" << endl;
					break;
				}
				case 3: {
					if (!Check_CoHuong()) {
						cout << "Do thi khong ton tai chu trinh Euler!" << endl;
					}
					else if (Check_CoHuong() == 1) {
						ll u;
						cout << "Nhap dinh u: "; cin >> u; cout << endl;
						ttEuler(u);
					}
					else cout << "Do thi la nua Euler!" << endl;
					break;
				}
				case 4: {
					if (vh) {
						if (!Check_VoHuong()) {
							cout << "Do thi khong ton tai duong di Euler!" << endl;
						}
						else if (Check_VoHuong() == -1) {
							ttEuler(x);
						}
						else cout << "Do thi la Euler!" << endl;
					}
					else cout << "Day khong phai do thi vo huong!" << endl;
					break;
				}
				case 5: {
					if (!Check_CoHuong()) {
						cout << "Do thi khong ton tai duong di Euler!" << endl;
					}
					else if (Check_CoHuong() == -1) {
						ttEuler(x2);
					}
					else cout << "Do thi la Euler!" << endl;
					break;
				}
				case 6: {
					ll u; Init(); 
					cout << "Nhap dinh u: "; cin >> u; 
					B[0] = u; cout << endl;
					ctHamilton(u);
					if (!d1) cout << "Khong co chu trinh Hamilton!" << endl;
					break;
				}
				case 7: {
					ll u; Init(); 
					cout << "Nhap dinh u: "; cin >> u; 
					B[0] = u; cout << endl;
					ddHamilton(u);
					if (!d2) cout << "Khong co duong di Hamilton!" << endl;
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

