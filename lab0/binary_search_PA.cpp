#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
  
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = (l + r) / 2;
  
        if (arr[mid] == x)
            return mid;
  
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
       return binarySearch(arr, mid + 1, r, x);
    }
  
    return -1;
}
  
int main(void)
{
    int arraysize, checklistsize;
    scanf("%d %d", &arraysize, &checklistsize);
    int arr[arraysize];
    for (int i = 0; i < arraysize; i++)
    {
      cin >> arr[i];
      arr[i] *= -1;
    }
    for(int i=0; i < checklistsize; i++)
    {
      int x;
      cin >> x;
      int result = binarySearch(arr, 0, arraysize - 1, x*-1);
      (result == -1)
          ? cout << "N" << " "
          : cout << "Y " ;      
    }
    // return 0;
}