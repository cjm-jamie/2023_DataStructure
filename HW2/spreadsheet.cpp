#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

void topological_sort(vector<vector<int>> &AL, vector<int> &indegree)
{
    queue<int> Q;
    for(int i=0; i<=n; i++)
        if(!indegree[i])
            Q.emplace(i);
    while (!Q.empty())
    {
        int v = Q.front(); Q.pop();
        for(auto u:AL[v])
        {
            indegree[u]--;
            if(!indegree[u])
                Q.emplace(u);
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> AL(n+1);
    vector<int>indegree(n+1, false);
    vector<int>value(n+1);
    while(m--)
    {
        char op; cin >> op;
        switch (op)
        {
        case 'A':
            /* code */
            break;
        case 'B':

        case 'C':

        case 'D':

        default:
            break;
        }
    }
}