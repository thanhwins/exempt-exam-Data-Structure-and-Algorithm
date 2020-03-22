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
	node *next;
	node *prev;
} *start;

class Sorted_LL {
public: 
	node *create(string);
	void insert_begin(string);
	void insert_last(string);
	void display();
	Sorted_LL() {
		start = NULL;
	}
};

node *Sorted_LL :: create(string n) {
	node *temp, *s;
	temp = new (node);	
	temp -> val = n;
	temp -> d = 1;
	temp -> next = NULL;
	return temp;
}

void Sorted_LL :: insert_last(string s) {
	node *temp, *p;
	temp = create(s);
	p = start;
	if (start == NULL) {
		temp -> prev = NULL;
		start = temp;
		dem++;
	}
	else {
		while (p -> next != NULL) {
			if (s == p -> val) {
				p -> d++; 
				return;
			}
			else p = p -> next;
		}
		if (p -> val != s) {
			p -> next = temp;
			temp -> prev = p;
			dem++;
		}
		else p -> d++;
	}
}

void Sorted_LL :: display() {
	node *temp;
	if (start == NULL) {
		cout << "Tep rong!" << endl;
		return;
	}
	temp = start;
	cout << dem << endl;
	while (temp != NULL) {
		cout << temp -> val << " " << temp -> d << endl;
		temp = temp -> next;
	}
}

int main() {
	ll n;
	Sorted_LL SLL;
	f >> n;
	FOR(i, 1, n) {
		string s;
		f >> s;
		SLL.insert_last(s);
	}
	SLL.display();
	return 0;
}

