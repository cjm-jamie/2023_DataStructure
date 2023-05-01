#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int largest_index, max_cookies;

pair<int, int> find_most_cookie(vector<vector<int>> &AL, vector<bool> &visited, int startpoint, vector<int> &cookies)
{
    int this_run_largest_index = -1;
    queue<int> Q;
    Q.push(startpoint);
    while (!Q.empty())
    {
        // record the current vertex and cur_index is for later update(update max_index) 
        int vertex = Q.front();
        Q.pop();
        if(visited[vertex])
            continue;
        visited[vertex] = true;
        // record largest index
        this_run_largest_index = max(this_run_largest_index, vertex);
        // Q.front().second = largest_index;
        if(find(cookies.begin(), cookies.end(), vertex) != cookies.end())
            max_cookies++;
        for(auto i:AL[vertex])
            if(!visited[i])
                Q.push(i);
    }
    return {max_cookies, this_run_largest_index};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;  cin >> t;
    while (t--)
    {
        largest_index = -1;
        max_cookies = 0;
        int n, m;   cin >> n >> m;
        vector<vector<int>> AL(n+1);
        vector<bool> visited(n+1);
        // contstruct graph
        for(int i=0; i<m; i++)
        {
            int v, u;   cin >> v >> u;
            AL[v].push_back(u);
            AL[u].push_back(v);
        }
        int num_of_cookies; cin >> num_of_cookies;
        vector<int> cookies(num_of_cookies);
        for(auto &i:cookies)
            cin >> i;
        for(int i=1; i<=n; i++)
            if(!visited[i])
            {
                pair<int, int> result = find_most_cookie(AL, visited, i, cookies);
                int cur_cookies = result.first;
                int cur_largest_index = result.second;
                
                // if this run find more cookies then update largest index
                if (max_cookies <= cur_cookies)
                    largest_index = cur_largest_index;
                // update max cookies
                max_cookies = cur_cookies;
            }
        cout << largest_index << " " << max_cookies << "\n";
    }
    return 0;
}