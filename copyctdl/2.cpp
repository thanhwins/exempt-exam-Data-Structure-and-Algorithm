//LeNhoa
#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int inf;
	struct node *next;
}*last;

class ds_vong{
	public:
		node* ktao(int);
		int dem();
		void chen_dau(int);
		void chen_vtri(int,int);
		void chen_cuoi(int);
		void xoa_dau();
		void xoa_vtri(int);
		void xoa_cuoi();
		void tim(int k);
		void duyet();
		void sxep();
		void dao();
		void hthi();
};

void ds_vong::hthi(){
	cout<<"danh sach la: ";
	node *s;
	s = last->next;
	while(s!=last){
		cout<<s->inf<<" ";
		s = s->next;
	}
	cout<<last->inf<<endl;
}

int ds_vong::dem(){
	if(last==NULL)	return 0;
	int x = 1;
	node *s;
	s = last;
	while(s->next!=last){
		x++;
		s = s->next;
	}
	return x;
}

node* ds_vong::ktao(int k){
	node *temp;
	temp = new(node);
	temp->inf = k;
	temp->next = NULL;
	//last = temp;
	return temp;
}

void ds_vong::chen_dau(int x){
	if(last==NULL){
		last = ktao(x);
		last->next = last;
	}
	else{
		node *temp;
		temp = ktao(x);
		temp->next = last->next;
		last->next = temp;
	}
}

void ds_vong::chen_cuoi(int x){
	if(last==NULL){
		last = ktao(x);
		last->next = last;
	}
	else{
		node *temp;
		temp = ktao(x);
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

void ds_vong::chen_vtri(int x, int vt){
	if(vt<1 || vt>dem()){
		cout<<"khong the chen sau vi tri tren";
	}
	else{
		if(vt==dem()){
			chen_cuoi(x);
		}
		else{
			node *s, *tem;
			s = last->next;
			for(int i=1; i<vt; i++){
				s = s->next;
			}
			tem = ktao(x);
			tem->next = s->next;
			s->next = tem;
		}
	}
}

void ds_vong::xoa_dau(){
	if(dem()==1){
		last = NULL;
	}
	else{
		node *s;
		s = last->next;
		last->next = s->next;
		free(s);
	}
}

void ds_vong::xoa_cuoi(){
	if(dem()==0 || dem()==1){
		last = NULL;
	}
	else{
		node *s, *t;
		s = last;
		for(int i=1; i<dem(); i++){
			s = s->next;
		}
		t = s->next;
		s->next = last->next;
		last = s;
		free(t);
	}
}

void ds_vong::xoa_vtri(int vt){
	if(vt<1 || vt>dem()){
		cout<<"khong co node de xoa";
	}
	else{
		if(vt==1){
			xoa_dau();
		}
		else{
			if(vt==dem()){
				xoa_cuoi();
			}
			else{
				node *s, *t;
				s = last;
				for(int i=1; i<vt; i++){
					s = s->next;
				}
				t = s->next;
				s->next = t->next;
				free(t);
			}
		}
	}
}

void ds_vong::tim(int k){
	if(last==NULL){
		cout<<"ds rong";
	}
	else{
		node *s;
		int vt = 1;
		s = last->next;
		while(s==last){
			if(s->inf == k){
				cout<<vt<<" ";
			}
			s = s->next;
			vt++;
		}
	}
}

void ds_vong::duyet(){
	
}

void ds_vong::sxep(){
	if(last==NULL){
		cout<<"ds rong";
	}
	else{
		node *s, *t;
		s = last->next;
		while(s!=last){
			for(t = s->next; t!=last->next; t = t->next){
				if(s->inf > t->inf){
					int k = s->inf;
					s->inf = t->inf;
					t->inf = k;
				}
			}
			s = s->next;
		}
	}
}

void ds_vong::dao(){
	
}

main(){
	ds_vong ds;
	int a=0, x, y;
	while(a<10){
		cout<<"************\n";
		cout<<"1.them node trai\n2.them node phai\n3.them vao vi tri\n4.xoa node trai\n5.xoa node phai\n6.xoa o vi tri\n7.sap xep danh sach\n8.dao nguoc danh sach\n9.duyet\n10.thoat\nban chon: ";
		cin>>a;
		switch(a){
			case 1:{
				cout<<"nhap gia tri muon chen:";
				cin>>x;
				ds.chen_dau(x);
				break;
			}
			case 2:{
				cout<<"nhap gia tri muon chen:";
				cin>>x;
				ds.chen_cuoi(x);
				break;
			}
			case 3:{
				cout<<"nhap gia tri va vi tri muon chen:";
				cin>>x>>y;
				ds.chen_vtri(x,y);
				break;
			}
			case 4:{
				ds.xoa_dau();
				break;
			}
			case 5:{
				ds.xoa_cuoi();
				break;
			}
			case 6:{
				cout<<"nhap vi tri muon xoa: ";
				cin>>x;
				ds.xoa_vtri(x);
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
				ds.hthi();
				break;
			}
		}
	}
//	ds.chen_cuoi(2);
//	ds.chen_dau(7);
//	ds.chen_cuoi(4);
//	ds.chen_vtri(3,3);
//	ds.xoa_vtri(2);
//	ds.xoa_cuoi();
//	ds.xoa_dau();
//	ds.sxep();
//	ds.hthi();
}

