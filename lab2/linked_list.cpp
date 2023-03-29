#include <iostream>
#include <cstdlib>
#include <stddef.h>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

typedef struct Node Node;

Node *Head = nullptr, *Tail = nullptr ;

void insertHead(int x)
{
    Node *newnode;
    newnode = new Node;
    newnode -> data = x;

    /*insert head*/
    newnode -> next = Head;
    newnode -> prev = nullptr;
    if(Head != nullptr)
        Head -> prev = newnode;
    Head = newnode;
    if(Tail == nullptr)
        Tail = newnode;
}

void insertTail(int x)
{
    Node *newnode;
    newnode = new Node;
    newnode -> data = x;

    /*insert tail*/
    newnode -> prev = Tail;
    newnode -> next = nullptr;
    if(Tail != nullptr)
        Tail -> next = newnode;
    Tail = newnode;
    if(Head == nullptr)
        Head = newnode;
}

void removeHead()
{
    Node *tmp;
    if(Head != nullptr)
    {
        tmp = Head;
        Head = Head -> next;
        if (Head != nullptr) 
            Head -> prev = nullptr;
        if ( tmp == Tail)
            Tail = nullptr;
        delete tmp;
    }
}

void removeTail()
{
    Node *tmp;
    if(Tail != nullptr)
    {
        tmp = Tail;
        Tail = Tail -> prev;
        if (Tail != nullptr) 
            Tail -> next = nullptr;
        if ( tmp == Head)
            Head = nullptr;
        delete tmp;
    }
}

char search(int x)
{
    Node *current;
    current = Head;
    if(Head == nullptr)
        return 'E';
    else
    {
        while(current != nullptr)
        {
            if(current -> data == x )
                return 'Y';
            current = current -> next;
        }
        return 'N';
    }
}

void print()
{
    Node *current;
    if(Head == nullptr)
        cout << "E";
    else
    {
        current = Head;
        while (current != nullptr )
        {
            cout << current -> data << " ";
            current = current -> next; 
        }
    }
    
    cout << "\n" ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int lineNum;
    cin >> lineNum;

    for (int i = 0; i < lineNum; i++) {
        string op;
        cin >> op;
        if (op == "IH") {
            int x;
            cin >> x;
            insertHead(x);
        } else if (op == "IT") {
            int x;
            cin >> x;
            insertTail(x);
        } else if (op == "RH") {
            removeHead();
        } else if (op == "RT") {
            removeTail();
        } else if (op == "S") {
            int x;
            cin >> x;
            char result = search(x);
            cout << result << endl;
        } else if (op == "O") {
            print();
        }
    }

    return 0;
}