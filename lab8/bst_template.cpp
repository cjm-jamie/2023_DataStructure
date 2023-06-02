#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    string op;
    set<int> s;
    while (n--)
    {
        cin >> op >> x;
        switch (op[0])
        {
        case 'I':
            /* "=" means doesn't find x in the set*/
            /* then insert x to s */
            if(s.find(x) == s.end())
                s.insert(x);
            cout << s.size() << "\n";
            break;
        case 'D':
            /* find x in s*/
            /* then delete x in s */
            if(s.find(x) != s.end())
                s.erase(x);
            cout << s.size() << "\n";
            break;
        case 'S':
            if(s.find(x) != s.end())
                cout << "YES\n";
            else
                cout << "NO\n";
            break;
        case 'L':
            /* insure that lowerbound is in set s */
            /* then print lower bound*/
            if(s.lower_bound(x) != s.end())
                cout << *(s.lower_bound(x)) << "\n";
            /* else print -1 instead*/
            else
                cout << "-1\n";
            break;
        case 'U':
            if(s.upper_bound(x) != s.end())
                cout << *(s.upper_bound(x)) << "\n";
            else
                cout << "-1\n";
            break;        
        default:
            break;
        }
    }
    
}