// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

fstream f ("data.txt", ios :: in);
ll dem = 0;

struct node {
	string infor;
	ll d;
	node *left, *right;
} *T = NULL;

node *GetNode() {
	node *p;
	p = new(node);
	return p;
}

bool Empty(node *p) {
	return (p == NULL);	
}

node *MakeNode(string x) {
	node *p;
	p = GetNode();
	p -> infor = x;
	p -> d = 1;
	p -> left = p -> right = NULL;
	return p;
}

void Add(string s) {
	if (T == NULL) {
		T = MakeNode(s);
		dem++;
		return;
	}
	node *p, *q;
	p = T;
	while (p -> left != NULL) {
		if (p -> infor == s) {
			p -> d++;
			return;
		}
		p = p -> left;
	}
	if (p -> infor == s) p -> d++;
	else {
		q = MakeNode(s);
		p -> left = q;
		dem++;
	}
}

void NLR(node *T) {
	if (T != NULL) {
		cout << T -> infor << " " << T -> d << endl;
		NLR(T -> left);
		NLR(T -> right);
	}
} 

int main() {
	ll n;
	f >> n;
	FOR(i, 1, n) {
		string s;
		f >> s;
		Add(s);
	}
	cout << dem << endl;
	NLR(T);
	return 0;
}

