#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i-1;

/* Move elements of arr[0..i-1], that are
greater than key, to one position ahead
of their current position */
while (j >= 0 && arr[j] > key)
{
arr[j+1] = arr[j];
j = j-1;
}
arr[j+1] = key;
}
}

int main(){

   int n;
   cout << "Enter n:";
   cin >> n;
   srand(time(NULL));

   int *data;

   data = new int[n];

   for (int i = 0; i<n; i++){
       data[i] = rand() % 1000;
   }
   auto start = high_resolution_clock::now();
   insertionSort(data,n);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
   return 0;
}
