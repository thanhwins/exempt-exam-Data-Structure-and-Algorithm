//LeNhoa_1
#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int inf;
	struct node *next;
}*start;

class ds_sx{
	public:
		node* ktao(int);
		void them(int);
		void hthi();
};

node* ds_sx::ktao(int k){
	node *temp;
//	temp = new(node);
	temp = new node();
	temp->inf = k;
	temp->next = NULL;
	return temp;
}

void ds_sx::them(int k){
	if(start==NULL){
		start = ktao(k);
	}
	else{
		node *a;
		a = ktao(k);
		if(start->inf > k){
			a->next = start;
			start = a;
		}
		else{
			node *s;
			s = start;
//			while(s->next != NULL){
				while((s->next->inf) < k){
					s = s->next;
				}
//			}
			a->next = s->next;
			s->next = a;
		}
	}
}

void ds_sx::hthi(){
	cout<<"danh sach la: ";
	node *s;
	s = start;
	while(s!=NULL){
		cout<<s->inf<<" ";
		s = s->next;
	}
}

main(){
	ds_sx ds;
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
//	ds.them(11);
//	ds.hthi();
	
}

