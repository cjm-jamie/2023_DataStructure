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

/* don't use insert and remove here */
/* why not insert: it will change the data of same pointer in the list */
/* why not remove: it will delete the target pointer, but we want it to keep the pointer */

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

        Node *cur, *target, *pre, *ne;

        vector<Node*> v(n+1);

        cur = head;
        for(int i=1; i<=n; i++)
        {
            /* making a linked list from 1~n*/
            insert(cur, i);
            cur = cur->next;

            /* create an array to store the pointer */
            v[i] = cur;
        }
        while(q--)
        {
            cin >> op;
            if(op == "H")
            {
                cin >> x;
                /* assign target pointer */
                target = v[x];

                /* delete target pointer from the list*/
                pre = target->prev;
                ne = target->next;

                pre->next = ne;
                ne->prev = pre;

                /* insert to head*/
                pre = head;
                ne = head->next;

                target->prev = pre;
                target->next = ne;

                pre->next = target;
                ne->prev = target;
            }
            else if(op == "T")
            {
                cin >> x;
                /* assign target pointer */
                target = v[x];

                /* delete target from the list*/
                pre = target->prev;
                ne = target->next;

                pre->next = ne;
                ne->prev = pre;

                /* insert to tail*/
                pre = tail->prev;
                ne = tail;

                target->prev = pre;
                target->next = ne;

                pre->next = target;
                ne->prev = target;
            }
        }
        
        output(head->next, tail);
        v.clear();

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