#include"bits/stdc++.h"
using namespace std;
void nhap(int a[],int &n)
{
	cout << "Nhap n=";
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> a[i];
}
int tim(int a[],int n,int x)
{
	int  left=1,right=n;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(a[mid]==x) return mid;
		if(a[mid]<x) left=mid+1;
		if(a[mid]>x) right=mid-1;
	}
	return -1;
}
main()
{
	int a[100],n,x;
	nhap(a,n);
	cout << "Nhap so can tim : ";
	cin >> x;
	cout << tim(a,n,x);
}
