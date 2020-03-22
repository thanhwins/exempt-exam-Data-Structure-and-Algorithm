//cac thao tac tren hang doi dua vao danh sach lien ket don
#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

struct queue{
	node *head;
	node *tail;
};

void Init(queue &q){
	q.head=q.tail=NULL;
}

node *get_node(int x){
	node *p=new node;
	if(p==NULL){
		cout<<"khong du bo nho de cap phat"<<endl;
	}
	else{
		p->data=x;
		p->next=NULL;
		return p;
	}
}

//them o cuoi hang doi
void add_tail(queue &q, node *p){
	if(q.head==NULL){
		q.head=q.tail=p;
	}
	else{
		q.tail->next=p;
		p->next=NULL;
		q.tail=p;
	}
}

//lay ra o dau hang doi
node *delete_head(queue &q){
	if(q.head==NULL){
		cout<<"hang doi rong, khong co gi de xoa"<<endl;
	}
	else{
		node *x=q.head;
		q.head=q.head->next;
		return x;
	}
}

void Output(queue &q){
	if(q.head==NULL){
		cout<<"hang doi rong"<<endl;
	}
	else{
		node *p=q.head;
		cout<<"cac phan tu dang co mat trong hang doi: "<<endl;
		while(p!=NULL){
			cout<<p->data<<endl;
			p=p->next;
		}
	}
}

void Input(queue &q){
	int n;
	cout<<"so luong phan tu ban muon nhap vao trong hang doi: ";
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cout<<"nhap gia tri cho node nay: ";
		cin>>x;
		node *p=get_node(x);
		add_tail(q,p);
	}
	Output(q);
}

int main(){
	queue q;
	Init(q);
	Input(q);
	return 0;
}
