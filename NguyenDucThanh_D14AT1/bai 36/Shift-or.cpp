#include <string>
#include <map>
#include <iostream>
 
using namespace std;
void bitap_search(string text, string pattern)
{
    int m = pattern.length();
    long pattern_mask[256];
    /** Cai dat mang R **/
    long R = ~1;
//    if (m == 0)
//        return -1;
//    if (m > 63)
//    {
//        cout<<"Mau tim kiem qua dai!";
//        return -1;
//    }
 

    for (int i = 0; i <= pattern.length(); ++i)
        pattern_mask[i] = ~0;
    for (int i = 0; i < m; ++i)
        pattern_mask[pattern[i]] &= ~(1L << i);
//         for (int i = 0; i < m; ++i)
//        cout << pattern_mask[i] << endl;
cout << pattern.length()*8;
//    for (int i = 0; i < text.length(); ++i)
//    {
//        R |= pattern_mask[text[i]];
//        R = R << 1;
//        //if ((R & (1L << m)) == 0)
//            //return i - m + 1;
//    }
    //return -1;
}
//void findPattern(string t, string p)
//{
//    int pos = bitap_search(t, p);
//    if (pos == -1)
//        cout << "\nKhong khop\n";
//    else
//        cout << "\nDa tim thay tai vi tri: " << pos;
//}
 
int main(int argc, char **argv)
{
 
    cout << "Thuat toan Bitap/Shift-or/Shift-and\n";
    string text;
	text="Nhap Xau Mau O Day";
    string pattern;
	pattern = "thanh";
	bitap_search(text,pattern);
//    findPattern(text, pattern);
}
