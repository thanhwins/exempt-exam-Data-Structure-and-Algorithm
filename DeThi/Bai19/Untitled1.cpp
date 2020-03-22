//minh meo hieu sao cay nhi phan lai cai dat bang mang, co nghia la cay nay phai day du khong duoc thieu node nao, dinh menh
//cac thao tac tren cay nhi phan dua vao mang
#include<iostream>
using namespace std;

#define max 1000

struct tree{
	int data[max]={0};
	int maxnode;
};

int Empty(tree T){
	if(T.maxnode==-1){
		return 1;
	}
	return 0;
}

int Full(tree T){
	if(T.maxnode=max-1){
		return 1;
	}
	else{
		return 0;
	}
}

//tim gia tri cua T.maxnode
int TimKiem(tree T){
	for(int i=0;i<max;i++){
		if(T.data[i]!=0){
			T.maxnode=i;
		}
	}
	return T.maxnode;
}

//tao node goc
void TaoNodeGoc(tree &T){
	T.maxnode=0;
	int x;
	cout<<"nhap gia tri ban muon dua vao node goc: ";
	cin>>x;
	T.data[T.maxnode]=x;
}

//them node la ban trai cho node x
void ThemNodeBenTrai(tree &T){
	int x;
	cout<<"nhap gia tri cua node ma ban muon them mot node o ben trai: ";
	cin>>x;
	int i;
	int kt=0;
	for(i=0;i<=T.maxnode;i++){
		if(x==T.data[i]){
			kt=1;
			break;
		}
	}
	if(kt==1){
		if(2*i+1<max && T.data[2*i+1]==0){
			int y;
			cout<<"nhap gia tri ban muon nhap cho node ben trai node "<<i<<": ";
			cin>>y;
			T.data[2*i+1]=y;
		}
		else{
			cout<<"node ben trai ma ban muon nhap vuot qua gia tri cua mang hoac node nay da ton tai gia tri"<<endl;
		}
	}
	else{
		cout<<"khong ton tai node co gia tri x";
	}
	T.maxnode=TimKiem(T);
}

//them node la ban phai cho node x
void ThemNodeBenPhai(tree &T){
	int x;
	cout<<"nhap gia tri cua node ma ban muon them mot node o ben phai: ";
	cin>>x;
	int i;
	int kt=0;
	for(i=0;i<=T.maxnode;i++){
		if(x==T.data[i]){
			kt=1;
			break;
		}
	}
	if(kt==1){
		if(2*i+2<max && T.data[2*i+2]==0){
			int y;
			cout<<"nhap gia tri ban muon nhap cho node ben phai node "<<i<<": ";
			cin>>y;
			T.data[2*i+2]=y;
		}
		else{
			cout<<"node ben phai ma ban muon nhap vuot qua gia tri cua mang hoac node nay da ton tai gia tri"<<endl;
		}
	}
	else{
		cout<<"khong ton tai node co gia tri x";
	}
	T.maxnode=TimKiem(T);
}

void Output(tree T){
	cout<<"cac phan tu dang co trong cay: "<<endl;
	for(int i=0;i<=T.maxnode;i++){
		cout<<"phan tu thu "<<i<<": "<<T.data[i]<<endl;
	}
}

//loai node la ben trai node x
void LoaiNodeBenTrai(tree &T){
	int x;
	cout<<"nhap gia tri cua node ma ban muon loai mot node o ben trai: ";
	cin>>x;
	int i;
	int kt=0;
	for(i=0;i<=T.maxnode;i++){
		if(x==T.data[i]){
			kt=1;
			break;
		}
	}
	if(kt==1){
		if(2*i+1<max && T.data[2*i+1]==0){
			T.data[2*i+1]=0;
		}
		else{
			cout<<"node ben trai ma ban muon xoa vuot qua gia tri cua mang hoac node nay da bang 0"<<endl;
		}
	}
	else{
		cout<<"khong ton tai node co gia tri x";
	}
	T.maxnode=TimKiem(T);
}

