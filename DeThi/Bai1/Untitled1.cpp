//cac thao tac co ban tren danh sach lien ket don
#include<iostream>
using namespace std;

//khoi tao danh sach lien ket don
struct node{//cau truc cua mot node
	int data;
	node *next;
};

struct list{//khai bao mot danh sach lien ket
	node *head;
	node *tail;
};

void Init(list &l){//cho danh sach lien ket rong
	l.head=l.tail=NULL;
}

node *get_node(int x){//dua gia tri x vao trong DSLK
	node *p=new node;
	if(p==NULL){
		cout<<"khong du bo nho de cap phat"<<endl;
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}

//them node vao dau
void add_head(list &l, node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		p->next=l.head;
		l.head=p;
	}
}

//them node vao cuoi
void add_tail(list &l, node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		l.tail->next=p;
		p->next=NULL;
		l.tail=p;  
	}
}

void Input(list &l){//ham nhap du lieu ban dau cho DSLK
	int n;
	cout<<"nhap so luong phan tu ban muon tao cho DSLK: "<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cout<<"nhap gia tri ban muon nhap cho node: ";
		cin>>x;
		node *p=get_node(x);
		add_tail(l,p);
	}
}

void Output(list l){
	node *p=new node;
	p=l.head;
	cout<<"cac phan tu trong danh sach lien ket lan luot la: "<<endl;
	while(p!=NULL){
		cout<<p->data<<endl;
		p=p->next;
	}
}

//them node vao mot vi tri thu n
void add_N(list &l){
	int n;
	cout<<"nhap vi tri ban muon chen node: ";
	cin>>n;
	int i=1;
	node *p=new node;
	p=l.head;
	while(i!=n-1){
		p=p->next;
		i++;
	}
	int x;
	cout<<"nhap gia tri ban muon dua vao node de chen vao vi tri n: ";
	cin>>x;
	node *q=get_node(x);
	node *z=p->next;
	q->next=z;
	p->next=q;
}

//loai node o dau
void delete_head(list &l){
	if(l.head==NULL){
		cout<<"DSLK rong thi xoa cai j"<<endl;
	}
	else{
		l.head=l.head->next;
	}
}

//loai node o cuoi
void delete_tail(list &l){
	if(l.head==NULL){
		cout<<"DSLK rong thi xoa cai j"<<endl;
	}
	else{
		node *p=l.head;
		while(p->next!=l.tail){
			p=p->next;
		}
		l.tail=p;
	}
}

//loai node o vi tri thu n
void delete_N(list &l){
	int n;
	cout<<"nhap vi tri ban muon loai node: ";
	cin>>n;
	int i=1;
	node *p=l.head;
	if(n==1){
		delete_head(l);
	}
	else{
		while(i!=n-1){
			p=p->next;
			i++;
		}
		node *q=p->next;
		p->next=q->next;	
	}
}
//tim node co gia tri x
void FindX(list &l){
	if(l.head==NULL){
		cout<<"DSLK rong thi tim cai j"<<endl;
	}
	else{
		int x;
		cout<<"nhap gia tri ban muon tim: ";
		cin>>x;
		node *p=l.head;
		int i=1;
		while(p!=NULL){
			if(p->data==x){
				cout<<"gia tri ban can tim o vi tri thu: "<<i<<endl;
			}
			p=p->next;
			i++;
		}
	}
}

//duyet DSLK

//sap xep cac node
void SapXep(list &l){
	if(l.head==NULL){
		cout<<"DSLK rong thi sap xep cai gi"<<endl;
	}
	else{
		node *p=l.head;
		while(p!=NULL){
			node *q=p->next;
			while(q!=NULL){
				if(p->data>q->data){
					int temp=p->data;
					p->data=q->data;
					q->data=temp;
					
				}
				q=q->next;
			}
			
			p=p->next;
		}
	}
}

//dao nguoc cac node cua DSLK
void DaoNguoc(list &l){
	node *p1, *p2, *p3;
	if(l.head==NULL){
		cout<<"danh sach rong"<<endl;
	}
	if(l.head->next==NULL){
		cout<<"dao nguoc lai danh sach van la chinh no"<<endl;
	}
	p1=l.head;
	p2=p1->next;
	p3=p2->next;
	p1->next=NULL;
	p2->next=p1;
	while(p3!=NULL){
		p1=p2;
		p2=p3;
		p3=p3->next;
		p2->next=p1;
	}
	l.head=p2;
}

int main(){
	list l;
	Init(l);
	Input(l);
	Output(l);
	int run=1;
	while(run==1){
		int luachon;
		cout<<"chon 1: neu muon them node vao mot vi tri thu n"<<endl;
		cout<<"chon 2: neu muon loai node o dau"<<endl;
		cout<<"chon 3: neu muon loai node o cuoi"<<endl;
		cout<<"chon 4: neu loai node o vi tri thu n"<<endl;
		cout<<"chon 5: neu muon tim node co gia tri x"<<endl;
		cout<<"chon 6: neu muon duyet danh sach lien ket"<<endl;
		cout<<"chon 7: neu muon sap xep cac node"<<endl;
		cout<<"chon 8: neu muon dao nguoc cac node cua DSLK"<<endl;
		cin>>luachon;
		switch(luachon){
			case 1:{
				add_N(l);
				Output(l);
				break;
			}
			case 2:{
				delete_head(l);
				Output(l);
				break;
			}
			case 3:{
				delete_tail(l);
				Output(l);
				break;
			}
			case 4:{
				delete_N(l);
				Output(l);
				break;
			}
			
			case 5:{
				FindX(l);
				break;
			}
			case 6:{
				Output(l);
				break;
			}
			case 7:{
				SapXep(l);
				break;
			}
			case 8:{
				DaoNguoc(l);
				Output(l);
				break;
			}
		}
		cout<<"chon 1: neu ban muon tiep tuc"<<endl;
		cout<<"chon 0: neu ban muon dung lai"<<endl;
		cin>>run;
	}
	return 0;
}
