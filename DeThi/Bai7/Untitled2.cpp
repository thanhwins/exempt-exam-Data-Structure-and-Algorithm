#include<iostream>
#include<cmath>
using namespace std;

//cau truc mot node trong DSLK kep
struct node{
	int ChiSo;
	int SoMu;
	node *prev;
	node *next;
};

//cau truc mot list
struct list{
	node *head;
	node *tail;
};


//khoi tao DSLK rong
void Init(list &l1, list &l2){
	l1.head=l1.tail=NULL;
	l2.head=l2.tail=NULL;
}

void Init1(list &l3){
	l3.head=l3.tail=NULL;
}


//tao gia tri cho mot node
node *get_node(int ChiSo, int SoMu){
	node *p=new node;
	if(p==NULL){
		cout<<"khong du bo nho de cap phat"<<endl;
		return NULL;
	}
	p->ChiSo=ChiSo;
	p->SoMu=SoMu;
	p->next=p->prev=NULL;
	return p;
}

//them node vao dau 
void add_head(list &l1, node *p){
	if(l1.head==NULL){
		l1.head=l1.tail=p;
	}
	else{
		p->next=l1.head;
		l1.head->prev=p;
		p->prev=NULL;
		l1.head=p;
	}
}


//them node vao cuoi
void add_tail(list &l1, node *p){
	if(l1.head==NULL){
		l1.head=l1.tail=p;
	}
	else{
		l1.tail->next=p;
		p->next=NULL;
		p->prev=l1.tail;
		l1.tail=p;
	}
}


//nhap gia tri cho da thuc ban dau
void Input(list &l1, list &l2){
	int n1, n2;
	cout<<"nhap so luong phan tu cho da thuc thu nhat: ";
	cin>>n1;
	for(int i=1;i<=n1;i++){
		int ChiSo,SoMu;
		cout<<"nhap chi so cho phan tu "<<i<<": ";
		cin>>ChiSo;
		cout<<"nhap so mu cho phan tu "<<i<<": ";
		cin>>SoMu;
		node *p=get_node(ChiSo,SoMu);
		add_tail(l1,p);
	}
	
	cout<<"nhap so luong phan tu cho da thuc thu hai: ";
	cin>>n2;
	for(int i=1;i<=n2;i++){
		int ChiSo,SoMu;
		cout<<"nhap chi so cho phan tu "<<i<<": ";
		cin>>ChiSo;
		cout<<"nhap so mu cho phan tu "<<i<<": ";
		cin>>SoMu;
		node *p=get_node(ChiSo,SoMu);
		add_tail(l2,p);
	}
}

void Output(list l1){
	if(l1.head==NULL){
		cout<<"danh sach lien ket rong"<<endl;
	}
	else{
		node *p=l1.head;
		int i=1;
		cout<<"cac thanh phan du lieu dang co mat trong DSLK: "<<endl;
		/*while(p!=NULL){
			cout<<"chi so:"<<p->ChiSo<<", so mu: "<<p->SoMu<<endl;
			p=p->next;
		}*/
		while(p!=NULL){
			cout<<"phan tu thu "<<i<<" co "<<"chi so:"<<p->ChiSo<<", so mu: "<<p->SoMu<<endl;
			p=p->next;
			i++;
		}
		//cout<<"here";
	}
}


//tinh gia tri cua da thuc khi cho gia tri x0 xac dinh
void Count(list l1, list l2){
	int x;
	cout<<"nhap gia tri cua x: ";
	cin>>x;
	node *p1=l1.head;
	int s1=0;
	while(p1!=NULL){
			s1 = s1 + p1->ChiSo * pow(x,p1->SoMu);
			p1=p1->next;
	}
	cout<<"gia tri cua da thuc thu nhat: "<<s1<<endl;
	node *p2=l2.head;
	int s2=0;
	while(p2!=NULL){
		s2 = s2 + p2->ChiSo * pow(x,p2->SoMu);
		p2=p2->next;
	}
	cout<<"gia tri cua da thuc thu hai: "<<s2<<endl;
}

