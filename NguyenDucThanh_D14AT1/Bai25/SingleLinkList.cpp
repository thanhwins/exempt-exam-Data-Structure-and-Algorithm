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
} *start;

class Single_LL {
public: 
	node *create(string);
	void insert_last(string);
	void display();
	Single_LL() {
		start = NULL;
	}
};

node *Single_LL :: create(string n) {
	node *temp, *s;
	temp = new (node);	
	temp -> word = n;
	temp -> d = 1;
	temp -> next = NULL;
	return temp;
}

void Single_LL :: insert_last(string s) {
	
	node *temp, *p;
	temp = create(s);
	p = start;
	if (start == NULL) {
		start = temp;
		start -> next = NULL;
		dem++;
	}
	else {
		while (p -> next != NULL) {
			if (s == p -> word) {
				p -> d++; 
				return;
			}
			else p = p -> next;
		}
		if (p -> word != s) {
			temp -> next = NULL;
			p -> next = temp;
			dem++;
		}
		else p -> d++;
	}
}

void Single_LL :: display() {
	node *temp;
	if (start == NULL) {
		cout << "Tep rong!" << endl;
		return;
	}
	temp = start;
	cout << dem << endl;
	while (temp != NULL) {
		cout << temp -> word << " " << temp -> d << endl;
		temp = temp -> next;
	}
}

int main() {
	ll n;
	Single_LL SLL;
	f >> n;
	FOR(i, 1, n) {
		string s;
		f >> s;
		SLL.insert_last(s);
	}
	SLL.display();
	return 0;
}

