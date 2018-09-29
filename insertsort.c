/* Robert Pfingsten
** pfingstr@oregonstate.edu
** September 26th, 2018
*/


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

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

/* Driver program to test insertion sort */
int main()
{
ifstream in("data.txt");

if(in.fail()) {
cout<<"Error in opening file"<<endl;
return 0;
}

ofstream out("insert.out");
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
insertionSort(arr, n);

// writing in file
for(int i=0; i<n; i++)
out<<arr[i]<<" ";
out<<endl;
}

in.close();
out.close();

cout<<"sorted data written to file"<<endl;

return 0;
}
