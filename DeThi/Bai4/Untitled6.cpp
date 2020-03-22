//tap thao tac tren danh sach lien ket kep
#include<iostream>
using namespace std;

//cau truc mot node trong DSLK kep
struct node{
	int data;
	node *prev;
	node *next;
};

//cau truc mot list
struct list{
	node *head;
	node *tail;
};

//khoi tao DSLK rong
void Init(list &l){
	l.head=l.tail=NULL;
}

//tao gia tri cho mot node
node *get_node(int x){
	node *p=new node;
	if(p==NULL){
		cout<<"khong du bo nho de cap phat"<<endl;
		return NULL;
	}
	p->data=x;
	p->next=p->prev=NULL;
}

//them node vao dau 
void add_head(list &l, node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		p->next=l.head;
		l.head->prev=p;
		p->prev=NULL;
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
		p->prev=l.tail;
		l.tail=p;
		l.tail->next=l.head;
		l.head->prev=l.tail;
	}
}

//nhap cac gia tri ban dau cho DSLK
void Input(list &l){
	int n;
	cout<<"nhap so luong node ban muon nhap: ";
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cout<<"nhap gia tri ban muon nhap cho node: ";
		cin>>x;
		node *p=get_node(x);
		add_tail(l,p);
	}
}

//in ra du lieu cua cac node dang co trong DSLK
void Output(list l){
	if(l.head==NULL){
		cout<<"danh sach lien ket rong"<<endl;
	}
	else{
		node *p=l.head;
		cout<<"cac thanh phan du lieu dang co mat trong DSLK: "<<endl;
		do{
			cout<<p->data<<endl;
			p=p->next;
		}
		while(p!=l.head);
	}
}

//them node vao vi tri pos
void add_N(list &l){
	int n;
	cout<<"nhap vi tri ban muon chen node: ";
	cin>>n;
	int x;
	cout<<"nhap gia tri ma ban muon dua vao node can chen: ";
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

//loai node o dau
void delete_head(list &l){
	if(l.head==NULL){
		cout<<"DSLK rong thi xoa cai j"<<endl;
	}
	else{
		l.head=l.head->next;
		l.head->prev=NULL;
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
		l.tail->next=NULL;
	}
}

//loai node o vi tri pos
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
		q->next->prev=p;	
	}
}

//tim node co gia tri x tren DSLK
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
//sap xep tang dan
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

//dao nguoc cac node tren DSLK
void DaoNguoc(list &l){
	node *p1, *p2;
	if(l.head==NULL){
		cout<<"danh sach rong"<<endl;
	}
	if(l.head->next==NULL){
		cout<<"dao nguoc lai danh sach van la chinh no"<<endl;
	}
	p1=l.head;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL){
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	l.head=p1;
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
