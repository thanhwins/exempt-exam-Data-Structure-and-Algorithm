//LeNhoa
#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int inf;
	node *next;
}*in, *out;

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
	return(out==NULL);
}

int queue::full(){
	node *t;
	return(t==NULL);
}

int queue::pop(){
	if(empty()){
		cout<<"queue rong\n";
		return;
	}
	else{
		node *t;
		t = out;
		int k = t->inf;
		out = out->next;
		free(t);
		return k;
	}
}

int queue::front(){
	
}

int queue::size(){
	
}

void queue::push(int x){
	
}

void queue::show(){
	if(empty())	cout<<"queue rong\n";
	else{
		cout<<"danh sach queue la: ";
		node *t;
		t = out;
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

