#include"bits/stdc++.h"
main()

{

int i,n,j,gap,temp,a[10];

printf("Mang co bao nhieu phan tu:=");

scanf("%d",&n);

printf("Nhap %d phan tu mang \n\n",n);

for(i=0;i<n;i++)

{

printf("Nhap a[%d]:",i);

scanf("\n%d",&a[i]);

}

for(gap=n/2;gap>0;gap=gap/2)

{

for(i=0;i<n;i=i+gap)

{

temp=a[i];

for(j=i;j>0&&a[j-gap]>temp;j=j-gap)

{

a[j]=a[j-gap];

}

a[j]=temp;

}

}

printf("Sap Xep Hoan Thanh\n");

for(i=0;i<n;i++)

printf("%d\n",a[i]);

}
