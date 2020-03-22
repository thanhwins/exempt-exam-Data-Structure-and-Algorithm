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
	node *p;
	if (T -> infor == x) return T;
	if (T == NULL) return NULL;
	p = Search(T -> left, x); 
	if (p == NULL) p = Search(T -> right, x);
	return p;
}

void Add_Left(node *T) {
	node *p, *q;
	ll x, y;
	cout << "Nhap gia tri cua cha: "; cin >> x;
	p = Search(T, x);
	if (p == NULL) {
		cout << "Node cha khong co thuc" << endl;
		return;
	}
	cout << "Nhap gia tri node con muon them: "; cin >> y;
	if (p -> left != NULL) {
		cout << "Node cha x da co nut con trai" << endl;
	}
	else {
		q = MakeNode(y);
		p -> left = q;
	}
}

void Add_Right(node *T) {
	node *p, *q;
	ll x, y;
	cout << "Nhap gia tri cua cha: "; cin >> x;
	p = Search(T, x);
	if (p == NULL) {
		cout << "Node cha khong co thuc" << endl;
		return;
	}
	cout << "Nhap gia tri node con muon them: "; cin >> y;
	if (p -> right != NULL) {
		cout << "Node cha x da co nut con phai" << endl;
	}
	else {
		q = MakeNode(y);
		p -> right = q;
	}
}

void Remove_Left(node *T, ll x) {
	node *p, *q;
	p = Search(T, x);
	if (p == NULL) {
		cout << "Node x khong co tren cay" << endl;
	} 
	else if ((p -> left -> right) != NULL || (p -> left -> left) != NULL) {
		cout << "Node x co nhanh cay con trai. Khong loai bo duoc!" << endl;
	}
	else {
		q = p -> left;
		p -> left = NULL;
		free(p);
	}
}

void Remove_Right(node *T, ll x) {
	node *p, *q;
	p = Search(T, x);
	if (p == NULL) {
		cout << "Node x khong co tren cay" << endl;
	} 
	else if (p -> right -> right != NULL || p -> right -> left != NULL) {
		cout << "Node x co nhanh cay con phai. Khong loai bo duoc!" << endl;
	}
	else {
		q = p -> right;
		p -> right = NULL;
		free(p);
	}
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
			     << "2. Them nut la ben trai cho node x" << endl
			     << "3. Them nut la ben phai cho node x" << endl
			     << "4. Loai nut la ben trai cua nut x" << endl
			     << "5. Loai nut la ben phai cua nut x" << endl
			     << "6. Tim node co gia tri x tren cay" << endl
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
					Add_Left(T);
					break;
				}
				case 3: {
					Add_Right(T);
					break;
				}
				case 4: {
					ll x;
					cout << "Nhap gia tri node cha: "; cin >> x;
					Remove_Left(T, x);
					break;
				}
				case 5: {
					ll x;
					cout << "Nhap gia tri node cha: "; cin >> x;
					Remove_Right(T, x);
					break;
				}
				case 6: {
					ll x;
					cout << "Nhap gia tri node can tim: "; cin >> x;
					node *q = Search(T, x);
					if (q == NULL) cout << "YES" << endl;
					else cout << "NO" << endl;
					break;
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

