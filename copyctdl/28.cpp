//LeNhoa_con ham radixsort -_-
// cac thuat toan sap xep
#include<iostream>
#include<algorithm>
using namespace std;

void selection(int a[], int n){
	int min;
	for(int i =0; i< n-1 ; i++){
		min = i;
		for(int j = i+1; j<n; j++){
			if(a[j]<a[min]){
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

void bubble(int a[], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			if(a[j] > a[j+1]){
				swap(a[j] , a[j+1]);
			}
		}
	}
}

void insertion(int a[], int n){
	for(int i=1; i<n; i++){
		int k = a[i];
		int j = i-1;
		while(j>=0 && a[j]>k){
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = k;
	}	
}

void quick(int a[],int x, int y){
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

void show(int a[], int n){
	cout<<"mang: ";
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void merge1(int a[], int l, int m, int r){
	int x = m-l+1;
	int y = r-m-1;
	int b[x], c[y];
	for(int i=0; i<x; i++)	b[i] = a[l+i];
	for(int j=0; j<y; j++)	c[j] = a[m+1+j];
//	show(b,x);
//	show(c,y);
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

void radix(int a[], int n){
	
}

void shellsort(int array[], int n){
	int i, j, a, temp;
	for(a = n/2;a > 0; a /= 2){
        for(i = a; i<n; i++){
            temp = array[i];
            for(j = i; j >= a ;j-=a){
                if(temp < array[j-a]){
                    array[j] = array[j-a];
                }
                else{
                    break;
                }
            }
            array[j] = temp;
        }
    }
}

void shaker(int a[], int n){
	int j;
    int left = 0, right = n-1, k = 0;
    while (left < right){
    	for (j = left; j < right; j++){ 
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                k = j;
            }
        }
        right = k;
        for (j = right; j > left; j--){
            if (a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                k = j;
            }
        }
        left = k;
    }
}

//void show(int a[], int n){
//	cout<<"mang: ";
//	for(int i=0; i<n; i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//}

main(){
	int a[100];
	int n;
	cout<<"nhap so phan tu cua mang: ";
	cin>>n;
	cout<<"nhap lan luot phan tu: ";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	show(a,n);
//	selection(a,n);
//	bubble(a,n);
//	quick(a,0,n);
//	insertion(a,n);
//	merge(a,0,n);
//	shaker(a,n);
	shellsort(a,n);
	show(a,n);
}

