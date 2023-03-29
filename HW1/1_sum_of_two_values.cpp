#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define ll long long

using namespace std;

int binary_search(vector<ll> &a, int n, ll val) {

    int l=1, r=n, mid;

    while(l <= r) 
    {
        mid=(l+r)/2;
        cout << "l is " << l << ", " << "r is " << r << ", " << "mid is " << mid << "\n";
        if(a[mid] == val)
            return mid;
        else if(a[mid] > val)
            r=mid-1;
        else if(a[mid] < val)
            l=mid+1;
    }

    return -1;
}

int main()
{
    int n, sum;
    ll sub, second_index;
    bool flag = false;

    cin >> n >> sum;

    vector<ll> a(n+1), index(n+1);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        cin >> index[i];
        cout << a[i] << " ";
    }
    cout << "\n";

    sort(a.begin(), a.end());
    for(int i=1; i<=n; i++)
        cout << a[i] << " ";
    cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        sub = sum - a[i];
        cout << "sub is " << sub << "\n";
        second_index = binary_search(a, n, sub);
        cout << "second_index is " << second_index << "\n";
        if(second_index != -1)
        {
            cout << i << " "<< second_index << "\n";
            flag = true;
            break;
        }
    }

    if(!flag)
        cout << "IMPOSSIBLE\n";

    return 0;
}