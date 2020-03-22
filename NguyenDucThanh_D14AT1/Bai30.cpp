// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

void SinhNhiPhan() {
	ll n, a[MAX], OK = false;
	cout << "Nhap n: "; cin >> n;
	FOR(i, 1, n) {
		a[i] = 0;
	}
	
	while (!OK) {
		FOR(i, 1, n) cout << a[i] << " ";
		cout << endl;
		ll i = n;
		while (i > 0 && a[i] == 1) a[i--] = 0;
		if (i > 0) a[i] = 1;
		else OK = true;
	}
}
void SinhToHop() {
	ll n, k, a[MAX], OK = false;
	cout << "Nhap n: "; cin >> n;
	cout << "Nhap k: "; cin >> k;
	FOR(i, 1, k) a[i] = i;
	
	while (!OK) {
		FOR(i, 1, k) cout << a[i] << " ";
		cout << endl;
		int i = k;
		while (i > 0 && a[i] == n-k+i) i--;
		if (i > 0) {
			a[i]++;
			FOR(j, i+1, n) a[j] = a[i] + j - i;
		}	
		else OK = true;	
	}
}

void swap(ll &a, ll &b) {
	ll t = a;
	a = b; 
	b = t;
}

void SinhHoanVi() {
	ll n, a[MAX], OK = false;
	cout << "Nhap n: "; cin >> n;
	FOR(i, 1, n) a[i] = i;
	while (!OK) {
		FOR(i, 1, n) cout << a[i] << " ";
		cout << endl;
		ll i = n-1;
		while (i > 0 && a[i] > a[i+1]) i--;
		if (i > 0) {
			ll j = n;
			while (a[i] > a[j]) j--;
			swap(a[i], a[j]);
			ll l = i+1, r = n;
			while (l <= r) {
				swap(a[l++], a[r--]);
			}
			
		}
		else OK = true;
	}
}

ll Tong(ll a[], ll s[], ll n) {
	ll S = 0;
	FOR(i, 1, n) 
		if (a[i] == 1)
			S += s[i];
	return S;
}

void TongDayCon() {
	ll n, k, a[MAX], s[MAX], OK = false;
	cout << "Nhap n: "; cin >> n;
	cout << "Nhap k: "; cin >> k;
	cout << "Nhap day: ";
	FOR(i, 1, n) {
		cin >> s[i];
		a[i] = 0;
	}
	cout << endl;
	while (!OK) {
		if (Tong(a, s, n) == k) {
			FOR(i, 1, n) {
				if (a[i] == 1) cout << s[i] << " ";
			}
			cout << endl;
		}
		ll i = n;
		while (i > 0 && a[i] == 1) a[i--] = 0;
		if (i > 0) 
			a[i] = 1;
		else OK = true;
	}
}

ll Tong1(ll a[], ll s[], ll n) {
	ll S = 0;
	FOR(i, 1, n) 
		S += s[a[i]];
	return S;
}

void TongM() {
	ll n, a[MAX], k, m, s[MAX], OK = false;
	cout << "Nhap n: "; cin >> n;
	cout << "Nhap k: "; cin >> k;
	cout << "Nhap m: "; cin >> m;
	cout << "Nhap day: ";
	FOR(i, 1, n) cin >> s[i];
	FOR(i, 1, k) a[i] = i;
	while (!OK) {
		if (Tong1(a, s, k) == m) {
			FOR(i, 1, k) cout << s[a[i]] << " ";
			cout << endl;
		}
		int i = k;
		while (i > 0 && a[i] == n-k+i) i--;
		if (i > 0) {
			a[i]++;
			FOR(j, i+1, n) a[j] = a[i] + j - i;
		}	
		else OK = true;	
	}
}

ll k;

void SinhSTN() {
	ll n, a[MAX], S, D, R;
	cout << "Nhap n: "; cin >> n;
	a[0] = 0; a[1] = n-1; a[2] = 1;
	k = 2;
	bool OK = false;
	while (!OK) {
		FOR(j, 1, k-1) 
			cout << a[j] << " + ";
		cout << a[k] << endl;
		ll i = k;
		while (a[i] == 1) i--;
		if (i == 0) OK = true;
		else {
			a[i]--;
			S = k - i + 1;
			D = S / a[i];
			R = S % a[i];
			FOR(j, i+1, i+D) a[j] = a[i];
			k = i+D;
			if (R > 0) {
				k++;
				a[k] = R;
			}	
		}	
	}
}

