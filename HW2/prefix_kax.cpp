#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, K;
    priority_queue<int> pq;
    cin >> N >> K;

    if(K==1){
        // print largest value
        for(int i=0; i<N; i++){
            int x;
            cin >> x;
            pq.push(x);
            int largest = pq.top();
            cout << largest << "\n";
        }
    }else{
        for(int i=0; i<K-1; i++)
        {
            int x;
            cin >> x;
            pq.push(-x);
        }
        for(int i=K; i<=N; i++)
        {
            int new_node; cin >> new_node;
            // new_node smaller than smallest num in heap
            // than pop new_node
            if(-new_node > pq.top())
                cout << new_node << "\n";
            // else pop smallest in the head, push new node in the heap
            else{
                int x=pq.top(); pq.pop();
                cout << -x << "\n";
                pq.push(-new_node);
            }
        }
    }

    return 0;
}