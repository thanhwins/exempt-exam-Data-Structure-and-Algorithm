//LeNhoa_tam_on
//hang doi bang mang
#include<iostream>
using namespace std;
struct queue{
	char a[100];
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
	char x = q.a[q.out];
	q.out++;
	return x;
}

char front(queue &q){
	char x = q.a[q.out];
	return x;
}

void push(queue &q, char c){
	if(!full(q)){
		q.in++;
		q.a[q.in] = c;
	}
	else{
		cout<<"queue da day\n";
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
	int a=0;
	char x;
	while(a<9){
		cout<<"************\n";
		cout<<"1.kt rong\n2.kt day\n3.lay phan tu dau queue\n4.lay size\n5.dua phan tu vao queue\n6.xoa dau queue\n7.duyet queue\n8.thoat\nban chon: ";
		cin>>a;
		switch(a<8){
			case 1:{
				cout<<empty(q);
				break;
			}
			case 2:{
				cout<<full(q);
				break;
			}
			case 3:{
				cout<<"dinh stack: "<<front(q);
				break;
			}
			case 4:{
				cout<<"kich thuoc stack: "<<size(q);
				break;
			}
			case 5:{
				cout<<"nhap phan tu muon dua vao: ";
				cin>>x;
				push(q,x);
				break;
			}
			case 6:{
				pop(q);
				break;
			}
			case 7:{
				show(q);
				break;
			}
		}
	}
//	cout<<empty(q)<<endl;
//	push(q,'4');
//	push(q,'7');
//	push(q,'1');
//	cout<<size(q);
//	cout<<empty(q)<<endl;
//	cout<< pop(q);
//	show(q);
}

