#include<iostream>
#include<vector>
using namespace std;
#define ll long long 

int binary_search(vector<ll> &a, int n, ll val) {
    int l=0,r=n-1,mid;
    while(l <= r) {
        mid=(l+r)/2;
        if(a[mid] == val) return mid;
        else if(a[mid] > val) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int main() {
    int n,m;cin>>n>>m;
    vector<ll> num(n);
    for(auto &x:num) cin>>x;
    ll q;
    while(m--) {
        cin>>q;
        if(binary_search(num,n,q)>=0) cout<<"Y ";
        else cout<<"N ";
    }
}