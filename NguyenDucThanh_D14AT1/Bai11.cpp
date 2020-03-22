// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

ll n, size = 0;

struct Queue {
	ll front, rear;
	char node[MAX];
};
Queue s;

bool Empty() {
	if (s.front == -1 || s.front > s.rear) return true;
	return false;
}

bool Full() {
	if (s.rear == n-1) return true;
	return false;
}

void Push(char n) {
	if (Full()) cout << "Tran Queue!" << endl;
	else {
		if (s.front == -1) s.front = 0;
		size++;
		s.node[s.rear] = n;
		s.rear++;
	}
}

char Top() {
	return s.node[s.front];
}

void Pop() {
	size--;
	s.front++;
}

void Display() {
	if (s.front == -1 || s.front > s.rear) cout << "Queue rong!" << endl;
	else {
		cout << "Queue: ";
		FOR(i, s.front, s.rear) {
			cout << s.node[i] << " ";
		}
	}
}


void Menu() {
	ll c; 
	cout << "Nhap so phan tu toi da cua Queue: "; 
	cin >> n; 
	cout << endl; 
	s.front = -1;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Kiem tra tinh rong cua hang doi" << endl
			 << "2. Kiem tra tinh day cua hang doi" << endl
			 << "3. Lay phan tu o dau hang doi" << endl
			 << "4. Lay kich co cua hang doi" << endl
			 << "5. Dua phan tu vao hang doi" << endl
			 << "6. Hien thi Queue" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				if (Empty()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 2: {
				if (Full()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 3: {
				if (!Empty()) {
					cout << Top();
					Pop();
				}
				else cout << "Queue rong!" << endl;
				break;
			}
			case 4: {
				cout << size << endl;
				break;
			}
			case 5: {
				char n;
				cout << "Nhap phan tu muon them: ";
				cin >> n;
				Push(n);
				break;
			}
			case 6: {
				Display();
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

