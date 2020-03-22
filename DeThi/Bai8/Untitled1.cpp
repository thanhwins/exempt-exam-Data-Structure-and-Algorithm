//cac thao tac tren ngan xep dua vao mang
#include<iostream>
#include<fstream>
using namespace std;

#define max 100


//khai bao cau truc mot ngan xep
struct stack{
	int top;//mot bien de luu vi tri hien tai cua dinh ngan xep
	char node[100];//mot mang luu gia tri cac phan tu trong stack
};

//kiem tra tinh rong cua ngan xep
int Empty(stack *s){//s la con tro tro toi stack
	if(s->top==-1){
		return 1;
	}
	return 0;
}

//kiem tra tinh day cua ngan xep
int Full(stack *s){
	if(s->top==max-1){
		return 1;
	}
	return 0;
}

//lay phan tu o dau ngan xep
char Get(stack *s){
	char x;
	x= s->node[s->top];
	return x;
}

//lay phan tu ra khoi ngan xep
char Pop(stack *s){
	if(Empty(s)==1){
		cout<<"ngan xep rong"<<endl;
		return 0;
	}
	else{
		char x=s->node[s->top];
		s->top=s->top-1;
		return x;
	}
}

//lay kich co cua ngan xep
int KichCo(stack *s){
	return s->top;
}

//dua phan tu vao ngan xep
void Push(stack *s, char x){
	if(Full(s)==1){
		cout<<"stack day roi, khong dua them phan tu vao duoc nua"<<endl;
	}
	else{
		s->top=s->top+1;
		s->node[s->top]=x;
	}
}

char a[100]={0};
int n=0;
void docfile(){
	int i=0;
	ifstream f;
	f.open("data.txt");
	if(f==0){
		return;
	}
	else{
		while(f>>a[i]){
			cout<<a[i];
			i++;
			n++;
		}
	}
	//cout<<endl<<n;
	f.close();
}

char b[100]={0};
void docfile1(){
	int i=0;
	ifstream f1;
	f1.open("data1.txt");
	if(f1==0){
		return;
	}
	else{
		while(f1>>b[i]){
			cout<<b[i];
			i++;
		}
	}
	//cout<<endl<<n;
	f1.close();
}

//ham so sanh do uu tien
int SoSanh(char x){
	if(x=='*' || x=='/'){
		return 2;
	}
	if(x=='+' || x=='-'){
		return 1;
	}
	return 0;
}

//trung to ve hau to
void ChuyenDoi(stack *s, stack *out){
	for(int i=0;i<n;i++){
		if(a[i]=='('){
			Push(s,a[i]);
		}
		if(a[i]!='(' && a[i]!=')' && a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/'){
			Push(out,a[i]);
		}
		if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/'){
			char y=Get(s);
			if(SoSanh(a[i])>=SoSanh(y)){
				Push(s,a[i]);
			}
			if(SoSanh(a[i])<SoSanh(y)){
				y=Pop(s);
				Push(out,y);
				Push(s,a[i]);
			}
			if(Empty(s)==1){
				Push(s,a[i]);
			}
		}
		if(a[i]==')'){
			char y=Pop(s);
			while(y!='('){
				Push(out,y);
				y=Pop(s);
			}
		}
	}
	while(Empty(s)!=1){
		char y=Pop(s);
		Push(out,y);
	}
	cout<<endl<<"bieu thuc sau khi chuyen doi tu trung to sang hau to: "<<endl;
	for(int i=0;i<=out->top;i++){
		cout<<out->node[i];
	}
}

//tinh toan gia tri cua bieu thuc hau to
void TinhToan(){
	stack *t=new stack;
	t->top=1;
	int i=0;
	while(b[i]!=0){
		if(b[i]!='(' && b[i]!=')' && b[i]!='+' && b[i]!='-' && b[i]!='*' && b[i]!='/'){
			Push(t,b[i]);
		}
		if(b[i]=='+' || b[i]=='-' || b[i]=='*' || b[i]=='/'){
			int a,b;
			char y=Pop(t);
			a=(int) y;
			cout<<a<<endl;
			y=Pop(t);
			b=(int) y;
			cout<<b<<endl;
			char c;
			c=(char) (a*b);
			cout<<c<<endl;
			Push(t,c);
		}
		i++;
	}
	cout<<"ket qua cua bieu thuc hau to la: "<<Pop(t);
}

int main(){
	stack *s=new stack;
	s->top=-1;
	stack *out=new stack;
	out->top=-1;
	docfile();
	ChuyenDoi(s,out);
	docfile1();
	//y cuoi cung tinh toan bieu thuc hau to chua ra
	//TinhToan();
	return 0;
}
