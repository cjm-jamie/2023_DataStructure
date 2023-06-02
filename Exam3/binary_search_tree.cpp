#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n, x, k;
    cin >> n;
    string op;
    set<int> s;
    bool flag = true;
    
    /* 負值的s，用來找反過來的 upper, lower bound*/
    set<int> neg_s;
    
    while (n--)
    {
        cin >> op >> x;
        /* for debug */
        // cout << "for input " << op << " " << x << " , the output is ";
        vector<int> upperbound;
        switch (op[0])
        {
        case 'I':
            /* 沒有找到 s，就把 s insert 進去*/
            if(s.find(x) == s.end()){
                s.insert(x);
                neg_s.insert(-x);
            }
            cout << s.size() << "\n";
            break;
        case 'D':
            /* 有找到 s，再把 s delete 掉*/
            if(s.find(x) != s.end()){
                s.erase(x);
                neg_s.erase(-x);
            }
            cout << s.size() << "\n";
            break;
        case 'S':
            if(s.find(x) != s.end())
                cout << "YES\n";
            else
                cout << "NO\n";
            break;
        case 'L':
            /* 存在 s 的 lower bound，再print出來*/
            if(s.lower_bound(x) != s.end())
                cout << *(s.lower_bound(x)) << "\n";
            /* else print -1 instead*/
            else
                cout << "-1\n";
            break;
        case 'U':
            cin >> k;
            upperbound.resize(k);
            /* 印出 kth 大於x的數字*/
            upperbound[0] = x;
            for(int i=0; i<k; i++){
                if(s.upper_bound(upperbound[i]) != s.end()){
                    upperbound[i+1] = *(s.upper_bound(upperbound[i]));
                }
                else
                    flag = false;
            }
            if(flag)
                cout << *(s.upper_bound(upperbound[k-1])) << "\n";
            else
                cout << "-1\n";
            break;
        /* Print the second smallest element greater than x in the set. */
        /* 也就是找兩次 'upper' bound (因為'greater') */        
        case 'V':
            /* 找到一次 upper bound */
            if(s.upper_bound(x) != s.end()){
                int first_upper = *(s.upper_bound(x));
                /* 找到第二次 upper bound */
                if(s.upper_bound(first_upper) != s.end())
                    cout << *(s.upper_bound(first_upper)) << "\n";
                else
                    cout << "-1\n";
            }
            else
                cout << "-1\n";
            break;
        /* 'third' smallest element 'greater' than x*/
        case 'W':
            /* 找到一次 upper bound */
            if(s.upper_bound(x) != s.end()){
                int first_upper = *(s.upper_bound(x));
                /* 找到第二次 upper bound */
                if(s.upper_bound(first_upper) != s.end()){
                    int second_upper = *(s.upper_bound(first_upper));
                    /* 找到第三次 upper bound */
                    if(s.upper_bound(second_upper) != s.end())
                        cout << *(s.upper_bound(second_upper)) << "\n";
                    else
                        cout << "-1\n";
                }
                else
                    cout << "-1\n";
            }
            else
                cout << "-1\n";
            break;
        /* the largest element 'smaller' than x in the set */
        /* Hint: Build a negative-value BST. Then Y x = -(U (-x)) */
        case 'Y':
            if(neg_s.upper_bound(-x) != neg_s.end())
                cout << *(neg_s.upper_bound(-x))*-1 << "\n";
            else
                cout << "-1\n";
            break;
        case 'Z':
            if(neg_s.upper_bound(-x) != neg_s.end()){
                /* first_smaller 是正值 */
                int first_smaller = *(neg_s.upper_bound(-x)) * -1;
                if(neg_s.upper_bound(-first_smaller) != neg_s.end())
                    cout << *(neg_s.upper_bound(-first_smaller))*-1 << "\n";
                else
                    cout << "-1\n";
            }
            else
                cout << "-1\n";
            break;            
        default:
            break;
        }

        flag = true;
        upperbound.clear();
    }
    return 0;
}