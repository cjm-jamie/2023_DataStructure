#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

// Nodes

struct Node {
    int data;
    Node *nxt, *prv;
};

// (pre) (x) (nxt)
Node* ins_after(Node *pre, int x) {
    Node *nd = new Node, *nex = pre->nxt;
    nd->data = x;
    nd->prv = pre, nd->nxt = nex;
    pre->nxt = nd;
    /* the following one might be nullptr, which can't be dereferenced*/
    if (nex) nex->prv = nd;

    return nd;
}

// (pre) (x) (nxt)
Node* ins_before(Node *nex, int x) {
    Node *nd = new Node, *pre = nex->prv;
    nd->data = x;
    nd->prv = pre, nd->nxt = nex;
    nex->prv = nd;
    /* the previous one might be nullptr, which can't be dereferenced*/
    if (pre) pre->nxt = nd;

    return nd;
}

void del(Node *bye) {
    Node *pre = bye->prv, *nex = bye->nxt;
    if (pre) pre->nxt = nex;
    if (nex) nex->prv = pre;
    delete bye;
}

// List
using NodePtr = Node*;

bool is_empty_list(NodePtr head) {
    return head == nullptr;
}

void ins_head(NodePtr &head, NodePtr &tail, int data) {
    if (is_empty_list(head)) {
        NodePtr nd = new Node;
        nd->data = data, nd->prv = nd->nxt = nullptr;
        head = tail = nd;
    } else {
        NodePtr nd = ins_before(head, data);
        head = nd;
    }
}

void ins_tail(NodePtr &head, NodePtr &tail, int data) {
    if (is_empty_list(head)) {
        NodePtr nd = new Node;
        nd->data = data, nd->prv = nd->nxt = nullptr;
        head = tail = nd;
    } else {
        NodePtr nd = ins_after(tail, data);
        tail = nd;
    }
}

void rm_head(NodePtr &head, NodePtr &tail) {
    if (is_empty_list(head)) return;

    /* only one element in the list*/
    else if (head == tail) {
        del(head);
        head = tail = nullptr;
    } else {
        Node *bye = head;
        head = head->nxt;
        del(bye);
    }
}

void rm_tail(NodePtr &head, NodePtr &tail) {
    if (is_empty_list(head)) return;

    /* only one element in the list*/
    else if (head == tail) {
        del(head);
        head = tail = nullptr;
    } else {
        Node *bye = tail;
        tail = tail->prv;
        del(bye);
    }
}

char search(NodePtr head, NodePtr tail, int data) {
    if (is_empty_list(head)) return 'E';
    char ans = 'N';
    for (NodePtr ptr = head; ptr != nullptr; ptr = ptr->nxt) {
        if (ptr->data == data) ans = 'Y';
    }
    return ans;
}

void output(NodePtr head, NodePtr tail) {
    if (is_empty_list(head)) {
        cout << "E\n"; return;
    }
    for (NodePtr ptr = head; ptr != nullptr; ptr = ptr->nxt) {
        cout << ptr->data << " ";
    }
    cout << "\n";
}


// main

int main() {
    int q; cin >> q;
    Node *head = nullptr, *tail = nullptr;
    while (q--) {
        string op; cin >> op;
        if (op == "IH") {
            int i; cin >> i;
            ins_head(head, tail, i);
        } else if (op == "IT") {
            int i; cin >> i;
            ins_tail(head, tail, i);
        } else if (op == "RH") {
            rm_head(head, tail); 
        } else if (op == "RT") {
            rm_tail(head, tail);
        } else if (op == "S") {
            int i; cin >> i;
            char ans = search(head, tail, i);
            cout << ans << "\n";
        } else if (op == "O") {
            output(head, tail);
        } else {
            assert(false && "unreachable");
        }
    }

    // free list
    while (head != nullptr) {
        rm_head(head, tail);
    }
}