void CaiTui() {
	ll n, k, a[MAX], b[MAX], c[MAX];
	bool OK = false;
	ll m = 0;
	cout << "Nhap so do vat: "; cin >> n;
	cout << "Nhap khoi luong toi da: "; cin >> k;
	FOR(i, 1, n) {
		cout << "Vat " << i << ": " << endl;
		cout << "- Gia tri: ";
		cin >> b[i];
		cout << "- Khoi luong: ";
		cin >> c[i];
	}
	FOR(i, 1, n) a[i] = 0;
	while (!OK) {
		ll v = 0, w = 0;
		FOR(i, 1, n) {
			v += b[i] * a[i];
			w += c[i] * a[i];
		}
		if (w <= k && v > m) 
			m = v;
		ll i = n;
		while (i > 0 && a[i] == 1) {
			a[i] = 0;
			i--;
		}
		if (i > 0) a[i] = 1;
		else OK = true;
	}
	cout << "Gia tri lon nhat co the: " << m << endl;
}

void DuLich() {
	ll n, a[MAX], d[MAX][MAX];
	cout << "So thanh pho: "; cin >> n;
	ll m = 1e9 + 7;
	bool OK = false;
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> d[i][j];
		}
	}
	FOR (i, 1, n) a[i] = i;
	while (!OK) {
		ll S = 0;
		FOR(i, 2, n) S += d[a[i-1]][a[i]];
		S += d[a[n]][a[1]];
		if (S < m) m = S;
		ll i = n-1;
		while (i > 0 && a[i] > a[i+1]) i--;
		if (i > 0) {
			ll j = n;
			while (a[i] > a[j]) j--;
			swap(a[i], a[j]);
			ll l = i+1, r = n;
			while (l <= r) {
				swap(a[l++], a[r--]);
			}
		}
		else OK = true;
	}
	cout << "Chi phi it nhat: " << m << endl;
}

void HienThi(ll a[], ll n) {
	FOR(i, 1, n) {
		FOR(j, 1, a[i] - 1)
			cout << " . ";
		cout << " x ";
		FOR(j, a[i] + 1, n)
			cout << " . ";
		cout << endl;
	}
	cout << endl << endl;
}

void QuanHau() {
	ll n, a[MAX], b[MAX], c[MAX];
	cout << "So quan hau: "; cin >> n;
	bool OK = false;
	FOR(i, 1, n) a[i] = i;
	while (!OK) {
		int kt = 1;
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++) {
			if (b[i + a[i]] == 1 || c[i - a[i] + n] == 1) {
				kt = 0;
				break;
			}
			b[i + a[i]] = 1;
			c[i - a[i] + n] = 1;
		}
		if (kt) 
			HienThi(a, n);
		ll i = n-1;
		while (i > 0 && a[i] > a[i+1]) i--;
		if (i > 0) {
			ll j = n;
			while (a[i] > a[j]) j--;
			swap(a[i], a[j]);
			ll l = i+1, r = n;
			while (l <= r) {
				swap(a[l++], a[r--]);
			}
		}
		else OK = true;
	}
}

void Menu() {
	ll c;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Liet ke cac xau nhi phan co do dai n" << endl
			 << "2. Liet ke cac to hop chap k" << endl
			 << "3. Liet ke cac hoan vi" << endl
			 << "4. Liet ke cac cach chia so n thanh tong cac so tu nhien nho hon n" << endl
			 << "5. Liet ke cac day con cua An sao cho tong cac phan tu dung bang K" << endl
			 << "6. Liet ke cac day con K phan tu sao cho tong cac phan tu cua day con bang M" << endl
			 << "7. Giai bai toan cai tui" << endl
			 << "8. Giai bai toan nguoi di du lich" << endl
			 << "9. Giai bai toan quan hau" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				SinhNhiPhan();
				break;
			}
			case 2: {
				SinhToHop();
				break;
			}
			case 3: {
				SinhHoanVi();
				break;
			}
			case 4: {
				SinhSTN();
				break;
			}
			case 5: {
				TongDayCon();
				break;
			}
			case 6: {
				TongM();
				break;
			}
			case 7: {
				CaiTui();
				break;
			}
			case 8: {
				DuLich();
				break;
			}
			case 9: {
				QuanHau();
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

