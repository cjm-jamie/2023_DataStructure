#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> sizes;

int cnt; // 紀錄環的數量
int max_size = 1; //紀錄最大環的node數

/* 如果pa是自己，表示自己是root */
/* 不然就往上找，順便做 path compression */
int find_root(int x){
    return parent[x] == x ? x: parent[x] = find_root(parent[x]);
}

void onion(int x, int y)
{
    int rx = find_root(x), ry = find_root(y);
    if(rx == ry)    return; // 原本就是同一個 parent ，連接的話會形成環
    if(sizes[rx] > sizes[ry]) swap(rx, ry); //now x is the smaller tree
    parent[rx] = ry;
    sizes[ry]+=sizes[rx];
    max_size = max(sizes[ry], max_size);
    cnt--; //形成一個connected component，所以要-1
}

int main()
{
    int n, m; cin >> n >> m;
    cnt = n; // 剛開始每個node都是獨立的

    /* node 從1~n，所以要開n+1比較合理 */
    parent.resize(n+1);
    sizes.resize(n+1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        sizes[i] = 1;
    }
    while (m--)
    {
        int u, v; cin >> u >> v;
        onion(u, v);
        cout << cnt << " "<< max_size << "\n";
    }

    return 0;
}