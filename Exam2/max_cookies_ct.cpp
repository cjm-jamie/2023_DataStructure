#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INT_MIN 1e-9

using namespace std;

int largest_index, max_cookies;

/* why no AC*/
// shouldn't use name the same as global variable in local funcion
// or it'll not update parameter in every run
pair<int, int> find_most_cookie(vector<vector<int>> &AL, vector<bool> &visited, int startpoint, vector<int> &cookies)
{
    // int largest_index = INT_MIN;
    queue<pair<int, int>> Q;
    // record the current location and distance 
    Q.push({startpoint, startpoint});
    while (!Q.empty())
    {
        int vertex = Q.front().first;
        int index = Q.front().second;
        Q.pop();
        if(visited[vertex])
            continue;
        visited[vertex] = true;
        // record largest index
        largest_index = max(largest_index, index);
        // Q.front().second = largest_index;
        if(find(cookies.begin(), cookies.end(), vertex) != cookies.end())
            max_cookies++;
        for(auto i:AL[vertex])
            if(!visited[i])
                Q.push({i, i});
    }
    return {max_cookies, largest_index};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;  cin >> t;
    while (t--)
    {
        largest_index = INT_MIN;
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
                // if find more cookies, update largest index
                if (max_cookies <= find_most_cookie(AL, visited, i, cookies).first)
                    largest_index = find_most_cookie(AL, visited, i, cookies).second;
                cout << "largest_index is " << largest_index << "\n";
                // update max cookies
                max_cookies = max(max_cookies, find_most_cookie(AL, visited, i, cookies).first);
                cout << "max_cookies is " << max_cookies << "\n";
            }
        cout << largest_index << " " << max_cookies << "\n";
    }
    return 0;
}