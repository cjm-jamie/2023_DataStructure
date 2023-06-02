// 1. topological sort
// 2. print lexicographically smallest result
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> G;
vector<int> indegree;
vector<int> ans;

int n, m;

void topologicalSort()
{
    priority_queue<int, vector<int>, greater<int>> minh;
    for(int i=1; i<=n; i++)
    {
        if(!indegree[i])
            minh.push(i);
    }
    while (!minh.empty())
    {
        int u = minh.top(); minh.pop();
        ans.emplace_back(u);
        for(auto v:G[u]){
            indegree[v]--;
            if(!indegree[v])
                minh.push(v);
        }
    }    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    G.resize(n+1);
    indegree.assign(n+1,0);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        indegree[v]++;
    }
    topologicalSort();
    if(ans.size()==n)
    {
        for(auto &i:ans)
            cout << i << " ";
        cout << "\n" ;
    }

    else
        cout << "-1\n";

}