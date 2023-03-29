#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

typedef struct Node Node;

void insert(Node *pre, int x)
{
    Node *nd = new Node;
    Node *ne = pre->next;

    nd->data = x;
    nd->next = ne;
    nd->prev = pre;

    ne->prev = nd;
    pre->next = nd;
}

void remove(Node *bye)
{
    Node *pre = bye->prev;
    Node *ne = bye->next;

    pre->next = ne;
    ne->prev = pre;

    delete bye;
}

Node *binarySearch(vector<Node*> &nodes, int query)
{
    int l= 1, r = nodes.size(), mid;  
    while(l<=r)
    {
        mid = (l+r)/2;
        if(nodes[mid]->data == query)
            return nodes[mid];
        else if(nodes[mid]->data > query)
            r = mid -1;
        else if(nodes[mid]->data < query)
            l = mid +1;
    }  
    return nullptr;
}

void output(Node *cur, Node *end)
{
    while (cur != end)
    {
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    
    cout << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q, x;
        string op;
        cin >> n >> q;

        /*Dummy node implementation*/
        Node *head = new Node;
        Node *tail = new Node;
        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;

        Node *cur, *target;

        vector<Node*> nodes(n+1);

        cur = head;
        for(int i=1; i<=n; i++)
        {
            insert(cur, i);
            nodes[i] = cur;
            cur = cur->next;
        }
        for(int i=0; i<q; i++)
        {
            cin >> op;
            if(op == "H")
            {
                cin >> x;
                target = binarySearch(nodes, x);
                insert(head, target->data);
                remove(target);
            }
            else if(op == "T")
            {
                cin >> x;
                target = binarySearch(nodes, x);
                insert(tail->prev, target->data);
                remove(target);
            }
        }
        output(head->next, tail);
        nodes.clear();

        /*clear the linked list after each test case*/
        Node *temp;
        cur = head;
        while (cur!=nullptr)
        {
            temp = cur->next;
            delete cur;
            cur = temp;
        }
        
    }

    return 0;
}