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

    vector<vector<int>> al(n+1, vector<int>());

    while (m--)
    {
        cin >> u >> v;
        al[u].emplace_back(v);
        al[v].emplace_back(u);
    }

    while (q--)
    {
        char op;
        cin >> op;
        int count = 0;
        if(op == 'D')
        {
            cin >> u;
            /* to count how mant elaement are there in the array */
            for(auto i:al[u])
                count++;
            cout << count << "\n";
        }
        else if (op == 'N')
        {
            bool flag = false;
            cin >> u >> v;
            for(auto i:al[u])
            {
                if (i == v)
                 flag = true;
                break;
            }
            if (flag)
                cout << "Y" << "\n";
            else
                cout << "N" << "\n";            
        }       
    }
    return 0;
}