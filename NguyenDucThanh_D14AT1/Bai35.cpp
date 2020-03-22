// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

void xuat1(ll a[][2])
{
    FOR(i, 0, 1) {
        FOR(j, 0, 1)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
void Mul() {
	ll a[2][2] = {{1, 2},{2, 1}};
	ll b[2][2] = {{1, 2},{2, 1}};
	ll t[2][2];
	cout << "Ma tran A: " << endl;
	xuat1(a);
	cout << "Ma tran B: " << endl;
	xuat1(b);
    FOR(i, 0, 1) {
        FOR(j, 0, 1) {
            t[i][j]=0;
            FOR(k, 0, 1)
                t[i][j] += a[i][k] * b[k][j];
        }
    }
    cout << "Ma tran A*B: " << endl;
    xuat1(t);
}

ll F(int m, int v) { 
	if (m == 0) { 
		if (v == 0) 
			return 1; 
		else return 0; 
	}
	else { 
		if (m>v ) 
			return (F(m-1, v)); 
		else return (F(m-1,v) + F(m,v-m)); 
	} 
} 

ll min(ll a, ll b) {
	return a<b?a:b;
}

void BienDoiXau() {
	char x[1000006];
	ll n;
	cin >> n >> x+1;
	ll *A = new ll[n+5];
	ll *B = new ll[n+5];
	A[0] = B[0] = 0;
	FOR(i, 1, n) {
		if(x[i] == 'A') {
			A[i] = A[i-1];
			B[i] = 1 + min(A[i-1], B[i-1]);
		}
		else {
			A[i] = 1 + min(A[i-1], B[i-1]);
			B[i] = B[i-1];
		}
	}
	cout << A[n];
}

void CaiTui() {
	int n, W; 
	int a[MAX], b[MAX]; 
	cin >> n >> W;
	FOR(i, 1, n) {
		cin >> a[i] >> b[i];
	}
	int L[MAX][MAX];
	FOR(i, 1, n) {
		FOR(j, 1, W) {
			if( b[i] < j ) {
				L[i][j] = max(L[i-1][j-a[i]] + b[i], L[i-1][j]);
			}
			else L[i][j] = L[i-1][j];
		}
	}
	cout << L[n][W];
}

void swap(ll &a, ll &b) {
	ll temp = a;
	a = b;
	b = temp;
}

void ChoThueMay() {
	ll n; 
	ll a[MAX], b[MAX]; 
	ll c[MAX]; 
	
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i] >> b[i] >> c[i];
	}
	
	for( ll i = 1; i<n; i++ ) {
		for( ll j = i+1; j<=n; j++ ) {
			if( b[i] > b[j] ) {
				swap(b[i], b[j]);
				swap(a[i], a[j]);
				swap(c[i], c[j]);
			}
		}
	} 
	ll L[MAX]; 
	for(ll i = 1; i<=n; i++ ) {
		L[i] = c[i]; 
		for( ll j = 1; j<i; j++ ) {
			if( b[j] <= a[i] && L[i] < L[j] + c[i] ) {
				L[i] = L[j] + c[i];
			}
		}
	}
	
	ll res = 0; 
	for( ll i = 1; i<=n; i++ ) {
		if( res < L[i] ) {
			res = L[i];
		}
	}
	cout << res << endl;
}

void DayConTongK() {
	ll n; 
	ll S; 
	ll a[MAX]; 
	ll truoc[MAX];
	cin >> n >> S;
	FOR(i, 1, n) cin >> a[i];
	ll L[MAX];
	L[0] = 1;
	FOR(i, 1, n) {
		FORD(t, S, a[i]) {
			if( L[t] ==  0  && L[t-a[i]] == 1) {
				L[t] = 1;
				truoc[t] = t-a[i];
			}
		}
	}

	ll tg = S;
	while (tg) {
		cout << tg-truoc[tg] << " ";
		tg = truoc[tg];
	}
}

ll KhongAm(ll n, ll k) {
	if( k == 0 || k == n) return 1;
	return KhongAm(n-1, k-1) + KhongAm(n-1, k);
}

void XauConMax() {
	string X, Y;
	cout << "Nhap xau X: "; cin >> X; 
	cout << "Nhap xau Y: "; cin >> Y;
	ll L[200][200];
	ll m = X.length();
	ll n = Y.length();
	FOR(i, 0, m) L[i][0] = 0;
	FOR(j, 0, n) L[0][j] = 0;
	FOR(i, 1, m) {
    	FOR(j, 1, n) {
           if (X[i] == Y[j]) L[i][j] = L[i-1][j-1]+1;
           else L[i][j] = max(L[i-1][j] , L[i][j-1]);	
   		}
    }
    FOR(i, 1, m) {
    	FOR(j, 1, n) {
    		cout << L[i][j];			
    	}
    }
}

void optimize() {
    int n;
    int a[10000];
    cout << "Nhap n: "; cin >> n;
    a[0] = - INT_MAX;
    a[n+1] = INT_MAX;
  
    int L[10000];
    L[n+1] = 1;
  
    FOR(i, 1, n) {
          cin >> a[i];
          L[i] = 0;
    }
  
    FORD(i, n, 0) {
        int jMax = n+1;
        int LMax = 0;
        FOR(j, i+1, n+1) {
            if(L[j]>LMax && a[j]>a[i]) {
                LMax = L[j];
                jMax = j;
            }
        }
        L[i] = L[jMax] +1;
    }
  
    cout << "Do dai xau tang dai nhat: " << L[0]-2 << endl; 
  
}

void Menu() {
	ll c;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Nhan hai ma tran" << endl
			 << "2. Dem so cach chia STN n thanh tong cac so nho hon n" << endl
			 << "3. Dem so nghiem nguyen khong am cua phuong trinh X1 + ... + Xn = k" << endl
			 << "4. Tim day con trong day so co tong cac phan tu bang k" << endl
			 << "5. Giai bai toan cai tui" << endl
			 << "6. Giai bai toan cho thue may" << endl
			 << "7. Giai bai toan tim day con tang dai nhat" << endl
			 << "8. Bien doi xau" << endl
			 << "9. Tim xau con chung dai nhat giua xau X va Y" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				Mul();
				break;
			}
			case 2: {
				ll n;
				cout << "Nhap n: "; cin >> n; 
				cout << "Ket qua: " << F(n,n) << endl;
				break;
			}
			case 3: {
				ll n, k;
				cout << "Nhap n: "; cin >> n; 
				cout << "Nhap k: "; cin >> k;
				cout << "So nghiem nguyen khong am :" << KhongAm(n-1+k, k);
				break;
			}
			case 4: {
				DayConTongK();
				break;
			}
			case 5: {
				CaiTui();
				break;
			}
			case 6: {
				ChoThueMay();
				break;
			}
			case 7: {
				optimize();
				break;
			}
			case 8: {
				BienDoiXau();
				break;
			}
			case 9: {
				XauConMax();
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

