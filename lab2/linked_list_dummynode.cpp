#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node *prev;
    Node *next;
};

typedef struct Node Node;

void insert(Node *pre, int data)
{
    Node *nd = new Node;
    Node *ne = pre -> next;

    nd -> data = data; 
    nd -> prev = pre;
    nd -> next = ne;

    pre -> next = nd;
    ne -> prev = nd;
}

void remove(Node *bye)
{
    Node *pre = bye -> prev;
    Node *ne = bye -> next;

    pre -> next = ne;
    ne -> prev = pre;

    delete bye;
}

void search(Node *cur, Node *end, int data)
{
    while (cur != end)
    {
        if(cur -> data == data)
        {
            cout << "Y\n";
            return;
        }
        cur = cur -> next;
    }
    
    cout << "N\n";
    return;
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

    int n;  
    cin >> n;

    /* With dummy node, head and tail are no longer nullptr when the list is empty */
    /* The head pointer points to the dummy node, which serves as the first node in the list*/
    /* And the tail pointer points to the dummy node's next node, which is initially nullptr.*/

    Node *head = new Node;
    Node *tail = new Node;
    head -> prev = nullptr;
    head -> next = tail;
    tail -> prev = head;
    tail -> next = nullptr;

    string op;
    int x;

    while (n--)
    {
        cin >> op;
        if (op == "IH")
        {
            cin >> x;
            insert(head, x);
        }
        else if(op == "IT")
        {
            cin >> x;
            /* is tail -> prev, not tail*/
            insert(tail -> prev, x);
        }
        else if (op == "RH")
        {
            /* is head -> next, not tail*/
            if(head -> next != tail)
                remove(head -> next);
        }
        else if (op == "RT")
        {
            if(head -> next != tail)
                remove(tail -> prev);
        }
        else if (op == "S")
        {
            cin >> x;
            if(head -> next != tail)
                search(head -> next, tail, x);
            else
                cout << "E\n";
        }
        else if (op == "O")
        {
            if(head -> next != tail)
                output(head -> next, tail);
            else
                cout << "E\n";
        }        
        
    }
    
    return 0;
}