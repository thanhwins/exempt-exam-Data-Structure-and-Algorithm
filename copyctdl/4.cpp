//LeNhoa_ok
//dslk kep
#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int inf;
	node *pre;
	node *next;
}*start;

class ds_kep{
	public:
		node* ktao(int);
		int dem();
		void chen_trai(int);
		void chen_vtri(int,int);
		void chen_phai(int);
		void xoa_trai();
		void xoa_vtri(int);
		void xoa_phai();
		void tim(int k);
		void duyet();
		void sxep();
		void dao();
		void hthi();
};

int ds_kep::dem(){
//	if(start==NULL)	return 0;
	int x = 0;
	node *s;
	s = start;
	while(s!=NULL){
		x++;
		s = s->next;
	}
	return x;
}

node* ds_kep::ktao(int k){
	node *temp;
	temp = new(node);
	temp->inf = k;
	temp->next = NULL;
	temp->pre = NULL;
	return temp;
}

void ds_kep::chen_trai(int k){
	if(start==NULL){
		start = ktao(k);
	}
	else{
		node *s;
		s = ktao(k);
		s->next = start;
		start->pre = s;
		start = s;
	}
}

void ds_kep::chen_phai(int k){
	if(start==NULL){
		start = ktao(k);
	}
	else{
		node *s, *t;
		s = start;
		t = ktao(k);
		while(s->next!=NULL){
			s = s->next;
		}
		s->next = t;
		t->pre = s;
	}
}

void ds_kep::chen_vtri(int gt, int vt){
	if(vt < 1 || vt > dem()){
		cout<<"khong chen duoc";
	}
	else{
		if(vt == dem()){
			chen_phai(gt);
		}
		else{
			node *s, *t;
			s = start;
			t = ktao(gt);
			for(int i=1; i<vt; i++){
				s = s->next;
			}
			t->next = s->next;
			s->next->pre = t;
			s->next = t;
			t->pre = s;
		}
	}
}

void ds_kep::xoa_trai(){
	if(start == NULL){
		cout<<"ds rong";
	}
	else{
		node *s;
		s = start;
		start = s->next;
		start->pre = NULL;
//		s->next = NULL;
		free(s);
	}
}

void ds_kep::xoa_phai(){
	if(start==NULL){
		cout<<"ds rong";
	}
	else{
		node *s, *t;
		s = start;
		while(s->next->next != NULL){
			s = s->next;
		}
		t = s->next;
		s->next = NULL;
		t->pre = NULL;
		free(t);
	}
}

void ds_kep::xoa_vtri(int vt){
	if(vt < 1 || vt > dem()){
		cout<<"co ton taij vi tri de xoa";
	}
	else{
		if(vt == dem()){
			xoa_phai();
		}
		else{
			if(vt==1){
				xoa_trai();
			}
			else{
				node *s, *t;
				s = start;
				for(int i=1; i<(vt-1); i++){
					s = s->next;
				}
				t = s->next;
				t->next->pre = s;
				s->next = t->next;
				free(t);
			}
		}
	}
}

void ds_kep::tim(int k){
	int vt = 0;
	node *s;
	s = start;
	while(s!=NULL){
		vt++;
		if(s->inf == k){
			cout<<vt<<" ";
		}
		s = s->next;
	}
}

void ds_kep::sxep(){
	if(start==NULL){
		cout<<"ds rong";
	}
	else{
		node *s, *t;
		s = start;
		while(s!=NULL){
			for(t = s->next; t!=NULL; t = t->next){
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


void ds_kep::hthi(){
	cout<<"danh sach la: ";
	node *s;
	s = start;
	while(s!=NULL){
		cout<<s->inf<<" ";
		s = s->next;
	}
}

main(){
	ds_kep ds;
	int a=0, x, y;
	while(a<9){
		cout<<"************\n";
		cout<<"1.them node phai\n2.them node trai\n3.them vao vi tri\n4.xoa node trai\n5.xoa node phai\n6.xoa o vi tri\n7.sap xep danh sach\n8.dao nguoc danh sach\n9.duyet\n10.thoat\nban chon: ";
		cin>>a;
		switch(a){
			case 1:{
				cout<<"nhap gia tri muon chen:";
				cin>>x;
				ds.chen_phai(x);
				break;
			}
			case 2:{
				cout<<"nhap gia tri muon chen:";
				cin>>x;
				ds.chen_trai(x);
				break;
			}
			case 3:{
				cout<<"nhap gia tri va vi tri muon chen:";
				cin>>x>>y;
				ds.chen_vtri(x,y);
				break;
			}
			case 4:{
				ds.xoa_trai();
				break;
			}
			case 5:{
				ds.xoa_phai();
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
				ds.hthi();
				break;
			}
		}
	}
//	ds.chen_trai(2);
//	ds.chen_trai(5);
//	ds.chen_phai(9);
//	ds.chen_vtri(6,2);
//	ds.chen_trai(6);
//	ds.sxep();
//	ds.xoa_trai();
//	ds.xoa_vtri(2);
//	ds.hthi();
//	cout<<endl;
//	ds.tim(6);
}

