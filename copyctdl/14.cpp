//LeNhoa_tam_on
//hang doi hai diem cuoi bang mang
#include<iostream>
using namespace std;

struct queue{
	int info[100];
	int first = -1;
	int last = -1;
};

int empty(queue q){
	return(q.first == -1 && q.last== -1);
}

int size(queue q){
	if(empty(q))	return 0;
	int dem = 0;
	for(int i = q.first; i<=q.last; i++){
		dem++;
	}
	return dem;
}

int full(queue q){
	return(size(q)==100);
}

int pop_f(queue &q){
	int x = q.info[q.first];
	q.first++;
	return x;
}

int pop_l(queue &q){
	int x = q.info[q.last];
	q.last--;
	return x;
}

int get_f(queue &q){
	int x = q.info[q.first];
	return x;
}

int get_l(queue &q){
	int x = q.info[q.last];
	return x;
}

void push_f(queue &q, int x){
	if(full(q))	cout<<"queue da day\n";
	if(empty(q)){
		q.first = 0;
		q.last = 0;
		q.info[0] = x;
	}
	else{
		if(q.first>0){
			q.first -= 1;
			q.info[q.first] = x;
		}
		if(q.first==0 && q.last<99){
			for(int i=q.last; i>=0; i--){
				q.info[i+1] = q.info[i];
			}
			q.info[0] = x;
			q.last++;
		}
	}
}

void push_l(queue &q, int x){
	if(empty(q)){
		q.first = 0;
		q.last = 0;
		q.info[0] = x;
	}
	else{
		if(full(q))	cout<<"queue da day\n";
		else{
			if(q.last<99){
				q.last += 1;
				q.info[q.last] = x;
			}
			if(q.last==99){
				for(int i=q.first; i<=q.last; i++){
					q.info[i-1] = q.info[i];
				}
				q.info[99] = x;
				q.first--;
			}
		}
	}
}

void show_first(queue q){
	cout<<"danh sach queue duyet tu dau: ";
	int i = q.first;
	while(i<=q.last){
		cout<<q.info[i]<<" ";
		i++;
	}
	cout<<endl;
}

void show_last(queue q){
	cout<<"danh sach queue duyet tu cuoi: ";
	int i = q.last;
	while(i>=q.first){
		cout<<q.info[i]<<" ";
		i--;
	}
	cout<<endl;
}

main(){
	queue q;
	cout<<empty(q)<<endl;
	push_l(q,6);
	push_l(q,9);
	push_f(q,3);
	show_first(q);
}

