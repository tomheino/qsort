#include <iostream>
#include <fstream>

using namespace std;
#define MAX 75000

// Function to perform the insertion sort
void insertion_sort(int a[], int low, int n)
  {
 
    for(int i=low+1;i<n+1;i++)
    {
      int val = a[i] ;
      int j = i ;
    while (j>low && a[j-1]>val)
      {
        a[j]= a[j-1] ;
      j-= 1;
    }
    a[j]= val ;
    }
 
  }
 

// Partition function for quicksort
int partition(int a[], int low, int high)
{
  int pivot = a[high] ;
  int i ,j;
  i = low;
  j = low;
 
  for (int i = low; i < high; i++)
     {
      if(a[i]<pivot)
      {
        int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      j += 1;
      }
    }
   
    int temp = a[j];
    a[j] = a[high];
    a[high] = temp;
 
  return j;
  }
 
 
// Function to call the partition function
// and perform quick sort on the array 
void quick_sort(int a[], int low,int high)
{
  if (low < high)
  {
    int pivot = partition(a, low, high);
    quick_sort(a, low, pivot-1) ;
    quick_sort(a, pivot + 1, high) ;
   
   
  }
}
 
// Hybrid function -> Quick + Insertion sort
void hybrid_quick_sort(int a[], int low, int high)
{
  while (low < high)
    {
 
    // If the size of the array is less
    // than threshold apply insertion sort
    // and stop recursion
    static const int M = 600;
    if (high-low + 1 < M)
      {
        insertion_sort(a, low, high);
      break;
    }
 
    else
       
        {
          int pivot = partition(a, low, high) ;
 
      // Optimised quicksort which works on
      // the smaller arrays first
 
      // If the left side of the pivot
      // is less than right, sort left part
      // and move to the right part of the array
      if (pivot-low<high-pivot)
        {
          hybrid_quick_sort(a, low, pivot - 1);
        low = pivot + 1;
      }
      else
        {
 
        // If the right side of pivot is less
        // than left, sort right side and
        // move to the left side   
        hybrid_quick_sort(a, pivot + 1, high);
        high = pivot-1;
        }
 
     }
   }
}

int main() {
int i;
int arr[MAX];
 for (int i = 0; i < MAX; i++)
    arr[i]=(rand()*rand())%1000001;
hybrid_quick_sort(arr, 0, MAX - 1); // Sort the elements of array
ofstream txtfile;
// Open .txt -file for printing
txtfile.open("print3_qsortHybrid.txt");
for (i = 0; i < MAX; i++)
    cout << arr[i] << endl;
    txtfile << arr[i] << endl;
return 0;
}