#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

void merge(vector<ll>&arr, int L, int R)
{
    vector<ll> buff;
    buff.clear();
    int M = (L+R) /2;
    // left array head
    int l = L;
    // right array head
    int r = M+1;
    while(l<=M && r<=R)
    {
        if(arr[l]>=arr[r])
        {
            buff.emplace_back(arr[l]);
            l++;
        }
        else{
            buff.emplace_back(arr[r]);
            r++;
        }
    }
    // in case left or right part is blank, put remain part into the buffer
    for(;l<=M;l++)
    {
        buff.emplace_back(arr[l]);
    }
    for(;r<=R;r++)
    {
        buff.emplace_back(arr[r]);
    }
    copy(buff.begin(), buff.end(), arr.begin() + L);
}

void mergeSort(vector<ll>&arr, int L, int R)
{
    if(L==R)
        return;
    int M = (L+R)/2;
    mergeSort(arr, L, M);
    mergeSort(arr, M+1, R);
    merge(arr, L, R);
}

int main(void)
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &x:arr)
        cin >> x;
    mergeSort(arr, 0, n-1);

    for(auto &x:arr)
        cout << x << " ";
}