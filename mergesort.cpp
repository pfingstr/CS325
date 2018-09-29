/* Robert Pfingsten
** pfingstr@oregonstate.edu
** September 26th, 2018
** Merge Sort code largely taken from Codebind.com with only changes in main for reading and writing from the example file.
*/


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void merger(int arr[], int lo, int  mi, int hi){
    int *temp = new int[hi-lo+1];//temporary merger array
    int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
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


int main()
{
ifstream in("data.txt");

if(in.fail()) {
cout<<"Error! The file did not open"<<endl;
return 0;
}

ofstream out("merge.out");
int n;
// reading size
while(in>>n){

// creating array
int *arr = new int[n];
// reading integers

int j=0;
while(j < n) {
in>>arr[j];
j++;
}

// sorting
MergeSort(arr, n);

// writing in file
for(int i=0; i<n; i++)
out<<arr[i]<<" ";
out<<endl;
}
in.close();
out.close();
cout<<"Sorted data written to file: merge.out"<<endl;
return 0;
}
