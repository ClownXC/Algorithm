#include <iostream>

//----------------------------
template<typename T>
void insertion_sort(T a[], int n)
{
    T tm;
    for (int i=0; i!=n; ++i)
    {
        tm = a[i];
        int k=i;
        for (; k>0; --k)
        {
            if (tm >= a[k-1])
                break;
            a[k] = a[k-1];
        }
        a[k] = tm;
    }
}

//---------------------------

template<typename T>
T median(T a[], int left, int right)
{
     int center = (left + right) / 2;
     T tm;
     if (a[left] > a[center]) {
         tm = a[left];
         a[left] = a[center];
         a[center] = tm;
      }
     if (a[left] > a[right]) {
13         tm = a[left];
14         a[left] = a[right];
15         a[right] = tm;
16     }
17     if (a[center] > a[right]) {
18         tm = a[center];
19         a[center] = a[right];
20         a[right] = tm;
21     }
22
23     tm = a[center];
24     a[center] = a[right-1];
25     a[right-1] = tm;
26
27     return a[right-1];
28 }
29
30 template<typename T>
31 void q_sort(T a[], int left, int right)
32 {
33     // 如果剩余未排序的数组长度太小，使用插入排序算法进行剩余数组的排序
34     if (left+4 <= right) {
35         T pivot = median(a,left,right);
36         int i = left;
37         int j = right - 1;
38         while (true) {
39             while (a[++i] < a[pivot]);
40             while (a[--j] > a[pivot]);
41             if (i < j) {
42                 T tm = a[i];
43                 a[i] = a[j];
44                 a[j] = tm;
45             }
46             else
47                 break;
48         }//while
49         T tm = a[i];
50         a[i] = a[right-1];
51         a[right-1] = tm;
52
53         q_sort(a,left,i-1);
54         q_sort(a,i+1,right);
55     }
56     else
57         insertion_sort(a+left,right-left+1);
58 }
59
60 template<typename T>
61 void quicksort(T a[], int n)
62 {
63     q_sort(a,0,n-1);
64 }
65 //--------------------------------------------------


int main(int argc, const char * argv[])
{


    return 0;

}