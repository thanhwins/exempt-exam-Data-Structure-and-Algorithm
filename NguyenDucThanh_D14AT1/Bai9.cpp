// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)
using namespace std;
struct node {
    char val;
    node *next;    
} *start;

class Single_LL {
public:
	node *create(char);
	bool Empty();
	bool Full();
	void Push(char);
	void Pop();
	void display();
	int isOperand(char);
	int Priority(char);
	void TTsangHT();
	int kiemTra(char);
	char Top();
	int Top1();
	void TinhHT();
	Single_LL() {
		start = NULL;
	}             
};

ll maxS, dem = 0;

node *Single_LL :: create(char n) {
	dem++;
	node *temp, *s;
	temp = new (node);	
	temp -> val = n;
	temp -> next = NULL;
	return temp;
}

bool Single_LL :: Empty() {
	if (start == NULL) return true;
	return false;
}

bool Single_LL :: Full() {
	if (dem == maxS) return true;
	return false;
}

void Single_LL :: Push(char n) {
	node *temp, *p;
	temp = create(n);
	if (start == NULL) {
		start = temp;
		start -> next = NULL;
	}
	else {
		p = start;
		start = temp;
		start -> next = p;
	}
}

void Single_LL :: Pop() {
	dem--;
	node *s;
	s = start;
	start = s -> next;
	s -> next = NULL;
	free(s);
}

char Single_LL :: Top() {
	return start -> val;
}

void Single_LL :: display() {
	node *temp;
	if (Empty()) {
		cout << "Stack rong!" << endl;
		return;
	}
	temp = start;
	cout << "Noi dung Stack: " << endl;
	while (temp != NULL) {
		cout << temp -> val << " ";
		temp = temp -> next;
	}
	cout << endl; 
}

int Single_LL :: isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Single_LL :: Priority(char ch)
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

void Single_LL :: TTsangHT() {
	ll k = 0; string P; dem = 0;
	cout << "Nhap bieu thuc trung to: ";
	cin >> P; start = NULL;
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

int Single_LL :: kiemTra(char c) {
	if(c >= 48 && c < 58) return 1;
	else return 0;
}

int Single_LL :: Top1() {
	return start -> val;
}

void Single_LL :: TinhHT() {
	string P; dem = 0;
	cout << "Nhap vao bieu thuc hau to: "; cin >> P;
	start = NULL;
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


void Menu(){
    Single_LL sl;
   	ll c; 
	cout << "Nhap so phan tu toi da cua stack: "; 
	cin >> maxS; 
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
			 << "9. Hien thi stack" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				if (sl.Empty()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 2: {
				if (sl.Full()) cout << "YES";
				else cout << "NO";
				break;
			}
			case 3: {
				if (!sl.Empty())
					cout << sl.Top();
				else cout << "Stack rong!" << endl;
				break;
			}
			case 4: {
				cout << dem << endl;
				break;
			}
			case 5: {
				char n;
				cout << "Nhap phan tu muon them: ";
				cin >> n;
				sl.Push(n);
				break;
			}
			case 6: {
				if (!sl.Empty()) 
					sl.Pop();	
				else cout << "Stack rong!" << endl;
				break;
			}
			case 7: {
				sl.TTsangHT();
				break;
			}
			case 8: {
				sl.TinhHT();
				break;
			}
			case 9: {
				sl.display();
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
