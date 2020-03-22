// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

ll n, size = 0;

struct Stack {
	ll top;
	char node[MAX];
};
Stack s;

bool Empty() {
	if (s.top == -1) return true;
	return false;
}

bool Full() {
	if (s.top == n-1) return true;
	return false;
}

void Push(char n) {
	if (Full()) cout << "Tran stack!" << endl;
	else {
		size++;
		s.top++;
		s.node[s.top] = n;
	}
}

char Top() {
	return s.node[s.top];
}

void Pop() {
	size--;
	s.top--;
}

void HienThi() {
	if (s.top == -1) cout << "Stack rong!" << endl;
	else {
		cout << "Stack: ";
		FORD(i, s.top, 0) {
			cout << s.node[i] << " ";
		}
	}
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
	cin >> P; s.top = -1;
	char Out[MAX];
	FOR(i, 0, P.length()-1) {
	//	cout << P[i] << endl;
		// Neu P[i] == "("
		if (P[i] == '(') 
			Push(P[i]);
		// Neu P[i] == toan hang
		else if (isOperand(P[i])) {
			Out[++k] = P[i];
		}
		// Neu P[i] == ")"
		else if (P[i] == ')') {
			char y = Top(); Pop();
			while (y != '(') {
				Out[++k] = y;
				y = Top();
				Pop();
			}
		}
		// Neu P[i] == toan tu
		else {
            char y = Top();
            if (Empty()) Push(P[i]);
            else if (Priority(P[i]) >= Priority(y)) 
            	Push(P[i]);
            else {
            	y = Top(); 
            	Pop();
            	Out[++k] = y;
            	Push(P[i]);
            }
        }
	}
	while (!Empty()) {
		Out[++k] = Top();
		Pop();
	}
	FOR(i, 1, k) cout << Out[i] << " ";
	cout << endl;
}

int kiemTra(char c)
{
	if(c >= 48 && c < 58) return 1;
	else return 0;
}

int Top1() {
	return s.node[s.top];
}

void TinhHT() {
	string P; 
	cout << "Nhap vao bieu thuc hau to: "; cin >> P;
	s.top = -1;
	FOR(i, 0, P.length()-1) {
		if (kiemTra(P[i]))
			Push(P[i] - '0');
		else {
			int val1 = Top1();
			Pop();//lay toan hang 1
            int val2 = Top1();
			Pop(); //lay toan hang 2
            switch (P[i]) {//thuc hien phep toan tuong ung
             case '+': Push(val2 + val1); break;
             case '-': Push(val2 - val1); break;
             case '*': Push(val2 * val1); break;
             case '/': Push(val2 / val1); break;
            }
		}
	}
	cout << Top1() << endl;
	Pop();
}

void Menu() {
	ll c; 
	cout << "Nhap so phan tu toi da cua stack: "; 
	cin >> n; 
	cout << endl; 
	s.top = -1;
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
			 << "9. Hien thi stack" << endl
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
				if (!Empty())
					cout << Top();
				else cout << "Stack rong!" << endl;
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
				if (!Empty()) 
					Pop();	
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
			case 9: {
				HienThi();
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