//sap xep danh sach
void SapXep(list &l){
	if(l.head==NULL){
		cout<<"DSLK rong thi sap xep cai gi"<<endl;
	}
	else{
		node *p=l.head;
		while(p!=NULL){
			node *q=p->next;
			while(q!=NULL){
				if(p->SoMu>=q->SoMu){
					int temp=p->SoMu;
					p->SoMu=q->SoMu;
					q->SoMu=temp;
					int temp1=p->ChiSo;
					p->ChiSo=q->ChiSo;
					q->ChiSo=temp1;
					
				}
				q=q->next;
			}
			
			p=p->next;
		}
	}
}

//tinh tong 2 da thuc
void TinhTong(list l1, list l2){
	list l3;
	Init1(l3);
	node *p=l1.head;
	node *z=new node;
	while(p!=NULL){
		node *q=l2.head;
		z=get_node(p->ChiSo,p->SoMu);
		while(q!=NULL){
			if(p->SoMu==q->SoMu){
				z->ChiSo = z->ChiSo + q->ChiSo;
				q->ChiSo=q->SoMu=0;
			}
			q=q->next;
		}
		add_tail(l3,z);
		p=p->next;
	}

	node *k=l2.head;
	node *o=new node;
	while(k!=NULL){
		if(k->SoMu!=0){
			o=get_node(k->ChiSo,k->SoMu);
			add_tail(l3,o);
		}
		k=k->next;
	}
	SapXep(l3);
	Output(l3);
}

//nhan 2 da thuc
void NhanDaThuc(list &l1, list &l2){
	SapXep(l1);
	SapXep(l2);
	list l4;
	Init1(l4);
	list l5;
	Init1(l5);
	node *p=l1.head;
	while(p!=NULL){
		node *q=l2.head;
		while(q!=NULL){
			node *z=new node;
			z=get_node(p->ChiSo*q->ChiSo,p->SoMu+q->SoMu);
			//cout<<q->ChiSo*q->ChiSo<<"   "<<q->SoMu+q->SoMu<<endl;
			add_tail(l4,z);
			q=q->next;
		}
		p=p->next;
	}
	SapXep(l4);
	//Output(l4);
	node *h=l4.head;
	while(h!=NULL){
		node *e=new node;
		e=get_node(h->ChiSo,h->SoMu);
		node *t=h->next;
		while(t!=NULL){
			if(h->SoMu==t->SoMu && h->SoMu!=0 && t->SoMu!=0){
				e->ChiSo=e->ChiSo+t->ChiSo;
				t->SoMu=0;
			}
			t=t->next;
		}
		add_tail(l5,e);
		h=h->next;
	}
	Output(l5);
}

//dao ham bac 1 cua da thuc
void DaoHam(list l1){
	SapXep(l1);
	node *p=l1.head;
	while(p!=NULL){
		p->ChiSo=p->ChiSo*p->SoMu;
		p->SoMu=p->SoMu-1;
		p=p->next;
	}
	if(l1.head->ChiSo==0){
		l1.head=l1.head->next;
	}
	cout<<"ket qua sau khi dao ham: "<<endl;
	Output(l1);
}

int main(){
	list l1,l2;
	Init(l1,l2);
	Input(l1,l2);
	cout<<"**************************************************"<<endl;
	//NhanDaThuc(l1,l2);
	cout<<"**************************************************"<<endl;
	//Output(l1);
	cout<<"**************************************************"<<endl;
	//Output(l2);
	cout<<"**************************************************"<<endl;
	//Count(l1,l2);
	cout<<"**************************************************"<<endl;
	//TinhTong(l1,l2);
	cout<<"**************************************************"<<endl;
	DaoHam(l1);
	return 0;
}
