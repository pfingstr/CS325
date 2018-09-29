#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;


void merger(int arr[], int lo, int  mi, int hi){
    int *temp = new int[hi-lo+1];//temporary merger array
    int i = lo, j = mi + 1;//i is for left-hand, j is for right-hand
    int k = 0;//k is for the temporary array
    while(i <= mi && j <=hi){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    //rest elements of left-half
    while(i <= mi)
        temp[k++] = arr[i++];
    //rest elements of right-half
    while(j <= hi)
        temp[k++] = arr[j++];
    //copy the merger-ed temporary array to the original array
    for(k = 0, i = lo; i <= hi; ++i, ++k)
        arr[i] = temp[k];
    delete []temp;
}

void MergeSortHelper(int arr[], int lo, int hi){
    int mid;
    if(lo < hi){
        mid = (lo + hi) >> 1;
        MergeSortHelper(arr, lo, mid);
        MergeSortHelper(arr, mid+1, hi);
        merger(arr, lo, mid, hi);
    }
}
void MergeSort(int arr[], int arr_size){
    MergeSortHelper(arr, 0, arr_size-1);
}

/* Function to print an array
void printArray(int A[], int size)
{
int i;
for (i=0; i < size; i++)
printf("%d ", A[i]);
printf("\n");
}
*/

int main(){

   int n;
   cout << "Enter n:";
   cin >> n;
   srand(time(NULL));

   int *data;
   data = new int[n];
   //generate arrays of size n containing random integer values from 0 to 10,000
   for (int i = 0; i<n; i++){
       data[i] = rand() % 10000;
   }
   auto start = high_resolution_clock::now();
   MergeSort(data, n);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout << n << endl;


   return 0;

}
