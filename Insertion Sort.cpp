#include <bits/stdc++.h>
using namespace std;
 
/*1. In each iteration the i-th element is compared to atmost all the
elements befor it. the comparison takes until the i-th element is greater than or equal to it.
Therefore, in eaach iteration of the algorithm the i-th element can take any positin from 0 to i-1 
2. i-j 
3. */
void insert(int arr[], int i){
    int t=i, key=arr[i];
    for (int j=i-1;j>=0;j--)
    {
        if(key>arr[j])
            break;
        t=j;
        
    }
    while(i>t){
        arr[i]=arr[i-1];
        i--;
    }
    arr[i]=key;
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        insert(arr,i);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, N);
    printArray(arr, N);
 
    return 0;
}
