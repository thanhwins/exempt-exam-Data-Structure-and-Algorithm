// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

void Display(ll a[], ll n) {
	FOR(i, 0, n-1) cout << a[i] << " ";
	cout << endl;
}

void convert (ll n, ll x) {
	char digits[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char output[MAX];
	while (n <= 0) {
		return;
	}
	convert(n/x, x);
	cout << digits[n%x];	
}
void DoiCoSo() {
	ll n, b; 
	cout << "Nhap n: "; cin >> n;
	cout << "Nhap b: "; cin >> b;
	cout << "Ket qua: ";
	convert(n, b);
}

ll Tong(ll n) {
	if (n == 0) return 0;
	return (n%10 + Tong(n/10));
}

void TongN() {
	ll n; 
	cout << "Nhap n: "; cin >> n;
	ll temp = Tong(n);
	cout << "Ket qua: " << temp << endl;
}

ll Tong(ll a[], ll n) {
	if (n == 1) return a[0];
	return (a[n-1] + Tong(a, n-1));
}

void TongA() {
	ll a[] = {1, 2, 3, 4, 5};
	ll n = sizeof(a) / sizeof(a[0]);
	cout << "Day An: ";
	Display(a, n);
	ll temp = Tong(a, n);
	cout << "Ket qua: " << temp << endl;
}

void reverse(char a[], ll index, ll n) {
	char temp = a[index];
	a[index] = a[n - index];
	a[n - index]= temp;
	if (index == n/2) return;
	reverse(a, index+1, n);
}

void Dao() {
	char a[] = "ABCDE";
	cout << "Ban dau: " << a << endl;
	ll n = strlen(a);
	reverse(a, 0, n-1);
	cout << "Ket qua: " << a << endl;
}

void swap(ll &a, ll &b) {
	ll temp = a;
	a = b; 
	b = temp;	
}

void select(ll a[], ll index, ll n) {
	ll min = index;
	FOR(j, min+1, 4) {
			if (a[min] > a[j])
				min = j;
	}
	swap(a[index], a[min]);
	if (index == n-1) return;	
	select(a, index+1, n);
}

void Selection() {
	ll a[] = {1, 4, 3, 5, 2};
	ll n = sizeof(a) / sizeof(a[0]);
	cout << "Ban dau: "; Display(a, n);
	select(a, 0, n-1);
	cout << "Ket qua: "; Display(a, n);
}

void insert(ll a[], ll key, ll n) {
	ll temp = a[key];
	ll j = key-1;
	while (j >= 0 && temp < a[j]) {
		a[j+1] = a[j];
		j--;
	}
	a[j+1] = temp;
	if (key == n) return;
	insert(a, key+1, n);
}

void Insertion() {
	ll a[] = {1, 4, 3, 5, 2}; 
	ll n = sizeof(a) / sizeof(a[0]); 
	cout << "Ban dau: "; Display(a, n);
	insert(a, 0, n-1);
	cout << "Ket qua: "; Display(a, n);
}

ll Sequencial(ll a[], ll ind, ll n, ll x) {
	if (ind > n) return -1;
	if (ind <= n && x == a[ind]) return ind+1;
	else Sequencial (a, ind+1, n, x);
}

void Sequencial_Sort() {
	ll a[] = {3, 2, 5, 1, 4};
	ll n = sizeof(a)/sizeof(a[0]);
	Display(a, n);
	ll x, temp;
	cout << "Nhap x: "; cin >> x;
	temp = Sequencial(a, 0, n-1, x);
	cout << endl;
	if (temp == -1) cout << "Khong tim thay x trong day An!" << endl;
	else cout << x << " nam o vi tri a[" << temp << "]" << endl;
}

struct node {
	ll infor;
	node *left, *right;
};

node *GetNode() {
	node *p;
	p = new(node);
	return p;
}

node *MakeNode(ll x) {
	node *p;
	p = GetNode();
	p -> infor = x;
	p -> left = p -> right = NULL;
	return p;
}

node *MakeRoot(node *T, ll x) {
	if (T == NULL) {
		T = MakeNode(x);
	}
	return T;
}

node *Search(node *T, ll x) {
	node *p;
	if (T -> infor == x) return T;
	if (T == NULL) return NULL;
	p = Search(T -> left, x); 
	if (p == NULL) p = Search(T -> right, x);
	return p;
}

void Add_Left(node *T, ll x, ll y) {
	node *p, *q;
	p = Search(T, x);
	q = MakeNode(y);
	p -> left = q;
}

void Add_Right(node *T, ll x, ll y) {
	node *p, *q;
	p = Search(T, x);
	q = MakeNode(y);
	p -> right = q;
}

void NLR(node *T) {
	if (T != NULL) {
		cout << T -> infor << " ";
		NLR(T -> left);
		NLR(T -> right);
	}
} 

ll Size(node *T) {
	if (T == NULL) return 0;
	return (Size(T -> left) + 1 + Size(T -> right));
}

ll identicalTrees(node *T1, node *T2) {
	if (T1 == NULL && T2 == NULL) return 1;
	if (T1 != NULL && T2 != NULL) 
		return (T1 -> infor == T2 -> infor 
		&& identicalTrees(T1 -> left, T2 -> left) 
		&& identicalTrees(T1 -> right, T2 -> right));
	return 0;
}

ll maxHigh(node *T) {
	if (T == NULL) return 0;
	else {
		ll lHigh = maxHigh(T -> left); 
		ll rHigh = maxHigh(T -> right);
		if (lHigh > rHigh) return (lHigh+1);
		else return (rHigh+1);
	}
}

void mirror(node *T) {
	if (T == NULL) return;
	node *temp;
	mirror(T -> left);
	mirror(T -> right);
	temp = T -> left;
	T -> left = T -> right;
	T -> right = temp;
}

void Menu() {
	ll c;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Doi so tu nhien n thanh so o he co so b" << endl
			 << "2. Tim tong tat ca cac chu so cua so tu nhien n" << endl
			 << "3. Tim tong tat ca cac phan tu cua day so An" << endl
			 << "4. Dao xau co do dai n" << endl
			 << "5. Thuat toan Selection Sort de quy" << endl
			 << "6. Thuat toan Insertion Sort de quy" << endl
			 << "7. Thuat toan Sequencial Search de quy" << endl
			 << "8. Tim kich co cua cay nhi phan bang de quy" << endl
			 << "9. Xac dinh hai cay nhi phan giong nhau bang de quy" << endl 
			 << "10. Xac dinh do cao cua cay nhi phan bang de quy" << endl
			 << "11. Tao nen cay phan chieu bang de quy" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					DoiCoSo();
					break;
				}
				case 2: {
					TongN();
					break;
				}
				case 3: {
					TongA();
					break;
				}
				case 4: {
					Dao();
					break;
				}
				case 5: {
					Selection();
					break;
				}
				case 6: {
					Insertion();
					break;
				}
				case 7: {
					Sequencial_Sort();
					break;
				}
				case 8: {
					node *T = NULL;
					T = MakeRoot(T, 2);
					Add_Left(T,2,1); 
					Add_Left(T,1,3); 
					Add_Left(T,3,4);
					Add_Right(T,2,5); 
					Add_Right(T,1,6); 
					Add_Right(T,3,7);
					cout << "Size: " << Size(T) << endl;
					break;
				}
				case 9: {
					node *T1 = NULL, *T2 = NULL;
					T1 = MakeRoot(T1, 2); T2 = MakeRoot(T2, 2);
					Add_Left(T1,2,1); Add_Left(T2,2,1);
					Add_Left(T1,1,3); Add_Left(T2,1,3); 
					Add_Left(T1,3,4); Add_Left(T2,3,4);
					Add_Right(T1,2,5); Add_Right(T2,2,5);
					Add_Right(T1,1,6); Add_Right(T2,1,6);
					Add_Right(T1,3,7); Add_Right(T2,3,7);
					if (identicalTrees(T1, T2)) cout << "Hai cay giong nhau!" << endl;
					else cout << "Hai cay khong giong nhau!" << endl;
					break;
				}
				case 10: {
					node *T = NULL;
					T = MakeRoot(T, 2);
					Add_Left(T,2,1); 
					Add_Left(T,1,3); 
					Add_Left(T,3,4);
					Add_Right(T,2,5); 
					Add_Right(T,1,6); 
					Add_Right(T,3,7);
					cout << "Chieo cao cay: " << maxHigh(T) << endl;
					break;
				}
				case 11: {
					node *T = NULL;
					T = MakeRoot(T, 2);
					Add_Left(T,2,1); 
					Add_Left(T,1,3); 
					Add_Left(T,3,4);
					Add_Right(T,2,5); 
					Add_Right(T,1,6); 
					Add_Right(T,3,7);
					cout << "(Duyet theo thu tu truoc) " << endl;
					cout << "Cay ban dau:    "; NLR(T);
					mirror(T);
					cout << "\nCay phan chieu: "; NLR(T);
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

