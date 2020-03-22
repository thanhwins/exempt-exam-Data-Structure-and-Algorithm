//bai toan ngan xep su dung danh sach lien ket don
#include<iostream>
#include<fstream>
using namespace std;

//khoi tao mot ngan xep
struct node{
	char data;
	node *next;
};

struct stack{
	node *top;
};

void Init(stack &s){
	s.top=NULL;
}

node *get_node(char x){
	node *p=new node;
	if(p==NULL){
		cout<<"khong du bo nho de cap phat"<<endl;
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}

//kiem tra tinh rong cua ngan xep
int Empty(stack s){
	if(s.top==NULL){
		return 1;
	}
	return 0;
}

//lay phan tu o dau ngan xep
node *Get(stack s){
	if(Empty(s)==1){
		node *x=new node;
		x->data='0';
		return x;
	}
	else{
		node *x=new node;
		x=s.top;
		return x;
	}
}

//lay kich co cua ngan xep
int KTKichCo(stack &s){
	int i=0;
	node *p=s.top;
	while(p!=NULL){
		i++;
		p=p->next;
	}
	return i;
}

//dua phan tu vao dau ngan xep
void Push(stack &s, node *p){
	if(s.top==NULL){
		s.top=p;
	}
	else{
		p->next=s.top;
		s.top=p;
	}
}

//lay phan tu ra khoi ngan xep
node *Pop(stack &s){
	if(Empty(s)==1){
		return NULL;
	}
	else{
		node *p=s.top;
		s.top=s.top->next;
		return p;
	}
}

/*void Input(stack &s){
	int n;
	cout<<"nhap so luong node muon nhap: "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		char x;
		cout<<"nhap gia tri ban muon nhap cho node: "<<endl;
		cin>>x;
		node *p=get_node(x);
		Push(s,p);
	}
}*/

void Output(stack s){
	node *p=s.top;
	cout<<"cac phan tu dang co mat trong ngan xep la: "<<endl;
	while(p!=NULL){
		cout<<p->data<<"   ";
		p=p->next;
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
			cout<<"a["<<i<<"]="<<a[i]<<endl;
			i++;
			n++;
		}
	}
	cout<<endl<<n;
	f.close();
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
void ChuyenDoi(stack &s){
	stack out;
	Init(out);
	for(int i=0;i<n;i++){
		if(a[i]=='('){
			node *p=get_node(a[i]);
			Push(s,p);
		}
		if(a[i]!='(' && a[i]!=')' && a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/'){
			node *p=get_node(a[i]);
			Push(out,p);
		}
		if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/'){
			node *y=Get(s);
			if(SoSanh(a[i])>=SoSanh(y->data)){
				node *p=get_node(a[i]);
				Push(s,p);
			}
			if(SoSanh(a[i])<SoSanh(y->data)){
				y=Pop(s);
				Push(out,y);
				node *p=get_node(a[i]);
				Push(s,p);
			}
			if(Empty(s)==1){
				node *p=get_node(a[i]);
				Push(s,p);
			}
		}
		if(a[i]==')'){
			node *y=Pop(s);
			while(y->data!='('){
				Push(out,y);
				y=Pop(s);
			}
		}
	}
	while(Empty(s)!=1){
		node *y=Pop(s);
		Push(out,y);
	}
	stack h;
	Init(h);
	node *p=Pop(out);
	while(p!=NULL){
		node *v=get_node(p->data);
		Push(h,v);
		p=p->next;
	}
	Output(h);
}

//tinh toan gia tri bieu thuc hau to

int main(){
	stack s;
	Init(s);
	//Input(s);
	//Output(s);
	docfile();
	ChuyenDoi(s);
	return 0;
}
