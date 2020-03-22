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
	for(int i=1;i<=n;i++)
	if(a[i]==x) return i;
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
