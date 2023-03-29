#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t, n, m, q;
    int u, v;

    cin >> t;
    
    while (t--)
    {
        cin >> n >> m >> q;

        vector<vector<int>>am(n+1, vector<int>(n+1, 0));

        while (m--)
        {
            cin >> u >> v;
            am[u][v]++;
            am[v][u]++;
        }

        while (q--)
        {
            bool flag = false;
            cin >> u >> v;
            for(int i=1; i<=n; i++)
            {
                if(am[u][i] && am[i][v])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                cout << "Y" << "\n";
            else
                cout << "N" << "\n";            
        }
    }    

    return 0;
}