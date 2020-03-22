//LeNhoa
#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
struct node{
	char inf;
	node *next;
}*top;

class stack{
	public:
		node* ktao(char);
		void push(char);
		char pop();
		char Top();
		void show();
		int empty();
		int full();
		int size();
		void hauTo();
		int gtHauTo();
};

int stack::full(){
	node *t;
	t = new (node);
	return(t==NULL);
}

node* stack:: ktao(char x){
	if(!full()){
		node *tmp;
		tmp = new (node);
		tmp->inf = x;
		tmp->next = NULL;
	}
}

void stack::push(char k){
	if(top==NULL){
		top = ktao(k);
	}
	else{
		node *tmp;
		tmp = ktao(k);
		tmp->next = top;
		top = tmp;
	}
}

char stack::pop(){
	node *t;
	t = top;
	char k = t->inf;
	top = t->next;
	free(t);
	return k;
}

char stack::Top(){
	return(top->inf);
}

void stack::show(){
	node *t;
	t = top;
	cout<<"stack: ";
	while(t!=NULL){
		cout<< t->inf <<" ";
		t = t->next;
	}
	cout<<endl;
} 

int stack::empty(){
	return(top==NULL);
}

int stack::size(){
	int count = 0;
	node *t;
	t = top;
	while(t!=NULL){
		count++;
		t = t->next;
	}
	return count;
}

int stack::gtHauTo(){
	string a;
	cout<<"nhap bt hau to: ";
	cin>>a;
	stack s;
	int x, y;
	for(int i=0; i < a.length(); i++){
		if( a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/' ){
			push(a[i]);
		}
		else{
			y = pop() - '0';
			x = pop() - '0';
			if(a[i]=='+')	x = x+y;
			if(a[i]=='-')	x = x-y;
			if(a[i]=='*')	x = x*y;
			if(a[i]=='/')	x = x/y;
			push(x+'0');
		}
	}
	x = pop() - '0';
	return x;
}

void stack::hauTo(){
	
}

main(){
	stack s;
	int a=0;
	char x;
	while(a<9){
		cout<<"************\n";
		cout<<"1.kt rong\n2.kt day\n3.lay top\n4.lay size\n5.dua phan tu vao stack\n6.bo dinh stack\n7.duyet stack\n8.gia tri bt hau to\n9.thoat\nban chon: ";
		cin>>a;
		switch(a){
			case 1:{
				cout<<s.empty();
				break;
			}
			case 2:{
				cout<<s.full();
				break;
			}
			case 3:{
				cout<<"dinh stack: "<<s.Top();
				break;
			}
			case 4:{
				cout<<"kich thuoc stack: "<<s.size();
				break;
			}
			case 5:{
				cout<<"nhap phan tu muon dua vao: ";
				cin>>x;
				s.push(x);
				break;
			}
			case 6:{
				s.pop();
				break;
			}
			case 7:{
				s.show();
				break;
			}
			case 8:{
				s.gtHauTo();
				break;
			}
		}
	}
//	s.push('4');
//	s.push('6');
//	s.show();
}

