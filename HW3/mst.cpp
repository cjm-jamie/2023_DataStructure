#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

typedef struct{
    ll cost;
    int u, v;
} edge;

vector<int> pa;
vector<int> sizes;
vector<edge> edges;
ll ans = 0;

// 必須為 bool，記得include algorithm
// 小於為true，代表 sort function 根據 edge 的 cost 由小到大排序 edges
bool compareEdges(edge a, edge b) {
    return a.cost < b.cost;
}

int find_root(int x){
    return pa[x] == x ? x : pa[x] = find_root(pa[x]);
}

// 可以直接 pa[find_root(y)] = find_root(x); 
void onion(int x, int y){ 
    int rx = find_root(x);  int ry = find_root(y);
    if( rx == ry) // 同一棵樹
        return;
    if(sizes[rx] > sizes[ry])   swap(rx, ry); // 讓 rx 保持是小的樹
    pa[rx] = ry;
    sizes[ry] += sizes[rx]; //不管rx(小的那顆)
}

int main()
{
    int n, m;   cin >> n >> m;
    edges.resize(m); //m+1 -> m 就 AC 了，why??? 因為這個是用來記錄edges的，總共只有m個
    pa.resize(n+1); // 用 resize 要到 n+1 ，因為這個是跟 node 的值有關，node 是從 1~n
    sizes.resize(n+1);
    for(int i=0; i<n; i++){ //i<=n 
        pa[i] = i;
        sizes[i] = 1;
        // cout << i << " " << pa[i] << "\n";
    }
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    sort(edges.begin(), edges.end(), compareEdges);  //根據cost由小到大排序edges  
    for(int i=0; i<m; i++){
        // u 和 v 如果 root 相同，代表已經是同一個 set，加 edge 會多路->形成環
        if (find_root(edges[i].u) != find_root(edges[i].v))
        {
            onion(edges[i].u, edges[i].v);
            ans+=edges[i].cost;
        }
    }

    cout << ans << "\n";

    return 0;
}