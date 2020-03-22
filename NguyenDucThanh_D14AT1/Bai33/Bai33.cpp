// Nguyen Duc Thanh - B14DCAT028
#include <bits/stdc++.h>
#define MAX 100
#define ll long long
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

struct Node {
	int info;
	Node *next;
};

struct List {
	Node *head,*tail;
};

void Createlist( List &l) {
	l.head = l.tail = NULL;
}

Node* CreateNode(int data) {
	Node *p = new Node;
	if(p != NULL){
		p ->info = data;
		
		p -> next = NULL;
	}
	return p;
}

bool Isempty(List l) {
	if(l.head == NULL) return true;
	return false;
}

bool Isfull(List S){
	Node *p = new Node;
	if(p == NULL) return true ;
	return false;
}
int sapxep(List &l) {
	Node *i = l.head;
	Node *q;
	while (i) {
		for (q = i -> next; q != NULL; q = q -> next)
		if ( i -> info > q -> info) {
			int temp = i -> info;
			i -> info = q -> info;
			q -> info = temp;
		
		}
		i = i -> next;
	}
}

void Push(List &l, int &x) {	
	Node *p = CreateNode(x);
    if (l.head == NULL) 
    	l.head  = l.tail = p;
    else {
        l.tail -> next = p; 
        l.tail = p;
   	}
    sapxep(l);
}

void Pop(List &l) {
	Node *p = l.head;
	l.head = l.head -> next;
	delete p;
}

int Peak(List l) {
	int x;
	x = l.head -> info;
	return x;
}

int Size(List l) {
	Node* p = l.head;
	int d = 0;
	while(p != NULL) {
		p = p -> next;
		d++;
	}
	return d;
}

void xuat(List l) {
	Node *p = l.head;
	if(!p) cout << "Danh sach rong!" << endl;
	while (p) {
	   cout<< endl << p -> info;
	   p = p -> next;
	}
}

void taodanhsach(List &l) {
	int k, x, y;
	cout << "Nhap so phan tu: ";
	cin >> k;
	FOR(i, 1, k) {
		cout << "Nhap phan tu thu " << i << ": "; 
		cin >> x;
		Push(l,x);
	}
	cout<<endl;
}
 
void nropes(List &l) {
	Createlist(l);
	taodanhsach(l);
	int OPT=0;
	while(Size(l) > 1){
		int F = l.head -> info; Pop(l);
		int S = l.head -> info; Pop(l);
		int P = F+S;
		OPT += P;
		Push(l,P);
	}
	cout << OPT;
}

struct dovat {
	int tl, gtsd;
} list1[100];

void nhap(int &n) {	
	cout<<"Nhap so do vat: "; cin >> n;
	FOR(i, 0, n-1)
	{
		cout << "Vat " << i+1 << endl;
		cout << "Trong luong: "; cin >> list1[i].tl;
		cout << "Gia tri: "; cin >> list1[i].gtsd;
	}
}

void sort(int n) {
	FOR(i, 0, n-2) {	
		FOR(j, i+1, n-1)
			if(list1[i].gtsd < list1[j].gtsd) {
				dovat tmp;
				tmp = list1[i];
				list1[i] = list1[j];
				list1[j] = tmp;
		    }
	}
}

void tim(int n,int &m) {
	sort(n);
	int s = 0, tmp = 0;
	int p = 0;
	int j = 0;
	cout << "Nhap trong luong toi da: "; cin >> m;
	cout << "Lay cac do vat co trong luong: ";
	FOR(i, 0, n-1) {
		tmp = s + list1[i].tl;
		if(tmp <= m) {
			s += list1[i].tl;
			p += list1[i].gtsd;
			cout << list1[i].tl << " ";
		}
	}
	cout << "Gia tri toi da co the la: " << p;
}

struct Time{
	int start, finish;
} list11[100];

void nhap1(int &n) {	
	cout << "Nhap n: "; cin >> n;
	FOR(i, 0, n-1) {
		cout <<"Hanh dong thu " << i+1 << endl;
		cout << "Thoi gian bat dau: "; cin >> list11[i].start; 
		cout << "Thoi gian ket thuc: "; cin >> list11[i].finish;
	}
}

void xuat1(int n){
	FOR(i, 1, n) {
	cout << " " << list11[i].start;
	cout << " " << list11[i].finish;
}
}
void sort1(int n) {
	FOR(i, 0, n) {	
		FOR(j, i+1, n-1)
			if (list11[i].finish > list11[j].finish) {
				Time tmp;
				tmp = list11[i];
				list11[i] = list11[j];
				list11[j] = tmp;
			}
	}
}
void tim1(int n) {
	sort1(n);
	cout << "0 ";
	int j = 0;
	FOR(i, 1, n-1) {
		if(list11[j].finish < list11[i].start) {
			j = i;
			cout << i << " ";
		}
	}	
}

int a[5][5] = { {0,15,30,50,20},
                {15,0,10,35,32},
                {30,10,0,15,40},
            	{50,35,15,0,43},
                {20,32,40,43,0}};
int n5;
bool b[5] = {false};
int kq[10], bestConfig[10] = {0};
int min5 = 32000, cost = 0;
int start;

