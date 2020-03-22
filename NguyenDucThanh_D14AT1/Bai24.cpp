// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

struct node {
	ll infor;
	node *left, *right;
} *Tree;

node *GetNode() {
	node *p;
	p = new(node);
	return p;
}
bool Empty(node *p) {
	return (p == NULL);	
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
	if (T != NULL) {
		if (x > T -> infor) return (Search(T -> right, x));
		else if (x < T -> infor) return (Search(T -> left, x));
		else return T;
	}
	else return NULL;
}

void Add(node *T) {
	node *p, *q;
	ll x;
	cout << "Nhap gia tri node muon them: "; cin >> x;
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

node *minValueNode(node *T) {
	node *p = T;
	while (p -> left != NULL) p = p -> left;
	return p;
}

node *Remove(node *T, ll x) {
	if (T == NULL) return T;
	if (x < T -> infor) T -> left = Remove(T -> left, x);
	else if (x > T -> infor) T -> right = Remove(T -> right, x);
	else {
		if (T -> left == NULL) {
			node *temp = T -> right;
			free(T);
			return temp;
		}
		else if (T -> right == NULL) {
			node *temp = T -> left;
			free(T);
			return temp;
		}
		node *temp = minValueNode(T -> right);
		T -> infor = temp -> infor;
		T -> right = Remove(T -> right, temp -> infor);
	}
	return T;
}

node *Rotate_Left(node *T) {
	node *p = T;
	if (T == NULL) cout << "Khong ton tai cay!" << endl;
	else if (T -> right == NULL) cout << "Khong co cay con phai!" << endl;
	else {
		p = T -> right;
		T -> right = p -> left;
		p -> left = T;
	}
	return p;
}

node *Rotate_Right(node *T) {
	node *p;
	if (T == NULL) cout << "Khong ton tai cay!" << endl;
	else if (T -> left == NULL) cout << "Khong co cay con trai!" << endl;
	else {
		p = T -> left;
		T -> left = p -> right;
		p -> right = T;
	}
	return p;
}

void NLR(node *T) {
	if (T != NULL) {
		cout << T -> infor << " ";
		NLR(T -> left);
		NLR(T -> right);
	}
} 

void LNR(node *T) {
	if (T != NULL) {
		LNR(T -> left);
		cout << T -> infor << " ";
		LNR(T -> right);
	}
} 

void LRN(node *T) {
	if (T != NULL) {
		LRN(T -> left);
		LRN(T -> right);
		cout << T -> infor << " ";
	}
} 

void NLR1(node *T) {
	stack <node*> s;
	while (true) {
		while (T != NULL) {
			cout << T -> infor << " ";
			s.push(T);
			T = T -> left;
		}
		if (s.empty()) {
			return;
		}
		T = s.top();
		s.pop();
		T = T -> right;
	}
}

void LNR1(node *T) {
	stack <node*> s;
	node *p = T;
	bool done = 0;
	while (!done) {
		if (p != NULL) {
			s.push(p);
			p = p -> left;
		}
		else {
			if (!s.empty()) {
				p = s.top();
				cout << p -> infor << " ";
				s.pop();
				p = p -> right;
			}
			else done = 1;
		}
	}
}

void LRN1(node *T) {
	stack <node*> s1;
	stack <node*> s2;
	s1.push(T);
	while (!s1.empty()) {
		node *p = s1.top();
		s1.pop();
		s2.push(p);
		if (p -> left != NULL) {
			s1.push(p -> left);
		}
		if (p -> right != NULL) {
			s1.push(p -> right);
		}
	}
	while (!s2.empty()) {
		node *p = s2.top();
		cout << p -> infor << " ";
		s2.pop();
	}
}

void Menu() {
	ll c;
	node *T = NULL;
	while (1) {
			cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			     << "1. Tao nut goc cho cay" << endl
			     << "2. Them node cho cay" << endl
			     << "3. Loai node tren cay" << endl
			     << "4. Tim node co gia tri x tren cay" << endl
			     << "5. Xoay phai node tren cay" << endl
			     << "6. Xoay trai node tren cay" << endl
			     << "7. Duyet cay theo thu tu truoc bang de quy" << endl
			     << "8. Duyet cay theo thu tu giua bang de quy" << endl
			     << "9. Duyet cay theo thu tu sau bang de quy" << endl
			     << "10. Duyet cay theo thu tu truoc khong de quy" << endl
			     << "11. Duyet cay theo thu tu giua khong de quy" << endl
			     << "12. Duyet cay theo thu tu sau khong de quy" << endl
			     << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
			cout << endl << "Ban muon thuc hien chuc nang nao? "; 
			cin >> c;
			switch (c) {
				case 1: {
					ll x;
					cout << "Nhap gia tri cua node: "; cin >> x;
					T = MakeRoot(T, x);
					break;
				}
				case 2: {
					Add(T);
					break;
				}
				case 3: {
					ll x;
					cout << "Nhap gia tri node muon loai bo: "; cin >> x;
					T = Remove(T, x);
					break;
				}
				case 4: {
					ll x;
					cout << "Nhap gia tri node can tim: "; cin >> x;
					node *q = NULL;
					q = Search(T, x);
					if (q == NULL) cout << "NO" << endl;
					else cout << "YES" << endl;
					break;
				}
				case 5: {
					T = Rotate_Right(T);
					break;
				}
				case 6: {
					T = Rotate_Left(T);
				}
				case 7: {
					NLR(T);
					break;
				}
				case 8: {
					LNR(T);
					break;
				}
				case 9: {
					LRN(T);
					break;
				}
				case 10: {
					NLR1(T);
					break;
				}
				case 11: {
					LNR1(T);
					break;
				}
				case 12: {
					LRN1(T);
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

