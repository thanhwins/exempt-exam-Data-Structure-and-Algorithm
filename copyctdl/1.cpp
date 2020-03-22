//LeNhoa_ok
//dslk don
#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int inf;
	node *next;
}*start;

class single_list{
	public:
		node* ktao(int);
		void chend(int);
		void chenc(int);
		void chenvt(int,int);
		void xoad();
		void xoac();
		void xoavt(int);
		void dao();
		void sxep();
		void tim(int);
		void duyet();
		int dem();
};

node* single_list::ktao(int k){
	node *tmp;
	tmp = new (node);
	tmp->inf = k;
	tmp->next = NULL;
//	return tmp;
}

int single_list::dem(){	
	int vt = 0;
	node *s;
	s = start;
	while(s!=NULL){
		s= s->next;
		vt++;
	}
	return vt;
}
void single_list::chend(int k){
	if(start==NULL){
		start = ktao(k);
	}
	else{
		node *tmp;
		tmp = ktao(k);
		tmp->next = start;;
		start = tmp;
	}
}

void single_list::chenc(int k){
	if(start == NULL){
		start = ktao(k);
	}
	else{
		node *s, *t;
		t = ktao(k);
		s = start;
		while(s->next != NULL){
			s = s->next;
		}
		s->next = t;
	}
}

void single_list::chenvt(int k, int vt){
	if(vt<1 || vt>dem()){
		cout<<"khong the chen du lieu";
	}
	else{
		if(vt==1){
			chend(k);
		}
		else{
			node *s, *t;
			s = start;
			for(int i=1; i<vt-1; i++){
				s = s->next;
			}
			t = ktao(k);
			t->next = s->next;
			s->next = t;
		}
	}
}

void single_list::xoad(){
	if(start==NULL){
		cout<<"ds rong";
	}
	else{
		node *s;
		s = start;
		start = s->next;
		free(s);
	}
}

void single_list::xoac(){
	if(start==NULL){
		cout<<"ds rong";
	}
	else{
		node *s,*t;
		s = start;
		while(s->next!=NULL){
			s = s->next;
		}
		t = s->next;
		s->next = NULL;
		free(t);
	}
}

void single_list::xoavt(int vt){
	if(vt<1 || vt>dem()){
		cout<<"khong ton tai vi tri tren";
	}
	else{
		node *s, *t;
		s = start;
		for(int i=1; i<vt; i++){
			s = s->next;
		}
		t = s->next;
		s->next = t->next;
		free(t);
	}
}

void single_list::tim(int k){
	if(start==NULL){
		cout<<"ds rong";
	}
	else{
		cout<<"vi tri: ";
		node *s;
		s = start;
		int vt = 1;
		while(s== NULL){
			if(s->inf == k){
				cout<<vt<<" ";
			}
		}
	}
}

void single_list::sxep(){
	node *s, *t;
	s = start;
	while(s!=NULL){
		t = s->next;
		while(t != NULL){
			if(t->inf < s->inf){
				int x = t->inf;
				t->inf = s->inf;
				s->inf = x;
			}
			t = t->next;
		}
		s = s->next;
	}
}

void single_list::dao(){
	node *t1,*t2,*t3;
	if(start==NULL){
		cout<<"ds rong";
		return;
	}
	if(start->next==NULL)	return;
	t1 = start;
	t2 = t1->next;
	t3 = t2->next;
	t1->next = NULL;
	t2->next = t1;
	while(t3!=NULL){
		t1 = t2;
		t2 = t3;
		t3 = t3->next;
		t2->next = t1;
	}
	start = t2;
}

void single_list::duyet(){
	if(start==NULL){
		cout<<"ds rong";
	}
	else{
		cout<<"danh sach: ";
		node *s;
		s = start;
		while(s!= NULL){
			cout<<s->inf<<" ";
			s = s->next;
		}
	}
	cout<<endl;
}

main(){
	single_list ds;
	int a=0, x, y;
	while(a<10){
		cout<<"************\n";
		cout<<"1.them node phai\n2.them node trai\n3.them vao vi tri\n4.xoa node trai\n5.xoa node phai\n6.xoa o vi tri\n7.sap xep danh sach\n8.dao nguoc danh sach\n9.duyet\n10.thoat\nban chon: ";
		cin>>a;
		switch(a){
			case 1:{
				cout<<"nhap gia tri muon chen:";
				cin>>x;
				ds.chenc(x);
				break;
			}
			case 2:{
				cout<<"nhap gia tri muon chen:";
				cin>>x;
				ds.chend(x);
				break;
			}
			case 3:{
				cout<<"nhap gia tri va vi tri muon chen:";
				cin>>x>>y;
				ds.chenvt(x,y);
				break;
			}
			case 4:{
				ds.xoad();
				break;
			}
			case 5:{
				ds.xoac();
				break;
			}
			case 6:{
				cout<<"nhap vi tri muon xoa: ";
				cin>>x;
				ds.xoavt(x);
				break;
			}
			case 7:{
				ds.sxep();
				break;
			}
			case 8:{
				ds.dao();
				break;
			}
			case 9:{
				ds.duyet();
				break;
			}
		}
	}
//	ds.chenc(4);
//	ds.chend(9);
//	ds.chenvt(7,2);
//	ds.sxep();
//	ds.duyet();
}