void Output() {
	FOR(i, 0, n5-1) {
		cout << bestConfig[i]+1 << " -> ";
	}
	cout << bestConfig[0]+1 << endl;
	cout << "Chi phi: " << min5 << endl;
}

void Try(int i) {
	if (i == n5) {
		if (cost + a[kq[i-1]][kq[0]] < min5) {
			min5 = cost + a[kq[i-1]][kq[0]];
			FOR(k, 0, n5-1) 
				bestConfig[k]= kq[k];
		}
	}
	else {
		FOR(j, 0, n5-1) {
			if(b[j] == false && cost + a[kq[i-1]][j] < min5) {
				kq[i] = j;
				b[j] = true;
				cost += a[kq[i-1]][j];
				Try(i+1);
				b[j] = false;
				cost -= a[kq[i-1]][j];
			}
		}
	}
}

ll INF = 1e9 + 7;
fstream f ("data.txt", ios :: in);

ll n, w[MAX][MAX], p[MAX], cx[MAX], D[MAX], PRIM[MAX][MAX];

void Nhap() {
	f >> n;
	FOR(i, 1, n) {
		FOR(j, 1, n)
			f >> w[i][j];
		cx[i] = true;
		p[i] = -1;
		D[i] = INT_MAX;
	}
	f.close();
}

ll Extract_Min() {
	ll min = INT_MAX, u;
	FOR(i, 1, n) {
		if (cx[i] && D[i] < min) {
			min = D[i]; 
			u = i;
		}
	}
	return u;
}

void HienThi() {
	FOR(i, 1, n) {
		FOR(j, 1, n)
			cout << setw(6) << PRIM[i][j];
		cout << endl;
	}
}

void Prim(ll i) {
	D[i] = 0;
	FOR(i, 1, n-1) {
		ll u = Extract_Min();
		cx[u] = false;
		FOR(j, 1, n) {
			if (cx[j] && w[i][j] != 0 && w[i][j] < D[j]) {
				D[j] = w[i][j];
				p[j] = u;
			}
		}
	}
	FOR(i, 1, n) 
		PRIM[p[i]][i] = PRIM[i][p[i]] = w[p[i]][i];
	HienThi();
		
}

fstream f2 ("data2.txt", ios :: in);

ll n2, s2, t2, w2[MAX][MAX], cx2[MAX], p2[MAX], d2[MAX], minp;

void Nhap2() {
	f2 >> n2;
	f2 >> s2 >> t2;
	FOR(i, 1, n2) {
		FOR(j, 1, n2) {
			f2 >> w2[i][j];
			if (w2[i][j] == -1) w2[i][j] = INF;
		}
		cx2[i] = true;
	}
	f2.close();
}

void InitDijkstra() {
	FOR(i, 1, n2) {
		d2[i] = w2[s2][i];
		p2[i] = s2;
	}
}

void Dijkstra() {
	InitDijkstra();
	
	ll u, v;
	p2[s2] = 0; d2[s2] = 0; cx2[s2] = false;
	
	cx2[s2] = false;
	while (cx2[t2]) {
		minp = INF;
		FOR(i, 1, n2) {
			if (cx2[i] && d2[i] < minp) {
				minp = d2[i];
				u = i;
			}
		}
		cx2[u] = false;
		if (cx2[t2]) {
			FOR(i, 1, n2) {
				if (cx2[i] && d2[i] > d2[u] + w2[u][i]) {
					d2[i] = d2[u] + w2[u][i];
					p2[i] = u;
				}
			}
		}
	}
}

void HienThi2() {
	cout << endl << "- Duong di ngan nhat tu " << s2 << " den " << t2 << " la:" << endl;
	cout << setw(4) << t2 << " <- ";
	ll i = p2[t2];
	while (i != s2) {
		cout << i << " <- ";
		i = p2[i];
	}
	cout << s2 << endl << "- Do dai duong di la: " << d2[t2];
}

void Menu() {
	List l;
	ll c;
	while (1) {
		cout << endl << "------------------------------------" << endl << "Danh sach cac chuc nang: " << endl
			 << "1. Giai bai toan n-ropes" << endl
			 << "2. Giai bai toan Activity Selection khong trong so" << endl
			 << "3. Giai bai toan cai tui" << endl
			 << "4. Giai bai toan nguoi di du lich" << endl
			 << "5. PRIM" << endl
			 << "6. Dijkstra" << endl
			 << "0. Ket thuc chuong trinh" << endl << "------------------------------------" << endl;
		cout << "Ban muon chon chuc nang nao? ";
		cin >> c;
		switch(c) {
			case 1: {
				nropes(l);
				break;
			}
			case 2: {
				int n;
				nhap1(n);
				tim1(n);
				break;
			}
			case 3: {
				int n, m;
				nhap(n);
				tim(n,m);
				break;
			}
			case 4: {
				n5 = 5;
				start = 3;
				kq[0] = start; b[start] = true;
					
				Try(1);
				Output();
				break;
			}
			case 5: {
				Nhap();
				Prim(4);
				break;
			}
			case 6: {
				Nhap2();
				Dijkstra();
				HienThi2();
				break;
			}
		}
	}
} 
int main() {
	Menu();
	return 0;
}

