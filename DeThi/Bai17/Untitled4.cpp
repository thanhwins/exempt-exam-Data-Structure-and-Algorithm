//cai dat hang doi uu tien dua vao danh sach lien ket don
#include<iostream>
using namespace std;

struct node{//khai bao cau truc mot node trong hang doi uu tien
	int data;
	int priority;
	node *next;
};

struct queue_priority{
	node *head;
	node *tail;
};

void Init(queue_priority &q){//khai bao hang doi rong
	q.head=q.tail=NULL;
}

node *get_node(int x, int y){//dua gia tri vao mot node
	node *p=new node;
	if(p==NULL){
		cout<<"khong du bo nho de cap phat"<<endl;
	}
	else{
		p->data=x;
		p->priority=y;
		p->next=NULL;
		return p;
	}
}

void add(queue_priority &q, node *p){
	if(q.head==NULL){
		q.head=q.tail=p;
	}
	else{
		if( p->priority<=q.head->priority){
			p->next=q.head;
		}
		else{
			if(q.tail->priority<=p->priority){
				q.tail->next=p;
				q.tail=p;
			}
			else{
				node *t=q.head;
				while(t!=NULL){
					if(t->priority<=p->priority && t->next->priority>=p->priority){
						break;
					}
					else{
						t=t->next;
					}
				}
				p->next=t->next;
				t->next=p;
			}
		}
	}
}

void delete_queue(queue_priority &q){
	if(q.head==NULL){
		cout<<"hang doi rong, khong xoa duoc nua"<<endl;
	}
	else{
		node *p=q.head;
		while(p->next!=q.tail){
			p=p->next;
		}
		p->next=NULL;
		q.tail=p;
	}
}

void Output(queue_priority &q){
	if(q.head==NULL){
		cout<<"hang doi rong"<<endl;
	}
	else{
		node *p=q.head;
		cout<<"cac phan tu co mat trong hang doi la: "<<endl;
		while(p!=NULL){
			cout<<"gia tri: "<<p->data<<" voi do uu tien la: "<<p->priority<<endl;
			p=p->next;
		}
	}
}

void Input(queue_priority &q){
	int n;
	cout<<"nhap so luong phan tu ban muon dua vao trong hang doi: ";
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cout<<"nhap gia tri ban muon dua vao node: ";
		cin>>x;
		int y;
		cout<<"nhap do uu tien cua node nay: ";
		cin>>y;
		node *p=get_node(x,y);
		add(q,p);
	}
	Output(q);
}

int main(){
	queue_priority q;
	Init(q);
	Input(q);
	return 0;
}
