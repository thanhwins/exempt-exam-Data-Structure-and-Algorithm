#include"bits/stdc++.h"
using namespace std;
main()
{
	int n,a[100];
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=1;i<n;i++)
	for(int j=i;j>=1;j--)
	{
		if(a[j-1]>a[j]) swap(a[j-1],a[j]);
	}
	for(int i=0;i<n;i++) cout << a[i] << "   ";
}
