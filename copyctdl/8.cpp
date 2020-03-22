//LeNhoa_chuyen doi trung to sang hau to???
#include<iostream>
#include<string.h>
using namespace std;
struct stack{
	int top = -1;
	char inf[100];
};

int empty(stack s){
	return(s.top == (-1));
}

int full(stack s){
	return(s.top==99);
}

void push(stack &s, char x){
	s.top++;
	s.inf[s.top] = x;
}

int size(stack s){
	return s.top;
}

char pop(stack &s){
	char k = s.inf[s.top];
	s.top--;
	return k;
}

char top(stack &s){
	char k = s.inf[s.top];
	return k;
}

int show(stack s){
	cout<<"hien thi stack: ";
	while(!empty(s)){
		cout<<pop(s)<<" ";
	}
}

//void hau_to(string a){
//	stack s;
//	for(int i=0; i < a.length(); i++){
//		if(a[i] == '('){
//			push(s,a[i]);
//		}
//		else{
//			
//		}
//	}
//}

int gtHauTo(){
	string a;
	cout<<"nhap bt hau to: ";
	cin>>a;
	stack s;
	int x, y;
	for(int i=0; i < a.length(); i++){
		if( a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/' ){
			push(s,a[i]);
		}
		else{
			y = pop(s) - '0';
			x = pop(s) - '0';
			if(a[i]=='+')	x = x+y;
			if(a[i]=='-')	x = x-y;
			if(a[i]=='*')	x = x*y;
			if(a[i]=='/')	x = x/y;
			push(s,(x+'0'));
		}
	}
	x = pop(s) - '0';
	return x;
}

main(){
	stack s;
	int a=0;
	char x;
	while(a<9){
		cout<<"************\n";
		cout<<"1.kt rong\n2.kt day\n3.lay top\n4.lay size\n5.dua phan tu vao stack\n6.bo dinh stack\n7.duyet stack\n8.gia tri bt hau to\n9.thoat\nban chon: ";
		cin>>a;
		switch(a<9){
			case 1:{
				cout<<empty(s);
				break;
			}
			case 2:{
				cout<<full(s);
				break;
			}
			case 3:{
				cout<<"dinh stack: "<<top(s);
				break;
			}
			case 4:{
				cout<<"kich thuoc stack: "<<size(s);
				break;
			}
			case 5:{
				cout<<"nhap phan tu muon dua vao: ";
				cin>>x;
				push(s,x);
				break;
			}
			case 6:{
				pop(s);
				break;
			}
			case 7:{
				show(s);
				break;
			}
			case 8:{
				gtHauTo();
				break;
			}
		}
	}
//	cout<< empty(s)<<endl;
//	push(s,2);
//	push(s,7);
//	show(s);
//	cout<<gtHauTo();
}

