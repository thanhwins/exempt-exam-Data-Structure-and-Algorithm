//LeNhoa
#include<iostream>
#include<stack>
using namespace std;
int a[100][100], n;
int le1,le2;
struct node{
	int inf;
	node *next;
};

class dsk{
	public:
		node *head;
		dsk();
		node* ktao(int);
		void them(int);
		void duyet();
		int dem();
};

dsk::dsk(){
	head = NULL;
}

node* dsk::ktao(int k){
	node *tmp;
	tmp = new (node);
	tmp->inf = k;
	tmp->next = NULL;
	return tmp;
}

void dsk::them(int k){
	if(head == NULL){
		head = ktao(k);
	}
	else{
		node *s, *t;
		t = ktao(k);
		s = head;
		while(s->next != NULL){
			s = s->next;
		}
		s->next = t;
	}
}

void dsk::duyet(){
	if(head==NULL){
		cout<<"ds rong";
	}
	else{
		node *s;
		s = head;
		while(s!= NULL){
			cout<<s->inf<<" ";
			s = s->next;
		}
		cout<<endl;
	}
}

class doThi:dsk{
	public:
		int sodinh;
		dsk dsk[20];
		void nhap();
		void duyet();
};

void doThi::nhap(){
	cout<<"nhap so dinh: ";
	cin>>sodinh;
	cout<<"nhap du lieu vao:\n";
	for(int i=0; i<sodinh; i++){
		int ke, k;
		cin>>ke;
		for(int j = 0; j<ke; j++){
			cin>>k;
			a[i+1][ke] = k;
			dsk[i].them(k);
		}
	}
}

void doThi::duyet(){
	cout<<"so dinh: "<<sodinh<<endl;
	for(int i=0; i<sodinh; i++){
		dsk[i].duyet();
	}
}

int ktEuler_vohuong(int a[][100], int n){
	int h, demchan = 0, demle = 0;
	for(int i=1; i<=n; i++){
		h = 0;
		for(int j=1; j<=n; j++){
			h += a[i][j];
		}
		if(h%2==0)	demchan++;
		else{
			demle++;
			le1 = i;
		}
	}
	if(demchan==n)	return 1;
	if(demle==2)	return(-1);
	return 0;
}

int ktEuler_cohuong(int a[][100], int n){
	int dem = 0, demle1 = 0, demle2=0;
	for(int i=0; i<=n; i++){
		int h=0, c=0;
		for(int j=0;j<=n; j++){
			h += a[i][j];
			c += a[j][i];
		}
		if(h==c)	dem++;
		else{
			if(h-c==1){
				demle1++;
				le1 = i;
			}
			if(c-h==1){
				demle2++;
				le2 = i;
			}
		}
	}
	if(dem==n)	return 1;
	if(demle1==1 && demle2==1)	return(-1);
	return 0;
}

void chuTrinhE(int x){
		
}




main(){
	doThi dt;
	dt.nhap();
	dt.duyet();
}

