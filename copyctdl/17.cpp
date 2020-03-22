//LeNhoa_ok
//hang doi uu tien bang dslk
#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int pri;
	int info;
	node *next;
}*top;

class queue{
	public:
		node *ktao(int,int);
		int empty();
		int full();
		int size();
		int pop();
		int front();
		void push(int,int);
		void show();
};

node* queue::ktao(int x, int y){
	node *t;
	t = new(node);
	t->info = x;
	t->pri = y;
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
	if(empty()){
		cout<<"queue rong\n";
		return 0;
	}
	else{
		node *t;
		t = top;
		int k = t->info;
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
	return(top->info);
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

void queue::push(int gt, int ut){
	if(empty()){
		top = ktao(gt,ut);
	}
	else{
		node *t, *s;
		s = ktao(gt,ut);
		if(top->pri < ut){
			s->next = top;
			top = s;
		}
		else{
			t = top;
			while(t->next!=NULL && t->next->pri > ut){
				t = t->next;
			}
			s->next = t->next;
			t->next = s;
		}
	}
}

void queue::show(){
	if(empty())	cout<<"queue rong\n";
	else{
		cout<<"danh sach queue la: ";
		node *t;
		t = top;
		while(t!=NULL){
			cout<<t->info<<" ";
			t = t->next;
		}
		cout<<endl;
	}
}



main(){
	queue q;
	q.push(4,4);
	q.push(2,7);
	q.pop();
	q.push(8,6);
	q.push(9,1);
	q.push(1,9);
	q.show();
}

