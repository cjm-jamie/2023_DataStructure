#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// Input:  Three current indices of A, B, and C
// Return: The combined indices of the three indices
long long getCombineIndex(const long long &a, const long long &b, const long long &c) {
    return a * 10000000000LL + b * 100000LL + c;
}

// Input:  The combined indices of the three indices
// Return: Three current indices of A, B, and C, where indices[0], indices[1], and indices[2] are the index of A, B, and C, respectively.
vector<long long> parseIndex(long long combinedIndex) {
    vector<long long> indices(3);
    indices[2] = combinedIndex % 100000;  combinedIndex /= 100000;
    indices[1] = combinedIndex % 100000;  combinedIndex /= 100000;
    indices[0] = combinedIndex;
    return indices;
}

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<long long> A(x), B(y), C(z);
    set<long long>indexs;
    
    for (int i = 0; i < x; ++i) cin >> A[i];
    for (int i = 0; i < y; ++i) cin >> B[i];
    for (int i = 0; i < z; ++i) cin >> C[i];

    sort(A.begin(), A.end(), greater<long long >());
    sort(B.begin(), B.end(), greater<long long >());
    sort(C.begin(), C.end(), greater<long long>());

    priority_queue< pair<long long,long long>,vector<pair<long long,long long>>> pq;
    pq.push(make_pair(A[0]+B[0]+C[0],getCombineIndex(0,0,0)));
    indexs.insert(getCombineIndex(0,0,0));

    while (!pq.empty() && k>0)
    {
        long long current = pq.top().second;
        pq.pop();
        vector<long long>v=parseIndex(current);
        long long tmp=A[v[0]]+B[v[1]]+C[v[2]];

        // output answer
        cout << tmp << "\n";
        k--;

        // next candidates
        long long first  = getCombineIndex(v[0]+1, v[1]  , v[2]);
        long long second = getCombineIndex(v[0]  , v[1]+1, v[2]);
        long long third  = getCombineIndex(v[0]  , v[1]  , v[2]+1);

        // make sure next index exists
        if(v[0]+1<x)
        {
            // index[first] hasn't been pushed into it
            if(indexs.find(first)==indexs.end())
            {
                indexs.insert(first);
                pq.push(make_pair(A[v[0]+1]+B[v[1]]+C[v[2]],first));
            }
        }
        if(v[1]+1<y)
        {
            if(indexs.find(second)==indexs.end())
            {
                indexs.insert(second);
                pq.push(make_pair(A[v[0]]+B[v[1]+1]+C[v[2]],second));
            }
        }
        if(v[2]+1<z)
        {
            if(indexs.find(third)==indexs.end())
            {
                indexs.insert(third);
                pq.push(make_pair(A[v[0]]+B[v[1]]+C[v[2]+1],third));
            }
        }    
    }
    
    return 0;
}