//loai node la ben phai node x
void LoaiNodeBenPhai(tree &T){
	int x;
	cout<<"nhap gia tri cua node ma ban muon loai mot node o ben trai: ";
	cin>>x;
	int i;
	int kt=0;
	for(i=0;i<=T.maxnode;i++){
		if(x==T.data[i]){
			kt=1;
			break;
		}
	}
	if(kt==1){
		if(2*i+2<max && T.data[2*i+2]==0){
			T.data[2*i+2]=0;
		}
		else{
			cout<<"node ben trai ma ban muon xoa vuot qua gia tri cua mang hoac node nay da bang 0"<<endl;
		}
	}
	else{
		cout<<"khong ton tai node co gia tri x";
	}
	T.maxnode=TimKiem(T);
}

//duyet theo thu tu truoc bang de quy
void NLR(tree T, int i){
	if(Empty(T)==0 && T.data[i]!=0 ){
		cout<<T.data[i]<<endl;
		NLR(T,2*i+1);
		NLR(T,2*i+2);
	}
}

//duyet theo thu tu giua bang de quy
void LNR(tree T, int i){
	if(Empty(T)==0 && T.data[i]!=0 ){
		NLR(T,2*i+1);
		cout<<T.data[i]<<endl;		
		NLR(T,2*i+2);
	}
}

//duyet theo thu tu sau bang de quy
void LRN(tree T, int i){
	if(Empty(T)==0 && T.data[i]!=0 ){
		NLR(T,2*i+1);
		NLR(T,2*i+2);
		cout<<T.data[i]<<endl;
	}
}

int main(){
	tree T;
	T.maxnode=-1;
	int run=1;
	while(run==1){
		int luachon;
		cout<<"chon 1: neu ban muon tao node goc"<<endl;
		cout<<"chon 2: neu ban muon tao node ben phai node x"<<endl;
		cout<<"chon 3: neu ban muon tao node ben trai node x"<<endl;
		cout<<"chon 4 neu ban muon in ra"<<endl;
		cout<<"chon 5: neu ban muon xoa node la trai cua node x"<<endl;
		cout<<"chon 6: neu ban muon xoa node la phai cua node x"<<endl;
		cout<<"chon 7: neu ban muon duyet cay theo thu tu truoc bang de quy"<<endl;
		cout<<"chon 8: neu ban muon duyet cay theo thu tu giua bang de quy"<<endl;
		cout<<"chon 9: neu ban muon duyet cay theo thu tu sau bang de quy"<<endl;
		cout<<"duyet khong theo de quy dung thi e chua lam duoc"<<endl;
		cin>>luachon;
		switch(luachon){
			case 1:{
				TaoNodeGoc(T);
				cout<<"*******************************************"<<endl;
				break;
			}
			case 2:{
				ThemNodeBenPhai(T);
				cout<<"*******************************************"<<endl;
				break;
			}
			case 3:{
				ThemNodeBenTrai(T);
				cout<<"*******************************************"<<endl;
				break;
			}
			case 4:{
				Output(T);
				cout<<"*******************************************"<<endl;
				break;
			}
			case 5:{
				LoaiNodeBenTrai(T);
				cout<<"*******************************************"<<endl;
				break;
			}
			case 6:{
				LoaiNodeBenPhai(T);
				cout<<"*******************************************"<<endl;
				break;
			}
			case 7:{
				int i;
				cout<<"nhap thu tu cua node ma ban muon bat dau duyet: ";
				cin>>i;
				NLR(T,i);
				cout<<"*******************************************"<<endl;
				break;
			}
			case 8:{
				int i;
				cout<<"nhap thu tu cua node ma ban muon bat dau duyet: ";
				cin>>i;
				LNR(T,i);
				cout<<"*******************************************"<<endl;
				break;
			}
			case 9:{
				int i;
				cout<<"nhap thu tu cua node ma ban muon bat dau duyet: ";
				cin>>i;
				LRN(T,i);
				cout<<"*******************************************"<<endl;
				break;
			}
		}
		cout<<"nhap 1: neu ban muon tiep tuc"<<endl;
		cout<<"nhap 0: neu ban muon dung lai"<<endl;
		cin>>run;
	}
	//Output(T);
	return 0;
}

