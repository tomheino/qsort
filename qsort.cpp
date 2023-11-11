/**
 * Data structures and algorythms
 * Qsort Assignment
 * Author: Tommi Heino
*/

#include <iostream>
#include <fstream>

#define MAX 75000
using namespace std;

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

int main() {
int i;
int arr[MAX];
 for (int i = 0; i < MAX; i++)
    arr[i]=(rand()*rand())%1000001;


quicksort(arr, 0, MAX - 1); // Sort the elements of array


for (i = 0; i < MAX; i++)
    cout << arr[i] << endl;
ofstream txtfile;
// Open .txt -file for printing
txtfile.open("print_qsort.txt");
for (i = 0; i < MAX; i++)
    txtfile << arr[i] << endl;
return 0;
}