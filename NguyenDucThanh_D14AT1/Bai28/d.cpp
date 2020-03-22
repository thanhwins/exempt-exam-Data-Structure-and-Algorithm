#include"bits/stdc++.h"
using namespace std;
void qs(int a[],int left,int right)
{
	int i=left,j=right;
	int mid=a[(left+right)/2];
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(left<j) qs(a,left,j);
	if(right>i) qs(a,i,right);
}
main()
{
	int n,a[100];
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	qs(a,0,n-1);
	for(int i=0;i<n;i++) cout << a[i] << "   ";
}
