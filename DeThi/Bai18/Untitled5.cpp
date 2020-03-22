//cac thao tac co ban hang doi 2 diem dau cuoi
#include<iostream>
using namespace std;


struct node{//cau truc cua mot node
	int data;
	node *next;
};

struct list{//khai bao mot hang doi 2 diem dau va cuoi
	node *head;
	node *tail;
};

void Init(list &l){//cho hang doi 2 diem dau va cuoi rong
	l.head=l.tail=NULL;
}

node *get_node(int x){//dua gia tri x vao trong hang doi 2 diem dau va cuoi
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

void Input(list &l){//ham nhap du lieu ban dau cho hang doi 2 diem dau va cuoi
	int n;
	cout<<"nhap so luong phan tu ban muon tao cho hang doi 2 diem dau va cuoi: "<<endl;
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
	cout<<"cac phan tu trong hang doi 2 diem dau va cuoi lan luot la: "<<endl;
	while(p!=NULL){
		cout<<p->data<<endl;
		p=p->next;
	}
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

int main(){
	list l;
	Init(l);
	Input(l);
	Output(l);
	int run=1;
	while(run==1){
		int luachon;
		cout<<"chon 1: neu muon in ra man hinh"<<endl;
		cout<<"chon 2: neu muon loai node o dau"<<endl;
		cout<<"chon 3: neu muon loai node o cuoi"<<endl;
		cout<<"chon 4: neu muon them node o dau"<<endl;
		cout<<"chon 5: neu muon them node o cuoi"<<endl;
		cin>>luachon;
		switch(luachon){
			case 1:{
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
				int x;
				cout<<"nhap gia tri cho node: ";
				cin>>x;
				node *p=get_node(x);
				add_head(l,p);
				break;
			}
			case 5:{
				int x;
				cout<<"nhap gia tri cho node: ";
				cin>>x;
				node *p=get_node(x);
				add_tail(l,p);
				break;
			}
		}
		cout<<"chon 1: neu ban muon tiep tuc"<<endl;
		cout<<"chon 0: neu ban muon dung lai"<<endl;
		cin>>run;
	}
	return 0;
}
