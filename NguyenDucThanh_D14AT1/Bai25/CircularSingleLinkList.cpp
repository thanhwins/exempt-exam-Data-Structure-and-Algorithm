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
	string word;
	ll d;
	node *next;
} *last;

class Circular_LL {
public: 
	node *create(string);
	void insert_begin(string);
	void display();
	Circular_LL() {
		last = NULL;
	}
};

node *Circular_LL :: create(string s) {
	node *temp;
	temp = new (node);
	temp -> word = s;
	temp -> d = 1;
	temp -> next = NULL;
	return temp;
}

void Circular_LL :: insert_begin(string s) {
	node *temp, *p;
	temp = create(s);
	if (last == NULL) {
		last = temp;
		temp -> next = last;
		dem++;
	}
	else {
		node *t = last;
		while (t -> next != last) {
			if (s == t -> word) {
				t -> d++;
				return;
			}
			else t = t -> next;
		}
		if (t -> word != s) {
			temp -> next = last -> next;
			last -> next = temp;
			last = temp;
			dem++;
		}
		else t -> d++;
	}
}

void Circular_LL :: display() {
	node *temp;
	if (last == NULL) {
		cout << "Tep rong!" << endl;
		return;
	}
	temp = last -> next;
	cout << dem << endl;
	while (temp != last) {
		cout << temp -> word << " " << temp -> d << endl;
		temp = temp -> next;
	}
	cout << temp -> word << " " << temp -> d << endl; 
}
	
int main() {
	ll n; f >> n;
	Circular_LL CLL;
	FOR(i, 1, n) {
		string s;
		f >> s;
		CLL.insert_begin(s);
	}
	CLL.display();
	return 0;
}

