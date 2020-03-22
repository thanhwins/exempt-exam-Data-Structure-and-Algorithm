// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)
#define maxn 1000111
using namespace std;
const ll base = 1e9 + 7;

void Display(int a[], int n) {
	cout << "Day An: ";
	FOR(i, 0, n-1) cout << a[i] << " ";
	cout << endl;
}

int Sequencial(int a[], int n, int x) {
	FOR(i, 0, n-1)
		if (x == a[i])
			return i+1;
	return -1;
}
int Interpolation(int a[], int n, int x) {
	int low = 0, high = n-1, mid;
	while (a[low] <= x && a[high] >= x) {
		if (a[high] - a[low] == 0) return (low+high)/2;
		mid = low + ((x-a[low]) * (high-low)) / (a[high] - a[low]);
		if (a[mid] < x) low = mid + 1;
		else if (a[mid] > x) high = mid - 1;
		else return mid;
	}
	if (a[low] == x) return low;
	return -1;
}

typedef pair <ll, ll> rr;
rr b[100];

int Binary(int a[], int n, int x) {
	FOR(i, 0, n - 1){
		b[i].first = a[i];
		b[i].second = i + 1;
	}
	sort(b, b + n);
	
	int low = 0, high = n-1, mid = (low+high)/2;
	while (low <= high) {
		if (b[mid].first < x) low = mid+1;
		else if (b[mid].first > x) high = mid-1;
		else return mid;
		mid = (low+high)/2;
	}
	return -1;
}

int fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 
			377, 610, 98,1597, 2584, 4181, 6765, 10946, 17711, 28657, 
			46368, 75025, 121393, 196418, 317811, 514229, 832040, 
			1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 
			24157817, 39088169, 63245986, 102334155, 165580141 };

int Fibo(int a[], int n, int x) {
	FOR(i, 0, n - 1){
		b[i].first = a[i];
		b[i].second = i + 1;
	}
	sort(b, b + n);
	int inf = 0, pos, k;
	int kk = -1, nn = -1;
	if (nn != n) {
		k = 0;
		while (fib[k] < n)
			k++;
	}
	else k = kk;
	while (k > 0) {
		pos = inf + fib[--k];
		if (pos >= n || x < b[pos].first);
		else if (x > b[pos].first) {
			inf = pos + 1;
			k--;
		}
		else return pos;
	}
	return -1;
}

struct node {
	int infor;
	node *left, *right;
};

node *GetNode() {
	node *p;
	p = new(node);
	return p;
}

bool Empty(node *p) {
	return (p == NULL);	
}

node *MakeNode(int x) {
	node *p;
	p = GetNode();
	p -> infor = x;
	p -> left = p -> right = NULL;
	return p;
}

node *MakeRoot(node *T, int x) {
	if (T == NULL) {
		T = MakeNode(x);
	}
	return T;
}

node *Search(node *T, ll x) {
	if (T != NULL) {
		if (x > T -> infor) return (Search(T -> right, x));
		else if (x < T -> infor) return (Search(T -> left, x));
		else return T;
	}
	else return NULL;
}


void Add(node *T, int x) {
	node *p, *q;
	p = q = T;
	while (p -> infor != x && q != NULL) {
		p = q;
		if (x < p -> infor) 
			q = p -> left;
		else q = p -> right;
	}
	if (x == p -> infor) {
		cout << "Node da ton tai" << endl;
		return;
	}
	node *r = MakeNode(x);
	if (x < p -> infor)
		p -> left = r;
	else p -> right = r;
}

ll POW[maxn], hashT[maxn];
ll getHashT(int i, int j) {
	return (hashT[j] - hashT[i-1]*POW[j-i+1] + base*base) % base;
}

void Menu() {
	int c;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Tim kiem tuyen tinh" << endl
			 << "2. Tim kiem noi suy" << endl
			 << "3. Tim kiem nhi phan" << endl
			 << "4. Tim kiem Fibonacci" << endl
			 << "5. Tim kiem tren cay nhi phan" << endl
			 << "6. Tim kiem dua vao ham bam" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				int a[5] = {3, 2, 5, 1, 4};
				int n = sizeof(a)/sizeof(a[0]);
				Display(a, n);
				int x, temp;
				cout << "Nhap x: "; cin >> x;
				temp = Sequencial(a, n, x);
				cout << endl;
				if (temp == -1) cout << "Khong tim thay x trong day An!" << endl;
				else cout << x << " nam o vi tri a[" << temp << "]" << endl;
				break;
			}
			case 2: {
				int a[5] = {3, 2, 5, 1, 4};
				int n = sizeof(a)/sizeof(a[0]);
				Display(a, n);
				int x, temp;
				cout << "Nhap x: "; cin >> x;
				temp = Interpolation(a, n, x);
				cout << endl;
				if (temp == -1) cout << "Khong tim thay x trong day An!" << endl;
				else cout << x << " nam o vi tri a[" << temp << "]" << endl;
				break;
			}
			case 3: {
				int a[5] = {3, 2, 5, 1, 4};
				int n = sizeof(a)/sizeof(a[0]); cout << n << endl;
				Display(a, n);
				int x, temp;
				cout << "Nhap x: "; cin >> x; 
				temp = Binary(a, n, x);
				cout << endl;
				if (temp == -1) cout << "Khong tim thay x trong day An!" << endl;
				else cout << x << " nam o vi tri a[" << b[temp].second << "]" << endl;
				break;
			}
			case 4: {
				int a[5] = {3, 2, 5, 1, 4};
				int n = sizeof(a)/sizeof(a[0]);
				Display(a, n);
				int x, temp;
				cout << "Nhap x: "; cin >> x;
				temp = Fibo(a, n, x);
				cout << endl;
				if (temp == -1) cout << "Khong tim thay x trong day An!" << endl;
				else cout << x << " nam o vi tri a[" << b[temp].second << "]" << endl;
				break;
			}
			case 5: {
				int a[5] = {3, 2, 5, 1, 4};
				int n = sizeof(a)/sizeof(a[0]);
				Display(a, n);
				node *T = NULL;
				T = MakeRoot(T, a[0]);
				FOR(i, 1, 4) Add(T, a[i]);
				int x, temp;
				cout << "Nhap x: "; cin >> x;
				node *p = Search(T, x);
				if (p == NULL) cout << "Khong tim thay x trong day An!" << endl;
				else cout << "YES" << endl;
				break;
			}
			case 6: {
				string T, P;
				cout << "Nhap T: "; cin >> T;
				cout << "Nhap P: "; cin >> P;
				int m = T.size(), n = P.size();
				cout << "Tim vi tri cua P trong T: ";
				T = " " + T; P = " " + P;
				POW[0] = 1; hashT[0] = 0;
				FOR(i, 1, m) POW[i] = (POW[i-1]*26) % base;
				FOR(i, 1, m) hashT[i] = (hashT[i-1]*26 + T[i] - 'a') % base;	
				ll hashP = 0;
				FOR(i, 1, n) hashP = (hashP*26 + P[i] - 'a') % base;
				FOR(i, 1, m-n+1) 
					if (hashP == getHashT(i, i+n-1))
						cout << i << " ";			
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

