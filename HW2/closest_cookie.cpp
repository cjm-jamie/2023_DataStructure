#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int find_closest_cookie(vector<vector<int>> &AL,int startpoint, vector<int> &cookie, vector<bool> &visited)
{
    queue<pair<int, int>> Q;
    Q.push({startpoint, 0});
    while (!Q.empty())
    {
        int vertex = Q.front().first;
        int distance = Q.front().second;
        Q.pop();
        if (visited[vertex])
            continue;
        visited[vertex] = true;
        if(find(cookie.begin(), cookie.end(), vertex) != cookie.end()){ // which means there's cookie on the vertex
            return distance;
        }
        for(auto i:AL[vertex])
            if(!visited[i]) Q.push({i, distance+1});
    }    
    return -1;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > AL(V+1);
        vector<bool> visited(V+1, false);
        while (E--)
        {
            int v, u;
            cin >> v >> u;
            AL[v].push_back(u);
            AL[u].push_back(v);
        }
        int start_point; cin >> start_point;
        int num_cookie; cin >> num_cookie;
        vector<int> cookie(num_cookie);
        for(auto &x:cookie) cin >> x;
        
        int result = find_closest_cookie(AL, start_point, cookie, visited);
        if(result == -1)
            cout << "SAD\n";
        else
            cout << result << "\n";
    }
    
}