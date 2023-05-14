
    /*if m+1 is relaced with m, firstly it will show segmentation error,
     i.e. it wll require to access the memory location the is not permitted, 
     accessing a variable that has already been freed, 
     writing to a read-only portion of the memory, etc. 
     Doing so causes it to run into an infinite loop, since 
     the sub space will not be updated and the function will keep on recursing 
     on the same subarray, leading to stack overflow or infinite recursion.*/


#include <bits/stdc++.h>
using namespace std;
int binarySearch(int array[], int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    if (array[mid] == mid)
      return mid;

    // Search the left half
    if (array[mid] > mid)
      return binarySearch(array, low, mid-1);

    // Search the right half
    return binarySearch(array, mid+1, high);
  }

  return -1;
}
int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid-1);

    // Search the right half
    return binarySearch(array, x, mid+1, high);
   /*if mid+1 and mid-1 are replaced by mid, the algorithm will work just fine
   giving us the desired output, however for the element at rhe last index it will throw a segmentation error.
   Because the search space is not correctly updated and the algorithm runs into an infinite loop.*/
  }

  return -1;
}

// Function to get pivot. For array 3, 4, 5, 6, 1, 2
// it returns 3 (index of 6)
int findPivot(int arr[], int low, int high)
{
    if (high < low)
        return -1;
    if (high == low)
        return low;

    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
 
    return findPivot(arr, mid + 1, high);
}
 
// Searches an element key in a pivoted
// sorted array arr[] of size n
int pivotedBinarySearch(int arr[], int n, int key)
{
    
    int t=findPivot(arr,0,n-1);
    // If we didn't find a pivot,
    // then array is not rotated at all
    if (t == -1)
        return binarySearch(arr, 0, n - 1, key);
 
    // If we found a pivot, then first compare with pivot
    // and then search in two subarrays around pivot
    if (arr[t] == key)
        return t;
 
    if (arr[0] <= key)
        return binarySearch(arr, 0, t - 1, key);
 
    return binarySearch(arr, t + 1, n - 1, key);
}




int main() {
    
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int x = 4;
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  cout<<"\n Normal Binary Search";
  if (result == -1)
    cout<<"Not found";
  else
    cout<<"Element is found at index"<<result;

  cout<<"\n Pivoted Binary Search \n";
  int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k = 10;
    cout << "Index of the element is : "
         << pivotedBinarySearch(arr1, n1, k);
    
    
    cout<<"\n Binary Search for array[i] == i \n";
    cout<<"such index is "<< binarySearch(array,0,n-1);
 
}