//LeNhoa_1
//dslk kep sxep
#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int inf;
	struct node *next;
	node *pre;
}*start;

class dsk_sx{
	public:
		node* ktao(int);
		void them(int);
		void hthi();
};

node* dsk_sx::ktao(int k){
	node *temp;
	temp = new node();
	temp->inf = k;
	temp->next = NULL;
	temp->pre = NULL;
	return temp;
}

void dsk_sx::them(int k){
	if(start==NULL){
		start = ktao(k);
	}
	else{
		node *a;
		a = ktao(k);
		if(start->inf > k){
			a->next = start;
			start->pre = a;
			start = a;
		}
		else{
			node *s;
			s = start;
			while((s->next->inf) < k){
				s = s->next;
			}
			a->next = s->next;
			s->next->pre = a;
			s->next = a;
			a->pre = s;
		}
	}
}

void dsk_sx::hthi(){
	cout<<"danh sach la: ";
	node *s;
	s = start;
	while(s!=NULL){
		cout<<s->inf<<" ";
		s = s->next;
	}
}

main(){
	dsk_sx ds;
	int a=0, x, y;
	while(a<3){
		cout<<"************\n";
		cout<<"1.them node\n2.hien thi danh sach\n3.thoat\nban chon: ";
		cin>>a;
		switch(a){
			case 1:{
				cout<<"nhap gia tri muon chen:";
				cin>>x;
				ds.them(x);
				break;
			}
			case 2:{
				ds.hthi();
				break;
			}
		}
	}
//	ds.them(9);
//	ds.them(7);
//	ds.them(4);
//	ds.them(8);
//	ds.hthi();
//	
}

