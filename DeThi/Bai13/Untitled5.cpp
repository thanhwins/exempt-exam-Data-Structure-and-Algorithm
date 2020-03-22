//cac thao tac tren hang doi uu tien su dung mang
#include<iostream>
using namespace std;

#define max 100

//khai bao cau truc cua mot hang doi uu tien
struct queue{
	int inp;
	int out;
	int priority[max];//muc do uu tien cua node
	int node[max];//du lieu	
};

//khai bao hang doi rong
void Init(queue *q){
	q->inp=q->out=-1;
}

//kiem tra tinh rong cua hang doi
int Empty(queue *q){
	if(q->inp==q->out){
		return 1;
	}
	return 0;
}

//kiem tra tinh day cua hang doi
int Full(queue *q){
	if(q->inp==max-1){
		return 1;
	}
	return 0;
}

//dua du lieu vao hang doi
void Push(queue *q, int x, int y){
	if(Full(q)==0){
		q->inp=q->inp+1;
		q->node[q->inp]=x;
		q->priority[q->inp]=y;
		//cout<<q->node[q->inp]<<endl;
	}
	else{
		cout<<"hang doi da day, khong the dua them dua lieu vao"<<endl;
	}
}

//lay du lieu ra khoi hang doi
int Pop(queue *q){
	if(Empty(q)==0){
		q->out=q->out+1;
		int x=q->node[q->out];
		return x;
	}
	else{
		cout<<"hang doi rong";
	}
}

void Output(queue *q){
	int i=q->out+1;
	//i=i+1;
	cout<<"cac phan tu co mat trong hang doi: "<<endl;
	while(i<=q->inp){
		cout<<"do uu tien: "<<q->priority[i]<<" co gia tri: "<<q->node[i]<<endl;
		i++;
	}
}

void SapXep(queue *q){
	//cout<<q->out;
	for(int i=0;i<q->inp;i++){
		for(int j=i+1;j<=q->inp;j++){
			if(q->priority[i]<=q->priority[j]){
				//cout<<"here";
				int a=q->priority[i];
				q->priority[i]=q->priority[j];
				q->priority[j]=a;
				int b=q->node[i];
				q->node[i]=q->node[j];
				q->node[j]=b;
			}
		}
	}
}

void Input(queue *q){
	int n;
	cout<<"khai bao so luong node ban muon nhap cho hang doi: ";
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cout<<"nhap gia tri cua node: ";
		cin>>x;
		int y;
		cout<<"nhap do uu tien cua node: ";
		cin>>y;
		Push(q,x,y);
	}
	SapXep(q);
	Output(q);
}

int main(){
	queue *q=new queue;
	Init(q);
	Input(q);
	return 0;
}
