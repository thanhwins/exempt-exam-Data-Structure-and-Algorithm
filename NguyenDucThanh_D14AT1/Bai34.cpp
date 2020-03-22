// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

void Display(ll a[]) {
	FOR(i, 0, sizeof(a)) {
		cout << a[i] << " ";
	}
	cout << endl;
}

ll Partition(ll a[], ll l, ll h) {
	ll x = a[h];
	ll i = l - 1;
	FOR(j, l, h-1) {
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[h]);
	return (i+1);
}
void Quick_Sort(ll a[], ll l, ll h) {
	if (l < h) {
		ll p = Partition(a, l, h);
		Quick_Sort(a, l, p-1);
		Quick_Sort(a, p+1, h);
	}
	
}

void Merge(ll a[], ll l, ll m, ll r) {
	ll i, j, k, c[MAX];
	i = l; k = l; j = m+1;
	while (i <= m && j <= r) {
		if (a[i] < a[j]) {
			c[k++] = a[i++]; 
		}
		else c[k++] = a[j++];
	}
	while (i <= m) c[k++] = a[i++];
	while (j <= r) c[k++] = a[j++];
	FOR(i, l, k-1) a[i] = c[i];
}

void Merge_Sort(ll a[], ll l, ll r) {
	if (l < r) {
		ll m = (l+r)/2;
		Merge_Sort(a, l, m);
		Merge_Sort(a, m+1, r);
		Merge(a, l, m, r);
	}
}

ll Binary_Search(ll a[], ll l, ll r, ll x) {
	if (r >= l) {
		ll mid = l + (r-l)/2;
		if (a[mid] == x) 
			return mid;
		else if (a[mid] < x)
			return Binary_Search(a, mid+1, r, x);
		else 
			return Binary_Search(a, l, mid-1, x);
	}
	return -1;
}

ll maxCrossingSum(ll a[], ll l, ll m, ll h) {
	ll sum = 0, left_sum = INT_MIN, right_sum = INT_MIN;
	FORD(i, m, l) {
		sum += a[i];
		if (sum > left_sum) left_sum = sum;
	}
	sum = 0;
	FOR(i, m+1, h) {
		sum += a[i];
		if (right_sum < sum) right_sum = sum;
	}
	return left_sum+right_sum;
}

ll max(ll a, ll b, ll c) {
	if (a >= c && a >= b) return a;
	else if (b >= a && b >= c) return b;
	else if (c >= a && c >= b) return c;
}

ll maxSubArraySum(ll a[], ll l, ll h) {
	if (l == h) return a[l];
	ll m = (l+h) / 2;
	return max(maxSubArraySum(a, l, m), maxSubArraySum(a, m+1, h), maxCrossingSum(a, l, m, h));
}

void Mul(ll a[], ll b[], ll c[], ll m, ll n) {
	ll z = m + n;
	FOR(i, 0, z){
		c[i] = 0;
	}
	FOR(i, 0, z) {
		FOR(j, 0, n) {
			FOR(k, 0, m) {
				if (j+k == i)	
					c[i] += a[j] * b[k];	
			}
		}
	}
} 

void Xuat(ll c[], ll m){
	FOR(i, 0, m-1)
		cout << c[i] << "x^" << i << " + ";
	cout << c[m] << "x^" << m << endl;
}

void Menu() {
	ll c;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Thuat toan nhan hai da thuc" << endl
			 << "2. Tim day con co tong lon nhat" << endl
			 << "3. Binary Search" << endl
			 << "4. Quick Sort" << endl
			 << "5. Merge Sort" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				ll n = 1, m = 1, z = m + n;
				ll a[] = {2,1};
				ll b[] = {1,2};
				ll c[MAX];
				cout << "P(x) = "; Xuat(a, n);
				cout << "Q(x) = "; Xuat(b, m);
				Mul(a, b, c, m, n);
				cout << "P(x) * Q(x) = "; Xuat(c, m+n);
				break;
			}
			case 2: {
				ll a[] = {-2, -5, 6, -2, -3, 1, 5, -6};
				cout << "Ban dau: ";
				FOR(i, 0, 7) cout << a[i] << " ";
				cout << endl;
				cout << "Tong day con lon nhat: " << maxSubArraySum(a, 0, 7) << endl;
				break;
			}
			case 3: {
				ll a[5] = {1, 2, 3, 4, 5};
				cout << "Ban dau: ";
				Display(a);
				ll x;
				cout << "Nhap so muon tim: "; cin >> x;
				ll temp = Binary_Search(a, 0, 4, x);
				if (temp == -1) 
					cout << "Khong tim thay!" << endl;
				else cout << "Tim thay x o vi tri a[" << temp+1 << "]" << endl;
				break;
			}
			case 4: {
				ll a[5] = {3, 2, 5, 1, 4};
				cout << "Ban dau: ";
				Display(a);
				Quick_Sort(a, 0, 4);
				cout << "Sap xep: ";
				Display(a);
				break;
			}
			case 5: {
				ll a[5] = {3, 2, 5, 1, 4};
				cout << "Ban dau: ";
				Display(a);
				Merge_Sort(a, 0, 4);
				cout << "Sap xep: ";
				Display(a);
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

