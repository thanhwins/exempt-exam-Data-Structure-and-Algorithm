//danh sach lien ket kep sap xep
#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
};

struct list{
	node *head;
	node *tail;
};

void Init(list &l){
	l.head=l.tail=NULL;
}

node *get_node(int x){
	node *p=new node;
	p->data=x;
	p->next=p->prev=NULL;
	return p;
}

void add(list &l, node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		if(p->data<=l.head->data){
			p->next=l.head;
			l.head->prev=p;
			l.head=p;
			l.head->prev=l.tail;
			l.tail->next=l.head;
		}
		else{
			if(p->data>=l.tail->data){
				l.tail->next=p;
				p->prev=l.tail;
				l.tail=p;
				l.tail->next=l.head;
				l.head->prev=l.tail;
			}
			else{
				node *q=l.head;
				do{
					if(q->data<=p->data && p->data<=q->next->data){
						node *z=q->next;
						q->next=p;
						p->prev=q;
						p->next=z;
						z->prev=p;
					}
					q=q->next;
				}
				while(q!=l.head);
			}
		}
	}
}

void Input(list &l){
	int n;
	cout<<"nhap so luong node ban muon tao: "<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cout<<"nhap gia tri ban muon: ";
		cin>>x;
		node *p=get_node(x);
		add(l,p);
	}
}

void Output(list l){
	if(l.head==NULL){
		cout<<"danh sach lien ket rong";
	}
	else{
		node *p=l.head;
		cout<<"cac phan tu co mat trong danh sach: "<<endl;
		do{
			cout<<p->data<<endl;
			p=p->next;
		}
		while(p!=l.head);
	}
}

int main(){
	list l;
	Init(l);
	Input(l);
	Output(l);
	return 0;
}
