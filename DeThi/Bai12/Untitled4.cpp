//cac thao tac tren hang doi vong dua vao mang
#include<iostream>
using namespace std;

#define max 100

//khai bao cau truc mot hang doi
struct queue{
	int front;
	int rear;
	int node[max];
};

//khai bao hang doi rong
void Init(queue *q){
	q->front=q->rear=-1;
}

//dua phan tu vao trong hang doi vong
void Push(queue *q, int x){
	if((q->front==0 && q->rear==max-1) || (q->front==q->rear+1)){
		cout<<"tran hang doi"<<endl;
		return;
	}
	if(q->front==-1){
		q->front=0;
		q->rear=0;
	}
	else{
		if(q->rear==max-1){
			q->rear=0;
		}
		else{
			q->rear=q->rear+1;
		}
	}
	q->node[q->rear]=x;
}

//lay phan tu khoi hang doi vong
int Pop(queue *q){
	if(q->front==-1){
		cout<<"hang doi rong"<<endl;
		return 0 ;
	}
	int x=q->node[q->front];
	if(q->front==q->rear){
		q->front=-1;
		q->rear=-1;
	}
	else{
		if(q->front==max-1){
			q->front=0;
		}
		else{
			q->front=q->front+1;
		}
	}
	return x;
}

void Output(queue *q){
	int i=0;
	//i=i+1;
	cout<<"cac phan tu co mat trong hang doi: "<<endl;
	while(i<=q->rear){
		cout<<q->node[i]<<endl;
		i++;
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
		Push(q,x);
	}
	Output(q);
}



int main(){
	queue *q=new queue;
	Init(q);
	Input(q);
	return 0;
}
