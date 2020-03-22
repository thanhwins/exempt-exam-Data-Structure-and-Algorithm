// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)
using namespace std;
void MTtoDSC() {
	fstream f1 ("data1.txt", ios :: in);
	ll w[MAX][MAX], dau[MAX], cuoi[MAX];
	ll n, dem = 0;
	f1 >> n;
	FOR(i, 1, n)
		FOR(j, 1, n)
			f1 >> w[i][j];
	
	FOR(i, 1, n-1) {
		FOR(j, i+1, n) {
			if (w[i][j] == 1) {
				dem++;
				dau[dem] = i; cuoi[dem] = j;
			}
		}
	}
	cout << n << " " << dem << endl;
	FOR(i, 1, dem) {
		cout << dau[i] << " " << cuoi[i] << endl;
	}
	f1.close();
}

void MTtoDSK() {
	fstream f1 ("data1.txt", ios :: in);
	ll w[MAX][MAX], ke[MAX];
	memset(ke, 0, MAX);
	ll n;
	f1 >> n;
	FOR(i, 1, n)
		FOR(j, 1, n) {
			f1 >> w[i][j];
			if (w[i][j] == 1) ke[i]++;
		}
			
	cout << n << endl;
	FOR (i, 1, n) {
		cout << ke[i] << " ";
		FOR(j, 1, n) {
			if (w[i][j] == 1) cout << j << " ";
		}
		cout << endl;
	}
	f1.close();
}

void DSCtoDSK() {
	fstream f2 ("data2.txt", ios :: in);
	ll n, sc, ke[MAX], w[MAX][MAX];
	memset(ke, 0, MAX);
	f2 >> n >> sc;
	FOR(i, 1, n)
		FOR(j, 1, n)
			w[i][j] = 0;
	FOR(i, 1, sc) {
		ll d, c;
		f2 >> d >> c;
		ke[d]++; ke[c]++;
		w[d][c] = 1; w[c][d] = 1;
	}
	cout << n << endl;
	FOR(i, 1, n) {
		cout << ke[i] << " ";
		FOR(j, 1, n) 
			if (w[i][j] == 1)
				cout << j << " ";
		cout << endl;
	}
	f2.close();
}

void DSCtoMT() {
	fstream f2 ("data2.txt", ios :: in);
	ll n, sc, w[MAX][MAX], d, c;
	f2 >> n >> sc;
	FOR(i, 1, n) 
		FOR(j, 1, n) 
			w[i][j] = 0;	 
	FOR(i, 1, sc) {
		f2 >> d >> c;
		w[d][c] = 1; w[c][d] = 1;
	}	
	cout << n << endl;
	FOR(i, 1, n) {
		FOR(j, 1, n) 
			cout << w[i][j] << " ";
		cout << endl;
	}
	f2.close();
}

void DSKtoMT() {
	fstream f3 ("data3.txt", ios :: in);
	ll n;
	ll w[MAX][MAX];
	f3 >> n;
	FOR(i, 1, n) 
		FOR(j, 1, n) 
			w[i][j] = 0;
	FOR(i, 1, n) {
		ll dem, cuoi;
		f3 >> dem;
		FOR(j, 1, dem) {
			f3 >> cuoi;
			w[i][cuoi] = 1;
		}
	}
	cout << n << endl;
	FOR(i, 1, n) {
		FOR(j, 1, n)
			cout << w[i][j] << " ";
		cout << endl;
	}
	f3.close();
}

void DSKtoDSC() {
	fstream f3 ("data3.txt", ios :: in);
	ll n, d = 0;
	ll w[MAX][MAX], dau[MAX], cuoi[MAX];
	f3 >> n;
	FOR(i, 1, n) 
		FOR(j, 1, n) 
			w[i][j] = 0;
	FOR(i, 1, n) {
		ll dem, cuoi;
		f3 >> dem;
		FOR(j, 1, dem) {
			f3 >> cuoi;
			w[i][cuoi] = 1;
		}
	}
	FOR(i, 1, n-1) {
		FOR(j, i+1, n) {
			if (w[i][j] == 1) {
				d++;
				dau[d] = i; cuoi[d] = j;
			}
		}
	}
	cout << n << " " << d << endl;
	FOR(i, 1, d) {
		cout << dau[i] << " " << cuoi[i] << endl;
	}
	f3.close();
}

void Menu() {
	ll c; 
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Ma tran ke sang Danh sach canh" << endl
			 << "2. Ma tran ke sang Danh sach ke" << endl
			 << "3. Danh sach canh sang Ma tran ke" << endl
			 << "4. Danh sach canh sang Danh sach ke" << endl
			 << "5. Danh sach ke sang Ma tran ke" << endl
			 << "6. Danh sach ke sang Danh sach canh" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					MTtoDSC();
					break;
				}
				case 2: {
					MTtoDSK();
					break;
				}
				case 3: {
					DSCtoMT();
					break;
				}
				case 4: {
					DSCtoDSK();
					break;
				}
				case 5: {
					DSKtoMT();
					break;
				}
				case 6: {
					DSKtoDSC();
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

