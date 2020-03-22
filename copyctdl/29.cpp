//LeNhoa_con cay nhi phan, cay tim kiem va ham bam -_-
//thuat toan tim kiem
#include<iostream>
using namespace std;

int tuyenTinh(int a[], int n, int x){
	for(int i=0; i<n; i++){
		if(a[i]==x)	return i;
	}
	return(-1);
}

int nhiPhan(int a[], int n, int x){
	int left = 0, right = n-1;
	int mid = (left+right)/2;
	while(left<=right){
		if(x>a[mid])	left = mid+1;
		else{
			if(x<a[mid])	right = mid-1;
			else	return(mid);
		}
	}
	return(-1);
}

int noiSuy(int a[], int n, int x){
	int left = 0, right = n-1, mid;
	while (a[right] != a[left] && x >= a[left] && x <= a[right]) {
        mid = left + ((x - a[left]) * (right - left) / (a[right] - a[left]));
        if (a[mid] < x){
        	left = mid + 1;
		}
        else if (x < a[mid])
            right = mid - 1;
        else
            return mid;
    } 

    if (x == a[left])	return left ;
    return -1;
}

int fibo(int a[], int n, int x){
	int fib[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2587};
	int i=0, vt, k=0;
	
	if(n==(-1))	return(-1);
	else{
		while(fib[k]<n)		k++;
	}
	while(k>0){
		vt = i + fib[--k];
		if(vt>=n || x<a[vt]);
		else{
			if(x>a[vt]){
				i = vt+1;
				k--; 
			}
			else	return vt;
		}
	}
	return(-1);
}


main(){
	int a[100];
	int n,x;
	cout<<"nhap so phan tu cua mang: ";
	cin>>n;
	cout<<"nhap lan luot phan tu: ";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<"nhap gia tri muon tim kiem: ";
	cin>>x;
	cout<<tuyenTinh(a,n,x);
	cout<<nhiPhan(a,n,x);
	cout<<noiSuy(a,n,x);
	cout<<fibo(a,n,x);
}


