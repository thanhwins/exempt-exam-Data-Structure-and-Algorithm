#include"bits/stdc++.h"
using namespace std;
void init(int a[],int n)
{
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
}
void merge(int a[],int n)
{
	int low1,k,low2,up1,up2;
	int tmp[1000];
	int size=1;
	while(size<n)
	{
		low1=0,k=0;
		while(low1+size<n)
		{
			low2=low1+size;
			up1=low2-1;
			if(low2+size-1<n)
			{
				up2=low2+size-1;
			}
			else
			up2=n-1;
			for(int i=low1,j=low2;i<=up1 && j<=up2;k++)
			{
				if(a[i]<=a[j])
				tmp[k]=a[i++];
				else tmp[k]=a[j++];
			}
			for(int i; i<=up1;k++)
			tmp[k]=a[i++];
			for(int j; j<=up2;k++)
			tmp[k]=a[j++];
			low1=up2+1;
		}
		for(int i=low1;k<n;i++)
		tmp[k++]=a[i];
		for(int i=0;i<n;i++)
		a[i]=tmp[i];
		size=size*2;
	}
}
void in(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout << a[i] << "  ";
}
main()
{
	int a[1999],n;
	init(a,n);
	merge(a,n);
	in(a,n);
}
