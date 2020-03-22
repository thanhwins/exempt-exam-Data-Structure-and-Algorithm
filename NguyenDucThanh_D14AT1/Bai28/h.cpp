#include<iostream>
using namespace std;
inline void doi(int &a, int &b)
{
 int t = a; a = b; b = t;
}
void xep(int a[], int n)
{
 int left = 0, right = n - 1, k,i,j;
 while (left < right)
 {
  for (i = left; i < right; i++) if (a[i]>a[i + 1]) { doi(a[i], a[i + 1]); k = i; };
  right = k;
  for (j = right; j>left; j--) if (a[j] < a[j - 1]){ doi(a[j], a[j - 1]); k = j; }
  left = k;
 }
}
main()
{
 int a[10] = { 2, 8, 9, 5, 6, 3, 4, 7, 1, 10 };
 xep(a, 10);
 for (int i = 0; i < 10; i++) cout << " " << a[i];
}
