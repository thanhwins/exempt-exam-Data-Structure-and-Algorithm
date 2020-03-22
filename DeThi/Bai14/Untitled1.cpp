//cac thao tac tren hang doi 2 diem cuoi
#include<iostream>
using namespace std;

#define max 100

struct dqueue{//khai bao cau truc mot hang doi 2 diem cuoi
	int dau;
	int cuoi;
	int node[max];
};

//khai bao hang doi rong
void Init(dqueue *d){
	d->dau=d->cuoi=-1;
}

//kiem tra tinh rong cua hang doi 2 diem cuoi
int Empty(dqueue *d){
	if((d->dau==-1 && d->cuoi==-1) || d->dau>d->cuoi){
		return 1;
	}
	return 0;
}

//kiem tra tinh day cua hang doi
int Full(dqueue *d){
	if(d->dau==0 && d->cuoi==max-1){
		return 1;
	}
	return 0;
}

//lay kich co cua hang doi 2 diem cuoi
int Size(dqueue *d){
	if(Empty(d)==1){
		cout<<"hang doi khong co phan tu nao ca"<<endl;
	}
	else{
		return (d->cuoi - d->dau + 1);
	}
}

//dua du lieu vao dau
void add_head(dqueue *d, int x){
	if(d->dau>0){
		d->dau=d->dau-1;
		d->node[d->dau]=x;
	}
}

//dua du lieu vao cuoi
void add_tail(dqueue *d, int x){
	if(d->cuoi<max-1){
		d->cuoi=d->cuoi+1;
		d->node[d->cuoi]=x;
	}
}

//lay phan tu o dau
int delete_head(dqueue *d){
	if(Empty(d)==0){
		int x=d->node[d->dau];
		d->dau=d->dau+1;
		return x;
	}
	else{
		cout<<"hang doi rong"<<endl;
	}
}

//lay phan tu o cuoi
int delete_tail(dqueue *d){
	if(Empty(d)==0){
		int x=d->node[d->cuoi];
		d->cuoi=d->cuoi-1;
		return x;
	}
	else{
		cout<<"hang doi rong"<<endl;
	}
}

//in ra cac phan tu dang co trong hang doi
void Output(dqueue *d){
	if(Empty(d)==1){
		cout<<"hang doi rong"<<endl;
	}
	else{
		if(d->dau=-1){
			d->dau=0;
		}
		cout<<"cac phan tu co trong hang doi: "<<endl;
		for(int i=d->dau;i<=d->cuoi;i++){
			cout<<"a["<<i<<"]="<<d->node[i]<<endl;
		}
	}
}

//nhap du lieu ban dau cho mang
void Input(dqueue *d){
	int n;
	cout<<"nhap so luong phan tu ban dau cho mang: ";
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cout<<"nhap gia tri cho phan tu nay: ";
		cin>>x;
		add_tail(d,x);
	}
	Output(d);
}



int main(){
	dqueue *d=new dqueue;
	Init(d);
	Input(d);
	return 0;
}
