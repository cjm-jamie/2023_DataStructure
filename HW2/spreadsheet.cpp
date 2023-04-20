#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

void topological_sort(vector<vector<int>> &AL, vector<int> &indegree, vector<int> &value)
{
    queue<int> Q;
    for(int i=1; i<=n; i++)
        if(!indegree[i])
            Q.emplace(i);
    while (!Q.empty())
    {
        int v = Q.front(); Q.pop();
        for(auto u:AL[v])
        {
            indegree[u]--;
            value[u]+=value[v];
            if(!indegree[u])
                Q.emplace(u);
        }
    }
    // if indegree!=0 means it won't put into queue, thus it's #REF!
    for(int i=1; i<=n; i++)
        if(indegree[i]!=0)
            value[i] = -1; //#REF!
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> AL(n+1);
    vector<int>indegree(n+1, 0);
    vector<int>value(n+1, 0);

    while(m--)
    {
        char op; cin >> op;
        switch (op)
        {
        int x1, x2, x3, x4, y;
        case 'A':
            cin >> x1 >> y;
            value[x1] = y;
            break;
        case 'B':
            cin >> x1 >> x2 >> y;
            AL[x2].emplace_back(x1);
            value[x1] = y;
            indegree[x1]++;
            break;
        case 'C':
            cin >> x1 >> x2 >> x3 >> y;
            AL[x2].emplace_back(x1);
            AL[x3].emplace_back(x1);
            value[x1] = y;
            indegree[x1]+=2;
            break;
        case 'D':
            cin >> x1 >> x2 >> x3 >> x4 >> y;
            AL[x2].emplace_back(x1);
            AL[x3].emplace_back(x1);
            AL[x4].emplace_back(x1);
            value[x1] = y;
            indegree[x1]+=3;
            break;
        default:
            break;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << "AL " << i << " is: ";
    //     for (auto u : AL[i])
    //         cout << u << " ";
    //     cout << "\n";
        // cout << "indegree of  " << i << " is: " << indegree[i] << "\n";
        // cout << "value of  " << i << " is: " << value[i] << "\n";
    // }
    topological_sort(AL, indegree, value);
    for(int i=1; i<=n; i++) {
        if (value[i] == -1) {
            cout << "#REF!" << "\n";
        }
        else {
            cout << value[i] << "\n";
        }
    }
}