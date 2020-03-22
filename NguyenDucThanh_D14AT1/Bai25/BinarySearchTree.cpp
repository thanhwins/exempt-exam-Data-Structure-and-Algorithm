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
};
node *T = NULL;

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
	p = q = T;
	
	while (q != NULL) {
		p = q;
		if (s == p -> infor) {
			p -> d++;
			return;
		}
		if (s < p -> infor) 
			q = p -> left;
		else q = p -> right;
	}
	
	node *r = MakeNode(s);
	if (s < p -> infor) {
		dem++; 
		p -> left = r;
	}
	else {
		dem++; 
		p -> right = r;
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

