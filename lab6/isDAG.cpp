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
    queue<int> Q;
    for(int i=1; i<=n; i++)
    {
        if(!indegree[i])
            Q.emplace(i);
    }
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        ans.emplace_back(u);
        for(auto v:G[u]){
            indegree[v]--;
            if(!indegree[v])
                Q.emplace(v);
        }
    }    
}

int main()
{
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
        cout << "YES\n" ;
    else
        cout << "NO\n";
}