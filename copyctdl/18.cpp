//LeNhoa_ok
//hang doi hai diem cuoi bang dslk don??????????
#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int inf;
	node *next;
}*first, *last;

class queue{
	public:
		node *ktao(int);
		int empty();
		int full();
		int size();
		int pop_first();
		int pop_last();
		int get_first();
		int get_last();
		void push_first(int);
		void push_last(int);
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
	return(first==NULL);
}

int queue::full(){
	node *t;
	return(t==NULL);
}

int queue::pop_first(){
	if(empty()){
		cout<<"queue rong\n";
		return 0;
	}
	else{
		node *t;
		t = first;
		int k = t->inf;
		first = first->next;
		free(t);
		return k;
	}
}

int queue::pop_last(){
	if(empty()){
		cout<<"queue rong\n";
		return 0;
	}
	else{
		node *t, *s;
		t = first;
		while(t->next!=last){
			t = t->next;
		}
		s = t->next;
		int k = s->inf;
		t->next = NULL;
		last = t;
		free(s);
		return k;
	}
}

int queue::get_first(){
	if(empty()){
		cout<<"queue rong\n";
		return 0;
	}
	return(first->inf);
}

int queue::get_last(){
	if(empty()){
		cout<<"queue rong\n";
		return 0;
	}
	return(last->inf);
}

int queue::size(){
	int dem = 0;
	node *t;
	t = first;
	while(t->next!=NULL){
		dem++;
		t = t->next;
	}
	return dem;
}

void queue::push_first(int x){
	if(empty()){
		first = ktao(x);
		last = first;
	}
	else{
		node *t;
		t = ktao(x);
		t->next =  first;
		first = t;
	}
}

void queue::push_last(int x){
	if(empty()){
		last = ktao(x);
		first = last;
	}
	else{
		node *t;
		t = ktao(x);
		last->next = t;
		last = t;
	}
}

void queue::show(){
	if(empty())	cout<<"queue rong\n";
	else{
		cout<<"danh sach queue la: ";
		node *t;
		t = first;
		while(t!=NULL){
			cout<<t->inf<<" ";
			t = t->next;
		}
		cout<<endl;
	}
}

main(){
	queue q;
	q.push_last(13);
	q.show();
	q.push_first(7);
	q.push_last(9);
	q.pop_last();
	q.show();
}
