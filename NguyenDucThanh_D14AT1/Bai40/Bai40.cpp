// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

ll INF = 1e9 + 7;
fstream f ("data.txt", ios :: in);

ll n, w[MAX][MAX], p[MAX], cx[MAX], D[MAX], PRIM[MAX][MAX];

void Nhap() {
	f >> n;
	FOR(i, 1, n) {
		FOR(j, 1, n)
			f >> w[i][j];
		cx[i] = true;
		p[i] = -1;
		D[i] = INT_MAX;
	}
	f.close();
}

ll Extract_Min() {
	ll min = INT_MAX, u;
	FOR(i, 1, n) {
		if (cx[i] && D[i] < min) {
			min = D[i]; 
			u = i;
		}
	}
	return u;
}

void HienThi() {
	FOR(i, 1, n) {
		FOR(j, 1, n)
			cout << setw(6) << PRIM[i][j];
		cout << endl;
	}
}

void Prim(ll i) {
	D[i] = 0;
	FOR(i, 1, n-1) {
		ll u = Extract_Min();
		cx[u] = false;
		FOR(j, 1, n) {
			if (cx[j] && w[i][j] != 0 && w[i][j] < D[j]) {
				D[j] = w[i][j];
				p[j] = u;
			}
		}
	}
	FOR(i, 1, n) 
		PRIM[p[i]][i] = PRIM[i][p[i]] = w[p[i]][i];
	HienThi();
		
}

fstream f2 ("data2.txt", ios :: in);

ll n2, s2, t2, w2[MAX][MAX], cx2[MAX], p2[MAX], d2[MAX], minp;

void Nhap2() {
	f2 >> n2;
	f2 >> s2 >> t2;
	FOR(i, 1, n2) {
		FOR(j, 1, n2) {
			f2 >> w2[i][j];
			if (w2[i][j] == -1) w2[i][j] = INF;
		}
		cx2[i] = true;
	}
	f2.close();
}

void InitDijkstra() {
	FOR(i, 1, n2) {
		d2[i] = w2[s2][i];
		p2[i] = s2;
	}
}

void Dijkstra() {
	InitDijkstra();
	
	ll u, v;
	p2[s2] = 0; d2[s2] = 0; cx2[s2] = false;
	
	cx2[s2] = false;
	while (cx2[t2]) {
		minp = INF;
		FOR(i, 1, n2) {
			if (cx2[i] && d2[i] < minp) {
				minp = d2[i];
				u = i;
			}
		}
		cx2[u] = false;
		if (cx2[t2]) {
			FOR(i, 1, n2) {
				if (cx2[i] && d2[i] > d2[u] + w2[u][i]) {
					d2[i] = d2[u] + w2[u][i];
					p2[i] = u;
				}
			}
		}
	}
}

void HienThi2() {
	cout << endl << "- Duong di ngan nhat tu " << s2 << " den " << t2 << " la:" << endl;
	cout << setw(4) << t2 << " <- ";
	ll i = p2[t2];
	while (i != s2) {
		cout << i << " <- ";
		i = p2[i];
	}
	cout << s2 << endl << "- Do dai duong di la: " << d2[t2];
}

ll w3[MAX][MAX], d3[MAX], p3[MAX], n3, dau3, cuoi3;

fstream f3 ("data3.txt", ios :: in);

void Nhap3() {
	f3 >> n3 >> dau3 >> cuoi3;
	FOR(i, 1, n3) {
		FOR(j, 1, n3) {
			f3 >> w3[i][j];
			if (w3[i][j] == 0)
				w3[i][j] = INF;
		}
		
	}
	f3.close();	
}

void HienThi3() {
	cout << endl << "Duong di ngan nhat tu dinh " << dau3 << " den dinh " << cuoi3 << " la:" << endl;
	ll i = cuoi3;
	while (i != dau3) {
		cout << i << " <- ";
		i = p3[i];
	}
	cout << dau3 << endl;
	cout << "Do dai duong di: " << d3[cuoi3] << endl;
}

bool BellmanFord() {
	FOR(i, 1, n3) {
		d3[i] = w3[dau3][i];
		p3[i] = dau3;
	}
	FOR(i, 1, n3-2) {
		bool stop = true;
		FOR(u, 1, n3) {
			FOR(v, 1, n3) {
				ll tmp = d3[u] + w3[u][v];
				if (d3[v] > tmp) {
					d3[v] = tmp;
					p3[v] = u;
					stop = false;
				}
			}
		}
		if (stop) return true;
	}	
	FOR(u, 1, n3) {
		FOR(v, 1, n3) {
			if (d3[v] > d3[u] + w3[u][v])
				return false;
		}
	}
	return true;
}


ll n1, w1[MAX][MAX], p1[MAX][MAX], d1[MAX][MAX];

fstream f1 ("data1.txt", ios :: in);

void Nhap1() {
	f1 >> n1;
	FOR(i, 1, n1) 
		FOR(j, 1, n1) {
			f1 >> w1[i][j];
			if (w1[i][j] == -1) w1[i][j] = INF;
		} 
}

void Floyd(ll u) {
	FOR(i, 1, n1) {
		FOR(j, 1, n1) {
			d1[i][j] = w1[i][j];
			p1[i][j] = 0;
		}
	}
	FOR(k, 1, n1) {
		FOR(i, 1, n1) {
			FOR(j, 1, n1) {
				if (d1[i][k] + d1[k][j] < d1[i][j]) {
					d1[i][j] = d1[i][k] + d1[k][j];
					p1[i][j] = k;
				}
			}
		}
	}
	FOR(i, 1, n1) {
		if (i != u) cout << "Duong di ngan nhat tu " << u << " -> " << i << ": " << d1[u][i] << endl;
	}
}

void Menu() {
	ll c;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. PRIM" << endl
			 << "2. Dijkstra" << endl
			 << "3. Bellman - Ford" << endl
			 << "4. Floyd" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					Nhap();
					Prim(4);
					break;
				}
				case 2: {
					Nhap2();
					Dijkstra();
					HienThi2();
					break;
				}
				case 3: {
					Nhap3();
					if (BellmanFord()) HienThi3();
					else cout << "Do thi co chu trinh am" << endl;
					break;
				}
				case 4: {
					Nhap1();
					Floyd(1);
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

