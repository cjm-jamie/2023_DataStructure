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
            int x; cin >> x;
            pq.push(x);
            int largest = pq.top();
            cout << largest << "\n";
        }
    }else{
        // build min-heap
        for(int i=1; i<=K; i++)
        {
            int x;
            cin >> x;
            pq.push(-x);
        }
        // first round, print smallest number
        cout << -pq.top() << "\n";
        // compare with current heap, discarde smallest number, find second smallest number
        for(int i=K+1; i<=N; i++)
        {
            int new_node; cin >> new_node;
            // new_node smaller than smallest num in heap
            // than discard new_node, print pq.top
            if(-new_node > pq.top())
                cout << -pq.top() << "\n";
            // else pop smallest in the head, push new node in the heap
            else{
                pq.pop();
                pq.push(-new_node);
                int x=pq.top(); 
                cout << -x << "\n";
            }
            // cout << "This is pq's top: " << pq.top() << "\n";
        }
    }

    return 0;
}