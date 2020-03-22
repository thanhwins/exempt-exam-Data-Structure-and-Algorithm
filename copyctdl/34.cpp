//LeNhoa
#include<iostream>
using namespace std;
void binarySearch(int A[], int n, int x){
	int left = 0, right = n-1;
    if(left > right)	return -1;
    else{
		int mid = (left + right) / 2;	
	    if(A[mid] == x)	return mid;	
	    if(A[mid] > x)
	        return binarySearch(A, x, left, mid - 1);	
	    if(A[mid] < x)
	        return binarySearch(A, x, mid + 1, right);
    }
}

void quickSort(int a[],int x, int y){
	int i=x, j = y;
	int k = a[(x+y)/2];
	while(i<=j){
		while(a[i]<k)	i++;
        while(a[j]>k)	j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
	}
	if(x<j)	quick(a,x,j);
	if(i<y)	quick(a,i,y);
}

void merge1(int a[], int l, int m, int r){
	int x = m-l+1;
	int y = r-m-1;
	int b[x], c[y];
	for(int i=0; i<x; i++)	b[i] = a[l+i];
	for(int j=0; j<y; j++)	c[j] = a[m+1+j];
	int i=0, j=0, k=l;
	while(i<x && j<y){
		if(b[i]<=c[j]){
			a[k] = b[i];
			i+=1;
		}
		else{
			a[k] = c[j];
			j+=1;
		}
		k++;
	}
	while(i<x){
		a[k] = b[i];
		i++;
		k++;
	}
	while(j<y){
		a[k] = c[j];
		j++;
		k++;
	}
}

void merge(int a[], int x, int y){
	if(x<y){
		int k = (x+y-1)/2;
		merge(a,x,k);
		merge(a,k+1,y);
		merge1(a,x,k,y);
	}
}

main(){

}

