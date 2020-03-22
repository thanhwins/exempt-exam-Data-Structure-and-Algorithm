#include"bits/stdc++.h"
using namespace std;
main()
{
	int n,a[100];
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		if(a[i]>a[j]) swap(a[i],a[j]);
	}
	for(int i=1;i<=n;i++) cout << a[i] << "   ";
}
