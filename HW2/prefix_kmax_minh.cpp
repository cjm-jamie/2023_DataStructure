#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;   cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> minh;
    if(k==1)
    // print largest value
    {
        for(int i=0; i<n; i++){
            int x;  cin >> x;
            minh.push(-x);
            cout << -minh.top() << "\n";
        }
    }else{
        for(int i=0; i<k; i++){
            int x;
            cin >> x;
            minh.push(x);
        }
        cout << minh.top() << "\n";
        for(int i=k; i<n; i++)
        {
            int new_node;   cin >> new_node;
            if(new_node < minh.top()) // if new_node smaller than min_top(), than skip it
                cout << minh.top() << "\n";
            else{
                minh.push(new_node);
                minh.pop();
                cout << minh.top() << "\n";
            }
        }
    }
}