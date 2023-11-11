// Data structures and algorythms
// Qsort Assignment
// Author: Tommi Heino

#include <iostream>
#include <fstream>

#define MAX 75000
using namespace std;

void itemSwap(int &a, int &b) {
    int t = a; 
    a = b; 
    b = t;
}
void compareAndSwap(int &a, int &b) {
    if(b < a) itemSwap(a,b);
}

void insertionSort(int a[], int l, int r) {
    for(int i = l+1; i <= r; i++) {
        for(int j = i; j > l; j--) {
            compareAndSwap(a[j-1], a[j]);
        }
    }
}

int partition(int a[], int l, int r) {
    int i = l-1, j = r; int v = a[r]; // Pivot element
    while(1) {
        while(a[++i] < v);
        while(v < a[--j]) if(j == l) break;
        if(i >= j) break;
        itemSwap(a[i], a[j]);
    }
    itemSwap(a[i], a[r]);
    return i;
}

void quicksort(int a[], int l, int r) {
    int i; int v;  // current partition element
    int j;
    if (r > l) {
        v = a[r]; i = l - 1; j = r;
        for (;;) {
            while(a[++i] < v);  // * scan left to right
            while(a[--j] > v);  // * scan right to left
            if (i >= j) break;  // ** exit for-loop
            swap(a[i], a[j]);       // swap left - right
        }
        swap(a[i], a[r]);            // swap left - partition
        quicksort(a,l,i-1);     // call low part
        quicksort(a,i+1, r);    // call high part
    }
}

// Median of Three
static const int M = 0;
void quicksort2(int a[], int l, int r) {
    if (r-l < M) return;
    itemSwap(a[(l+r)/2], a[r-1]);   // Median is r-1
    // cout << a[r-1] << endl;
    compareAndSwap(a[l], a[r-1]);   // l is smaller than r-1
    compareAndSwap(a[l], a[r]);     // l is smaller than r
    compareAndSwap(a[r-1], a[r]);   // r-1 is smaller than r
    int i = partition(a, l+1, r-1);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}

int main() {
int i;
int arr[MAX];
 for (int i = 0; i < MAX; i++)
    arr[i]=(rand()*rand())%1000001;


quicksort2(arr, 0, MAX - 1); // Sort the elements of array

ofstream txtfile;
// Open .txt -file for printing
txtfile.open("print2_qsortMedianOfThree.txt");
for (i = 0; i < MAX; i++)
    txtfile << arr[i] << endl;
return 0;
}