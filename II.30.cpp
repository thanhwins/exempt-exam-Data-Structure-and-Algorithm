#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
void lietKeNp(){
	int n, a[100], kt = 1;
	cout<<"Nhap n: ";
	cin>>n;
	for(int i = 1; i <= n; i++){
		a[i] = 0;
	}
	while(kt){
		for(int i = 1; i <= n; i++){
			cout<<a[i];
		}
		cout<<endl;
		int i = n;
		while(a[i]!= 0 && i > 0){
			a[i] = 0;
			i--;
		}
		a[i] = 1;
		if (i == 0) kt = 0;
	}
}
void lietKeHoanVi(){
	int a[100], n, kt = 1;
	cout<<"Nhap n:";
	cin>>n;
	for(int i = 1; i <= n; i++){
		a[i ]= i;
	}
	while(kt){
		for(int i = 1; i <= n; i++){
			cout<<a[i];
		}
		cout<<endl;
		int i = n - 1, j = n;
		while(i > 0 && a[i] > a[i + 1]) i--;
		if(i == 0) kt = 0;
		else{
				while(a[j] < a[i]) j--;
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			int l = i + 1, r = n;
			while( l <= r){
				int h = a[l];
				a[l] = a[r];
				a[r] = h;
				l++;
				r--;
			} 
		}
	
	}
}
void sinhToHop(){
	int a[100], n, k;
	cout<<"Nhap n va k:";
	cin>>n>>k;
	 for(int i =1 ; i <=k ; i++) {
        a[i] =1 ;
    }
     for(int i =1 ; i <=k ; i++) {
        cout<<a[i]<<" " ;
     }
     cout<<endl ;
    int j = k ;
    while(a[1]<n) {
        if(a[j]==n) {
            j-- ;
        }
        a[j]++ ;
         for(int i =1 ; i <=k ; i++) {
        	cout<<a[i]<<" " ;
     	}
     	cout<<endl ;
    }
}
void chiaSo(){
	int n, k, X[1000], dem =0;
	bool OK =1;
	cout<<"\n Nhap n="; cin>>n;
	k = 1; X[k] = n;
	while (OK ) {
		cout<<"\n Cach chia "<<++dem<<":";
		for (int i=1; i<=k; i++)
			cout<<X[i]<<" ";
	 	int i = k, j, R, S,D;
		while (i > 0 && X[i]==1 )
			 i--;
			if (i>0 ) {
				X[i] --; D = k - i + 1;
				R = D / X[i]; S = D % X[i];
				k= i;
				if (R>0) {
					for ( j = i +1; j<=i + R; j++)
					X[j] = X[i];
					k = k + R;
				}
				if (S>0 ){
					k = k +1; X[k] = S;
				}
			}
		else OK =0;
		}
	
}
void e(){
	int n,c[100], a[100], kt = 1, k;
//	cin>>n;
	cout<<"Nhap k: "; cin>>k;
	cout<<"Nhap so luong phan tu cua day: "; cin>>n;
	cout<<"Nhap day: ";
	for(int i = 1; i <= n; i++){
		cin>>c[i];
		a[i] = 0;
	}
	cout<<"Cac day con co tong bang k la: "<<endl;
	while(kt){
	//	for(int i = 1; i <= n; i++){
	//		cout<<a[i];
	//	}
	//	cout<<endl;
		int i = n, s = 0;
		while(a[i]!= 0 && i > 0){
			a[i] = 0;
			i--;
		}
		a[i] = 1;
		for(int i = 1; i <= n; i++){
			if(a[i] == 1) s += c[i];
		}
		if(s == k){
			for(int i = 1; i <= n; i++){
				if(a[i] == 1)
				cout<<c[i]<<"\t";
			}
			cout<<endl;
		}	
		if (i == 0) kt = 0;
		
	}
}
void g(){
	int kl[100], gt[100],  m, n, h = 0, f[100], a[100] = {0}, stop = 0;
	cout<<"Moi nhap lan luot so luong do vat va khoi luong toi da cua cai tui: ";
	cin>>n>>m;
	cout<<"Nhap gia tri cac do vat:\n";
	for(int i = 1; i <= n; i++) cin>>gt[i];
	cout<<"nhap khoi luong cac do vat:\n";
	for(int i = 1; i <= n; i++) cin>>kl[i];
	for(int i = 1; i <= n; i++){
		a[i] = 0;
	}
	while(!stop){
			int g = 0, w = 0;
		for(int i = 1; i <= n; i++){
			g += gt[i]*a[i];
			w += kl[i]*a[i];
		}
		if(w <= m && g > h){
			h = g;
			for(int i = 1; i <= n; i++){
				f[i] = a[i];
			}
		}
	//	hienThi();
	//	skt();
		int i = n;
		while(a[i] != 0){
			a[i] = 0; i--;
		}
		if(i == 0) stop = 1;
		else {
			a[i] = 1;
		}
	}
	cout<<"Gia tri duoc chon cho vao cai tui la: ";
		for(int i = 1; i <= n; i++){
			if(f[i] == 1)
			cout<<gt[i]<<"\t";
		}
		cout<<endl;
}
void menu(){
	cout<<"\t\t\t Bai 30: Thuat toan sinh "<<endl;
	cout<<"1.Liet ke cac xau nhi phan co do dai n"<<endl;
	cout<<"2.Liet ke cac to hop chap k cua 1..n  "<<endl;
	cout<<"3.Liet ke cac hoan vi  cua 1, 2,..n  "<<endl;
	cout<<"4.Liet ke cach chia so n thanh tong cac so tu nhien nho hon n"<<endl;
	cout<<"5.Liet ke cac day con cua day so An sao cho tong dung bang k"<<endl;
	cout<<"6.Giai bai toan cai tui"<<endl;
	cout<<"7.exit\n";
}

int main()
{
	int  chon;
	menu();
	do{
		cout<<"\n\t\t\tMoi nhap lua chon: ";cin>>chon;
		switch(chon){
			case 1: lietKeNp();break;
			case 3: lietKeHoanVi();break;
			case 2: sinhToHop();break;
			case 4: chiaSo();break;
			case 5: e();break;
			case 6: g();break;
			case 7: return 0;
		}
	}while(chon != 7);
//	lietKeNp();
//	lietKeHoanVi();
//	sinhToHop();
//	chiaSo();
//	e();
//	g();
	
}

