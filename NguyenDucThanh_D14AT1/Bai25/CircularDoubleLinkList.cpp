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
	string val;
	ll d;
	node *next, *prev;
} *start, *last;

class Circular_LL {
public: 
	node *create(string);
	void insert_begin(string);
	void display();
	Circular_LL() {
		start = NULL;
		last = NULL;
	}
};

node *Circular_LL :: create(string n) {
	node *temp;
	temp = new (node);
	temp -> val = n;
	temp -> d = 1;
	temp -> next = NULL;
	temp -> prev = NULL;
	return temp;
}

void Circular_LL :: insert_begin(string s) {
	node *temp, *p;
	temp = create(s);
	if (start == last && last == NULL) {
		start = last = temp;
		start -> next = last -> next = NULL;
		start -> prev = last -> prev = NULL;
		dem++;
	}
	else {
		node *t = start;
		while (t != last) {
			if (s == t -> val) {
				t -> d++;
				return;
			}
			else t = t -> next;
		}
		if (t -> val != s) {
			last -> next = temp;
			temp -> prev = last;
			last = temp;
			start -> prev = last;
			last -> next = start;
			dem++;
		}
		else t -> d++;
	}
}

void Circular_LL :: display() {
	node *temp;
	if (start == last && last == NULL) {
		cout << "Tep rong!" << endl;
		return;
	}
	temp = start;
	cout << dem << endl;
	FOR(i, 1, dem) {
		cout << temp -> val << " " << temp -> d << endl;
		temp = temp -> next;
	}
}

int main() {
	ll n;
	Circular_LL CLL;
	f >> n;
	FOR(i, 1, n) {
		string s;
		f >> s;
		CLL.insert_begin(s);
	}
	CLL.display();
	return 0;
}

