#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int q, op;
    cin >> q;

    priority_queue<int> pq;

    while (q--)
    {
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            pq.push(-x);
            // cout << "after push, the pq become " << "\n";
        }
        else if(op ==2){
            int pop;
            if(!pq.empty())
                pq.pop();
            // cout << "after pop, the pq become " << "\n";
        }else if(op == 3){
            if(!pq.empty())
                cout << -pq.top() << "\n";
            else
                cout << "EMPTY\n";
        }
    }
    
}