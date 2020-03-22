#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
void swap(int &a, int &b){
	int t = a; a= b; b = t;
}
void show(int a[], int n){
//	cin>>n;
	for(int i = 0; i < n; i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}
void a(int n){
	if(n/2 == 1) cout<<1;
	else a(n/2);
	cout<<n%2;
}
int b(int n){
	if(n / 10 == 0) return n;
	 return n%10 + b(n/10);
}
int c(int a[],int n){
	if(n == 1) return a[0];
	return a[n - 1] + c(a, n - 1);
}
void resString(char str[], int index, int size){//dao xau
    char temp = str[index];
    str[index] = str[size - index];
    str[size - index] = temp;
    if (index == size / 2)
        return;
    resString(str, index + 1, size);
}

void resSelectionSort( int a[], int i, int n){// sap xep chon de quy!
	if(i >= n - 1) return;// b1: diem dung la khi i >= n - 1;
	int index = i;//b2:tim phan tu nho nhat o lan thu i dua ve dau day
	for(int j = i + 1; j < n; j++){
		if(a[j] < a[index]){
			index = j;
		}
	}
	swap(a[i], a[index]);
	resSelectionSort(a, i + 1, n);//b3: goi lai de quy!
		
}
void resInsertionSort(int a[],int i, int n){// sap xep chen de quy!
	if(i > n - 1) return;
	int t = a[i];
	int index = i ;
	while(t < a[index - 1] && index > 0){
		a[index] = a[index - 1];
		index--;
	}
	a[index] = t;
	resInsertionSort(a, i + 1, n);
}
void sequentialSearch(int x, int a[], int i, int n){//tim kiem tuyen tinh de quy><, x la gia tri can tim, i la vi tri dau , nn la vi tri cuoi 
	if(a[i] == x) {
		cout<<"Vi tri cua "<<x<<"la : "<<i<<endl;
		return;
	}
	sequentialSearch(x, a, i + 1, n);
}
int main()
{
	int n, a[100];cin>>n;
//	a(n);
//	cout<<b(n);
	for(int i = 0; i < n; i++) cin>>a[i];
	sequentialSearch(16, a, 0, n);
//	cout<<c(a, n);
//	show(a, n);
 	return 0;
}

