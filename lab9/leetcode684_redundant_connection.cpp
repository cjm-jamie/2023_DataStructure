#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> sizes;

int cnt;
int max_size = 1;

int find_root(int x)
{
    return parent[x] == x ? x: parent[x] = find_root(parent[x]);
}

bool onion(int x, int y)
{
    int rx = find_root(x), ry = find_root(y);
    if(rx == ry)    return false;
    if(sizes[rx] > sizes[ry]) swap(rx, ry); //now x is the smaller tree
    parent[rx] = ry;
    sizes[ry]+=sizes[rx];
    return true;
}

int main()
{
    int n, m; cin >> n >> m;
    cnt = n;

    parent.resize(n);
    sizes.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sizes[i] = 1;
    }
    while (m--)
    {
        int u, v; cin >> u >> v;
        if(!onion(u, v))
            cout << u << " "<< v << "\n";
    }

    return 0;
}