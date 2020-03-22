//LeNhoa_ok
//hang doi uu tien bang mang
#include<iostream>
using namespace std;

struct queue{
	char info[100];
	int pri[100];
	int in = -1;
	int out = 0;
};

int empty(queue q){
	return(q.in < q.out);
}

int full(queue q){
	return(q.in==99);
}

int size(queue q){
	int dem = 0;
	for(int i = q.out; i<=q.in; i++){
		dem++;
	}
	return dem;
}

char pop(queue &q){
	char x = q.info[q.out];
	q.out++;
	return x;
}

char front(queue &q){
	char x = q.info[q.out];
	return x;
}

void push(queue &q, char gt, int ut){
	if(empty(q)){
		q.in = 0;
		q.info[0] = gt;
		q.pri[0] = ut;
	}
	else{
		if(!full(q)){
			int i = q.in;
			while(i>=q.out && q.pri[i] < ut){
				q.info[i+1] = q.info[i];
				q.pri[i+1] = q.pri[i];
				i--;
			}
			q.info[i+1] = gt;
			q.pri[i+1] = ut;
			q.in++;
		}
		else{
			cout<<"queue da day\n";
		}	
	}
}

void show(queue q){
	cout<<"danh sach queue: ";
	while(!empty(q)){
		cout<<pop(q)<<" ";
	}
	cout<<endl;
}

main(){
	queue q;
//	cout<<empty(q);
	push(q,'4',5);
	push(q, '2', 2);
	push(q, '1', 7);
//	push(q, '2', 6);
	cout<<size(q)<<endl;
	show(q);
//	while(!empty(q)){
//		cout<<pop(q)<<" ";
//	}
}
