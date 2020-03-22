// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

ll maxS;

stack <int> sl;
bool full() {
	if (sl.size() == maxS) return true;
	return false;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Priority(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}


void TTsangHT() {
	ll k = 0; string P;
	cout << "Nhap bieu thuc trung to: ";
	cin >> P; 
	stack <char> sl;
	char Out[MAX];
	FOR(i, 0, P.length()-1) {
	//	cout << P[i] << endl;
		// Neu P[i] == "("
		if (P[i] == '(') 
			sl.push(P[i]);
		// Neu P[i] == toan hang
		else if (isOperand(P[i])) {
			Out[++k] = P[i];
		}
		// Neu P[i] == ")"
		else if (P[i] == ')') {
			char y = sl.top(); sl.pop();
			while (y != '(') {
				Out[++k] = y;
				y = sl.top();
				sl.pop();
			}
		}
		// Neu P[i] == toan tu
		else {
            char y = sl.top();
            if (sl.empty()) sl.push(P[i]);
            else if (Priority(P[i]) >= Priority(y)) 
            	sl.push(P[i]);
            else {
            	y = sl.top(); 
            	sl.pop();
            	Out[++k] = y;
            	sl.push(P[i]);
            }
        }
	}
	while (!sl.empty()) {
		Out[++k] = sl.top();
		sl.pop();
	}
	FOR(i, 1, k) cout << Out[i] << " ";
	cout << endl;
}

int kiemTra(char c)
{
	if(c >= 48 && c < 58) return 1;
	else return 0;
}

void TinhHT() {
	string P; 
	cout << "Nhap vao bieu thuc hau to: "; cin >> P;
	stack <int> sl;
	FOR(i, 0, P.length()-1) {
		if (kiemTra(P[i]))
			sl.push(P[i] - '0');
		else {
			int val1 = sl.top();
			sl.pop();//lay toan hang 1
            int val2 = sl.top();
			sl.pop(); //lay toan hang 2
            switch (P[i]) {//thuc hien phep toan tuong ung
             case '+': sl.push(val2 + val1); break;
             case '-': sl.push(val2 - val1); break;
             case '*': sl.push(val2 * val1); break;
             case '/': sl.push(val2 / val1); break;
            }
		}
	}
	cout << sl.top() << endl;
	sl.pop();
}

void Menu(){
    cout << "Nhap so phan tu toi da cua stack: "; 
	cin >> maxS; 
   	ll c; 
	cout << endl; 
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Kiem tra tinh rong cua ngan xep" << endl
			 << "2. Kiem tra tinh day cua ngan xep" << endl
			 << "3. Lay phan tu o dau ngan xep" << endl
			 << "4. Lay kich co cua ngan xep" << endl
			 << "5. Dua phan tu vao ngan xep" << endl
			 << "6. Lay phan tu ra khoi ngan xep" << endl
			 << "7. Dich chuyen bieu thuc so hoc tu trung to sang hau to" << endl
			 << "8. Tinh toan gia tri cua bieu thuc hau to" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				if (sl.empty()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 2: {
				if (full()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 3: {
				if (!sl.empty())
					cout << sl.top();
				else cout << "Stack rong!" << endl;
				break;
			}
			case 4: {
				cout << sl.size() << endl;
				break;
			}
			case 5: {
				ll n;
				cout << "Nhap phan tu muon them: ";
				cin >> n;
				sl.push(n);
				break;
			}
			case 6: {
				if (!sl.empty()) 
					sl.pop();	
				else cout << "Stack rong!" << endl;
				break;
			}
			case 7: {
				TTsangHT();
				break;
			}
			case 8: {
				TinhHT();
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

