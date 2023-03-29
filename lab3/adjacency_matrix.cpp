#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;    
    int u, v;

    cin >> n >> m >> q;

    vector<vector<int>> am(n+1, vector<int>(n+1,0));

    while (m--)
    {
        cin >> u >> v;
        am[u][v]++;
        am[v][u]++;
    }

    while (q--)
    {
        char op;
        cin >> op;
        int count = 0;
        if(op == 'D')
        {
            cin >> u;
            /* not count++ because '0' is also an element in an array*/
            for(auto i:am[u])
                count+=i;
            cout << count << "\n";
        }
        else if (op == 'N')
        {
            cin >> u >> v;
            if (am[u][v])
                cout << "Y" << "\n";
            else
                cout << "N" << "\n";            
        }
       
    }

    return 0;
}