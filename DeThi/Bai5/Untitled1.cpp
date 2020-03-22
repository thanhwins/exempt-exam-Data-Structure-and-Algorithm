#include<iostream>
using namespace std;

//cau truc mot node
struct node{
	int data;
	node *next;
	node *prev;
};

//cau truc mot DSLK
struct list{
	node *head;
	node *tail;
};

//khai bao danh sach lien ket rong
void Init(list &l){
	l.head=l.tail=NULL;
}

//nhap gia tri cho mot node trong DSLK
node *get_node(int x){//x la gia tri can nhap vao node
	node *p=new node;
	if(p==NULL){
		cout<<"khong du bo nho de cap phat"<<endl;
		return NULL;
	}
	p->data=x;
	p->next=p->prev=NULL;
	return p;
}

//dua node vao dau DSLK
void add_head(list &l, node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		p->next=l.head;
		l.head->prev=p;
		l.head=p;
		l.head->prev=l.tail;
		l.tail->next=l.head;
	}
}

//dua node vao cuoi DSLK
void add_tail(list &l, node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		l.tail->next=p;
		p->prev=l.tail;
		l.tail=p;
		l.tail->next=l.head;
		l.head->prev=l.tail;
	}
}

//nhap gia tri ban dau cho DSLK
void Input(list &l){
	int n;
	cout<<"nhap so luong node ban muon nhap cho DSLK: ";
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cout<<"nhap gia tri cho node: ";
		cin>>x;
		node *p=get_node(x);
		add_tail(l,p);
	}
}

//dua ra gia tri cac node trong danh sach
void Output(list l){
	node *p=new node;
	p=l.head;
	cout<<"cac phan tu trong danh sach lien ket lan luot la: "<<endl;
	do{
		cout<<p->data<<endl;
		p=p->next;
	}
	while(p!=l.head);
}

//them node vao vi tri pos
void add_N(list &l){
	int n;
	cout<<"nhap vi tri ban muon chen: ";
	cin>>n;
	int x;
	cout<<"nhap gia tri ban muon dua vao node: ";
	cin>>x;
	node *p=get_node(x);
	if(n==1){
		add_head(l,p);
	}
	else{
		int i=1;
		node *q=l.head;
		while(i!=n-1){
			q=q->next;
			i++;
		}
		node *z=q->next;
		q->next=p;
		p->next=z;
		p->prev=q;
		z->prev=p;
	}
}

//loai node o dau danh sach
void delete_head(list &l){
	if(l.head==NULL){
		cout<<"DSLK rong thi xoa cai j"<<endl;
	}
	else{
		node *p=l.head;
		p=p->next;
		l.head=p;
		l.head->prev=l.tail;
		l.tail->next=l.head;
	}
}

//loai node o cuoi danh sach
void delete_tail(list &l){
	if(l.head==NULL){
		cout<<"DSLK rong thi xoa cai j"<<endl;
	}
	else{
		node *p=l.tail->prev;
		l.tail=p;
		l.tail->next=l.head;
		l.head->prev=l.tail;
	}
}

//loai node o vi tri n
void delete_N(list &l){
	if(l.head==NULL){
		cout<<"DSLK rong thi xoa cai j"<<endl;
	}
	else{
		int n;
		cout<<"nhap vi tri ban muon xoa: "<<endl;
		cin>>n;
		if(n==1){
			delete_head(l);
		}
		else{
			int i=1;
			node *p=l.head;
			while(i!=n-1){
				p=p->next;
				i++;
			}
			node *q=p->next;
			q=q->next;
			p->next=q;
			q->prev=p;
		}
	}
}

//tim node co gia tri x tren DSLK
void FindX(list &l){
	if(l.head==NULL){
		cout<<"danh sach lien ket rong thi tim cai j";
	}
	else{
		int x;
		cout<<"nhap gia tri ban muon tim: ";
		cin>>x;
		node *p=l.head;
		int i=1;
		do{
			if(p->data==x){
				cout<<"gia tri ban muon tim o vi tri: "<<i<<endl;
			}
			i++;
			p=p->next;
		}
		while(p!=l.head);
	}
}

//sap xep gia tri tren DSLK
void SapXep(list &l){
	if(l.head==NULL){
		cout<<"DSLK rong thi sap xep cai gi"<<endl;
	}
	else{
		node *p=l.head;
		do{
			node *q=p->next;
			do{
				if(p->data>q->data){
					int temp=p->data;
					p->data=q->data;
					q->data=temp;
				}
				q=q->next;
			}
			while(q!=l.head);
			p=p->next;
		}
		while(p!=l.tail);
	}
}

//dao nguoc danh sach lien ket
void DaoNguoc(list &l){
	node *p1, *p2;
	if(l.head==NULL){
		cout<<"danh sach rong"<<endl;
	}
	p1=l.head;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	/*do{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	while(p2!=l.head);*/
	while(p2!=l.head){
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	l.tail=l.head;
	l.head=p1;
	l.tail->next=l.head;
	l.head->prev=l.tail;
	cout<<"danh sach da duoc dao nguoc"<<endl;
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
				Output(l);
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
