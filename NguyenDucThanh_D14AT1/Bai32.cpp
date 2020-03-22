// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

ll n1, a1[MAX];

void Nhap1() {
	cout << "Nhap n: "; cin >> n1;
}

void Display1() {
	FOR(i, 1, n1) cout << a1[i] << " ";
	cout << endl;
}

void Try1(ll i) {
	
	FOR(j, 0, 1) {
		a1[i] = j;
		if (i == n1) Display1();
		else Try1(i+1);
	}
}
int n2, k2, a2[MAX];

void Nhap2() {
	cout << "Nhap n: "; cin >> n2;
	cout << "Nhap k: "; cin >> k2;
}

void Display2() {
	FOR(i, 1, k2) cout << a2[i] << " ";
	cout << endl;
}

void Try2(int i) {
	FOR(j, a2[i-1]+1, n2-k2+i) {
		a2[i] = j;
		if (i == k2) Display2();
		else Try2(i+1);
	}
}

int n3, a3[MAX], cx3[MAX];

void Nhap3() {
	cout << "Nhap n: "; cin >> n3;
	FOR(i, 1, n3) cx3[i] = true;
}

void Display3() {
	FOR(i, 1, n3) cout << a3[i] << " ";
	cout << endl;
}

void Try3(int i) {
	FOR(j, 1, n3) {
		if (cx3[j]) {
			a3[i] = j;
			cx3[j] = false;
			if (i == n3) Display3();
			else Try3(i+1);
			cx3[j] = true;
		}
	}
}

int n4, x4[MAX], a4[MAX], xuoi4[MAX], nguoc4[MAX];

void Nhap4() {
	cout << "Nhap n: "; cin >> n4;
	FOR(i, 1, n4)
		a4[i] = true;
	FOR(i, 1, 2*n4-1) {
		xuoi4[i] = true;
		nguoc4[i] = true;
	}
}

void Display4() {
	FOR(i, 1, n4) cout << "("<<i<<","<<x4[i]<<") ";
	cout << endl; 
}

void Try4(int i) {
	FOR(j, 1, n4) {
		if (a4[j] && xuoi4[i-j+n4] && nguoc4[i+j-1]) {
			x4[i] = j;
			a4[j] = false; xuoi4[i-j+n4] = false; nguoc4[i+j-1] = false;
			if (i == n4) Display4();
			else Try4(i+1);
			a4[j] = true; xuoi4[i-j+n4] = true; nguoc4[i+j-1] = true;
		}
	}
}

int feasible(int S[][9], int x, int y, int k){
	int i = 0, j = 0;
	FOR(i, 0, 8) {
		if (S[x][i] == k) return 0;
	}
	FOR(i, 0, 8) {
			if (S[i][y] == k) return 0;
		}
	int a = x/3, b = y/3;
	for(i = 3*a; i < 3*a+3; i++) {
		for(j = 3*b; j < 3*b+3; j++) {
			if (S[i][j] == k) return 0;
		}
	}
	return 1;

}

void printSolution(int S[][9]){
	int i = 0, j = 0;
	FOR(i, 0, 8) {
		FOR(j, 0, 8) {
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
}

void solve_sudoku(int S[][9], int x, int y) {
	if(y == 9) {
		if(x == 8) {
			printSolution(S);
		} 
		else {
			solve_sudoku(S, x+1,0);
		}
	} 
	else if(S[x][y] == 0) {
		int k = 0;
		FOR(k, 1, 9) {
			if (feasible(S,x,y,k)) {
				S[x][y] = k;
				solve_sudoku(S, x, y+1);
				S[x][y] = 0;
			}
		}
	} 
	else {
		solve_sudoku(S,x,y+1);
	}
}

int a[5][5] = { {0,15,30,50,20},
                {15,0,10,35,32},
                {30,10,0,15,40},
            	{50,35,15,0,43},
                {20,32,40,43,0}};
int n5;
bool b[5] = {false};
int kq[10], bestConfig[10] = {0};
int min5 = 32000, cost = 0;
int start;

void Output() {
	FOR(i, 0, n5-1) {
		cout << bestConfig[i]+1 << " -> ";
	}
	cout << bestConfig[0]+1 << endl;
	cout << "Chi phi: " << min5 << endl;
}

void Try(int i) {
	if (i == n5) {
		if (cost + a[kq[i-1]][kq[0]] < min5) {
			min5 = cost + a[kq[i-1]][kq[0]];
			FOR(k, 0, n5-1) 
				bestConfig[k]= kq[k];
		}
	}
	else {
		FOR(j, 0, n5-1) {
			if(b[j] == false && cost + a[kq[i-1]][j] < min5) {
				kq[i] = j;
				b[j] = true;
				cost += a[kq[i-1]][j];
				Try(i+1);
				b[j] = false;
				cost -= a[kq[i-1]][j];
			}
		}
	}
}

int max(int a, int b) { 
	return (a > b)? a : b; 
}

int knapSack(int W, int wt[], int val[], int n) {
   if (n == 0 || W == 0)
       return 0;
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
   else 
   	return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1));
}

void Menu() {
	ll c;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Liet ke xau nhi phan do dai n" << endl
			 << "2. Liet ke to hop chap k cua day An" << endl
			 << "3. Liet ke hoan vi cua day An" << endl
			 << "4. Giai bai toan cai tui" << endl
			 << "5. Giai bai toan nguoi di du lich" << endl
			 << "6. Giai bai toan n quan hau" << endl
			 << "7. Giai bai toan Sudoku" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					Nhap1();
					Try1(1);
					break;
				}
				case 2: {
					Nhap2();
					a2[0] = 0;
					Try2(1);
					break;
				}
				case 3: {
					Nhap3();
					Try3(1);
					break;
				}
				case 4: {
					int val[] = {60, 100, 120};
				    int wt[] = {10, 20, 30};
				    int  W = 50;
				    int n6 = sizeof(val) / sizeof(val[0]);
				    cout << knapSack(W, wt, val, n6) << endl;
					break;
				}
				case 5: {
					n5 = 5;
					start = 3;
					kq[0] = start; b[start] = true;
					
					Try(1);
					Output();		
					break;
				}
				case 6: {
					Nhap4();
					Try4(1);
					break;
				}
				case 7: {
					int S[9][9] =      {{0,3,1,2,0,0,0,7,9},
										{5,4,0,0,0,9,1,0,0},
										{8,0,0,0,0,7,0,0,5},
										{2,6,8,0,0,1,5,0,0},
						  				{1,0,0,0,0,0,0,0,8},
										{0,0,9,4,0,0,7,1,6},
										{9,0,0,8,0,0,0,0,2},
										{0,0,3,5,0,0,0,6,7},
										{7,2,0,0,0,4,3,8,0}};
					cout << "De bai: " << endl;
					printSolution(S);
					cout << "Dap ap:" << endl;
					solve_sudoku(S,0,0);
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

