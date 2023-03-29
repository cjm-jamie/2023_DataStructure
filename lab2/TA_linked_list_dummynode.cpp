#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void insert(Node *pr, int data)
{
    Node *nd = new Node;
    Node *ne = pr->next;

    nd->data = data;
    nd->prev = pr;
    nd->next = ne;

    pr->next = nd;
    ne->prev = nd;
}

void remove(Node *bye)
{
    Node *pr = bye->prev;
    Node *ne = bye->next;

    pr->next = ne;
    ne->prev = pr;

    delete bye;
}

void search(Node *cur, Node *end, int data)
{
    while (cur != end) {
        if (cur->data == data) {
            cout << "Y\n";
            return;
        }
        cur = cur->next;
    }
    cout << "N\n";
    return;
}

void output(Node *cur, Node *end)
{
    while (cur != end) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    /* With dummy node, head and tail are no longer nullptr when the list is empty */
    /* The head pointer points to the dummy node, which serves as the first node in the list*/
    /* And the tail pointer points to the dummy node's next node, which is initially nullptr.*/

    Node *head = new Node;
    Node *tail = new Node;
    head->next = tail;
    head->prev = NULL;
    tail->next = NULL;
    tail->prev = head;

    string s;
    int i;
    while (n--) {
        cin >> s;
        if (s == "IH") {
            cin >> i;
            insert(head, i);
        } else if (s == "IT") {
            cin >> i;
            insert(tail->prev, i);
        } else if (s == "RH") {
            if (head->next != tail) remove(head->next);
        } else if (s == "RT") {
            if (head->next != tail) remove(tail->prev);
        } else if (s == "S") {
            cin >> i;
            if (head->next != tail) {
                search(head->next, tail, i);
            } else {
                cout << "E\n";
            }
        } else {
            if (head->next != tail) {
                output(head->next, tail);
            } else {
                cout << "E\n";
            }
        }
    }

    return 0;
}