//duyet cay nhi phan dua vao danh sach lien ket
#include<iostream>
using namespace std;

//khoi tao mot node cho cay
struct node{
	int data;
	node *left;
	node *right;
};

struct tree{
	node *root;
};

//khoi tao cay rong
void Init(tree &t){
	t.root=NULL;
}

int Empty(tree t){//kiem tra xem cay co rong khong
	if(t.root==NULL){
		return 1;
	}
	return 0;
}

//dua gia tri vao mot node
node *get_node(int x){//x la gia tri can dua vao node
	node *p=new node;
	if(p==NULL){
		cout<<"khong du bo nho de cap phat"<<endl;
		return NULL;
	}
	p->data=x;
	p->left=p->right=NULL;
	return p;
}

//tao node goc cho cay 
void MakeRoot(tree &t, int x){
	t.root=get_node(x);
}

//tim kiem node co gia tri x
node *Find(node *p, int x){
	
	if(p->data==x){
		return p;
	}
	if(p==NULL){
		return NULL;
	}
	p=Find(p->left,x);
	if(p==NULL){
		p=Find(p->right,x);
	}
	return p;
}

//them node vao ben trai node x
void add_left(tree &t){
	int x,y;
	cout<<"nhap gia tri cua node x: ";
	cin>>x;
	node *p=t.root;
	node *q=Find(p,x);
	if(q==NULL){
		cout<<"khong ton tai gia tri cua node x"<<endl;
		return ;
	}
	else{
		cout<<"nhap gia tri cua node them vao trai node x: ";
		cin>>y;
		node *k=get_node(y);
		q->left=k;
	}
}

//them node vao ben phai node x
void add_right(tree &t){
	int x,y;
	cout<<"nhap gia tri cua node x: ";
	cin>>x;
	node *p=t.root;
	node *q=Find(p,x);
	if(q==NULL){
		cout<<"khong ton tai gia tri cua node x"<<endl;
		return ;
	}
	else{
		cout<<"nhap gia tri cua node them vao trai node x: ";
		cin>>y;
		node *k=get_node(y);
		q->right=k;
	}
}

//xoa node trai node x
void Remove_left(tree &t){
	int x;
	cout<<"nhap gia tri cho node x: ";
	cin>>x;
	node *p=t.root;
	node *q=Find(p,x);
	if(p==NULL){
		cout<<"node x khong ton tai"<<endl;
		return ;
	}
	else{
		if(p->left->left!=NULL || p->left->right!=NULL){
			cout<<"node x co nhanh cay con trai nen khong the xoa"<<endl;
			return ;
		}
		else{
			p->left=NULL;
		}
	}
}

//xoa node phai node x
void Remove_right(tree &t){
	int x;
	cout<<"nhap gia tri cho node x: ";
	cin>>x;
	node *p=t.root;
	node *q=Find(p,x);
	if(p==NULL){
		cout<<"node x khong ton tai"<<endl;
		return ;
	}
	else{
		if(p->right->left!=NULL || p->right->right!=NULL){
			cout<<"node x co nhanh cay con phai nen khong the xoa"<<endl;
			return ;
		}
		else{
			p->right=NULL;
		}
	}
}

//duyet cay theo thu tu truoc co de quy
void NLR(node *p){
	if(p!=NULL){
		cout<<p->data<<endl;
		NLR(p->left);
		NLR(p->right);
	}
}

//duyet cay theo thu tu giua co de quy
void LNR(node *p){
	if(p!=NULL){
		LNR(p->left);
		cout<<p->data<<endl;
		LNR(p->right);
	}
}

//duyet cay theo thu tu truoc co de quy
void LRN(node *p){
	if(p!=NULL){
		LRN(p->left);
		LRN(p->right);
		cout<<p->data<<endl;		
	}
}

int main(){
	tree t;
	Init(t);
	int run=1;
	while(run==1){
		int luachon;
		cout<<"chon 1: neu ban muon tao node goc cho cay"<<endl;
		cout<<"chon 2:neu ban muon them node vao ben trai node x"<<endl;
		cout<<"chon 3:neu ban muon them node vao ben phai node x"<<endl;
		cout<<"chon 4:neu ban muon loai node ben trai node x"<<endl;
		cout<<"chon 5:neu ban muon loai node ben phai node x"<<endl;
		cout<<"chon 6:neu ban muon duyet theo thu tu truoc"<<endl;
		cout<<"chon 7:neu ban muon duyet theo thu tu giua"<<endl;
		cout<<"chon 8:neu ban muon duyet theo thu tu sau"<<endl;
		cin>>luachon;
		switch(luachon){
			case 1:{
				int x;
				cout<<"nhap gia tri ban muon dua vao node goc: ";
				cin>>x;
				MakeRoot(t,x);
				break;
			}
			case 2:{
				add_left(t);
				break;
			}
			case 3:{
				add_right(t);
				break;
			}
			case 4:{
				Remove_left(t);
				break;
			}
			case 5:{
				Remove_right(t);
				break;
			}
			case 6:{
				node *p=t.root;
				NLR(p);
				break;
			}
			case 7:{
				node *p=t.root;
				LNR(p);
				break;
			}
			case 8:{
				node *p=t.root;
				LRN(p);
				break;
			}
		}
		cout<<"******************************************"<<endl;
		cout<<"chon 1: neu ban muon tiep tuc"<<endl;
		cout<<"chon 0: neu ban muon dung lai"<<endl;
		cin>>run;
	}
	return 0;
}
