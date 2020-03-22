//LeNhoa_ok
//hang doi bang danh sach lien ket
#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int inf;
	node *next;
}*top;

class queue{
	public:
		node *ktao(int);
		int empty();
		int full();
		int size();
		int pop();
		int front();
		void push(int);
		void show();
};

node* queue::ktao(int x){
	node *t;
	t = new(node);
	t->inf = x;
	t->next = NULL;
	return t;
}

int queue::empty(){
	return(top==NULL);
}

int queue::full(){
	node *t;
	return(t==NULL);
}

int queue::pop(){
	if(top==NULL){
		cout<<"queue rong\n";
		return 0;
	}
	else{
		node *t;
		t = top;
		int k = t->inf;
		top = top->next;
		free(t);
		return k;
	}
}

int queue::front(){
	if(empty()){
		cout<<"queue rong\n";
		return 0;
	}
	return(top->inf);
}

int queue::size(){
	node *t;
	t = top;
	int dem = 0;
	while(t==NULL){
		dem++;
		t = t->next;
	}
	return dem;
}

void queue::push(int x){
	if(top==NULL){
		top = ktao(x);
	}
	else{
		node *t, *s;
		s = ktao(x);
		t = top;
		while(t->next!=NULL){
			t = t->next;
		}
		t->next = s;
	}
}

void queue::show(){
	if(empty())	cout<<"queue rong\n";
	else{
		cout<<"danh sach queue la: ";
		node *t;
		t = top;
		while(t!=NULL){
			cout<<t->inf<<" ";
			t = t->next;
		}
		cout<<endl;
	}
}

main(){
	queue q;
//	q.push(13);
//	q.push(7);
//	q.pop();
//	q.push(9);
//	q.show();
}

