#include <iostream>
#include <set>
// map 中的值會依照 key 做排序
// 而 key 是唯一值，並不會出現同樣的鍵值 key，否則會直接覆蓋
#include <map>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    string op;
    set<int> s; //record distinct number
    map<int, int> num_counter; //counter of each number

    /* 負值的s，用來找反過來的 upper, lower bound*/
    set<int> neg_s;

    // for(auto &i:num_counter)
    //     i.second = 0;

    while (n--)
    {
        cin >> op >> x;
        /* for debug */
        cout << "for input " << op << " " << x << " , the output is ";

        switch (op[0])
        {
        case 'I':
            /* 沒有找到 s，就把 s insert 進去*/
            if(s.find(x) == s.end()){
                s.insert(x);
                neg_s.insert(-x);
            }
            num_counter[x]++; /* 不管怎樣，只要insert，counter 一定會增加*/
            // cout << "x is " << x << " num_counter[x] is " << num_counter[x] << " s.size is " << s.size() << "\n";
            cout << s.size() << "\n";
            break;
        case 'D':
            /* 有找到 x，先確認他是不是最後一個 x*/
            if(s.find(x) != s.end())
            {
                num_counter[x]--;
                if(!num_counter[x]){  // 確認他是不是最後一個 x
                    s.erase(x);  // 是的話就把 x 從整個 set 中移除掉
                    neg_s.erase(-x);
                }
            }
            cout << s.size() << "\n";
            break;
        case 'C':
            if(s.find(x) == s.end()) // x is not in the set
                cout << "0\n";
            else
                cout << num_counter[x] << "\n";
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
    }
    
}