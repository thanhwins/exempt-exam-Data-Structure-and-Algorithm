//tap thao tac tren danh sach lien ket don sap xep
#include<iostream>
using namespace std;

//cau truc cua mot node
struct node{
	int data;
	node *next;
};

//cau truc cua mot list
struct list{
	node *head;
	node *tail;
};

//khoi tao DSLK rong
void Init(list &l){
	l.head=l.tail=NULL;
}

//dua gia tri vao mot node
node *get_node(int x){
	node *p=new node;
	if(p==NULL){
		cout<<"khong du bo nho de cap phat"<<endl;
		return NULL;
	}
	p->data=x;
	p->next=NULL;
}

//them mot node vao danh sach lien ket don sap xep
void add(list &l, node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		if(p->data<=l.head->data){
			p->next=l.head;
			l.head=p;
		}
		else{
			if(p->data>=l.tail->data){
				l.tail->next=p;
				p->next=NULL;
				l.tail=p;
				//l.tail->next=NULL;
			}
			else{
				node *q=l.head;
				while(q!=l.tail){
					if(q->data<=p->data && p->data<=q->next->data){
						node *z=q->next;
						q->next=p;
						p->next=z;
						break;
					}
					q=q->next;
				}
			}
		}
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
		add(l,p);
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

int main(){
	list l;
	Init(l);
	Input(l);
	Output(l);
	return 0;
}
