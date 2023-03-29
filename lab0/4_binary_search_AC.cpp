#include <iostream>
#include <vector>

#define ll long long 

using namespace std;
  
char binarySearch(ll arr[], ll l, ll r, ll x)
{
    if (r >= l) {
        ll mid = l + (r-l) / 2;
  		// avoid (l+r) > 2^31 -1 
        if (arr[mid] == x)
            return 'Y';
  
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
       return binarySearch(arr, mid + 1, r, x);
    }
    return 'N';
}
  
int main(void)
{
    int arraysize, checklistsize;
    cin >> arraysize >> checklistsize;
    ll arr[arraysize];
    for (int i = 0; i < arraysize; i++)
    {
      cin >> arr[i];
      arr[i] *= -1;
    }
    for(int i=0; i < checklistsize; i++)
    {
      ll x;
      cin >> x;
      char result = binarySearch(arr, 0, arraysize - 1, x*-1);
      cout << result << " ";
    }
    return 0;
}