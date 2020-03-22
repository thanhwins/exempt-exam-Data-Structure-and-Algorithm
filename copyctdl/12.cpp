//LeNhoa_tam_on
//hang doi vong bang mang
#include<iostream>
using namespace std;
struct queue{
	char a[100];
	int in = 0;
	int out = 0;
};

int empty(queue q){
	return(q.in==q.out);
}

int size(queue q){
	int dem = 0;
	int i = q.out;
	while(i!=q.in){
		if(i==99)	i = 0;
		else	i++;
		dem++;
	}
	return dem;
}

int full(queue q){
	return(size(q)==100);
}

char pop(queue &q){
	char x = q.a[q.out];
//	q.a[q.out] = 0;
	if(q.out==99)	q.out = 0;
	else	q.out+=1;
	return x;
}

char front(queue &q){
	char x = q.a[q.out];
	return x;
}

void push(queue &q, char c){
	if(!full(q)){
		q.a[q.in] = c;
		if(q.in==99){
			q.in = 0;
		}
		else	q.in++;
//		q.a[q.in] = c;
	}
	else{
		cout<<"queue da day\n";
	}
}

main(){
	queue q;
	cout<<empty(q)<<endl;
	push(q,'6');
	push(q,'7');
	push(q,'8');
	pop(q);
	push(q,'9');
	push(q,'0');
	push(q,'1');
//	cout<<size(q);
//	cout<<"\n"<<empty(q);
		while(!empty(q)){
		cout<<pop(q)<<" ";
	}
	cout<<endl;
}

