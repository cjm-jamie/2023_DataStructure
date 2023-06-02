#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
    Node(int _key, Node* _left = nullptr, Node* _right = nullptr, Node* _parent = nullptr) 
        : key(_key), left(_left), right(_right), parent(_parent) {}
} Node;

// Input:   The root node of the tree.
// Return:  The node with minimum value of the tree.
Node* findmin(Node* root) {
    while(root -> left)
        root = root -> left;
    return root;
}

// Input:   The root node of the tree.
// Return:  The node with maximum value of the tree.
Node* findmax(Node* root) {
    while(root -> right)
        root = root -> right;
    return root;
}

// Input:   The root node of the tree and the value we want to find.
// Return:  The node with the value. If the node doesn't exist, return nullptr.
Node* search(Node* root, int k) {
    if (root == nullptr)    return nullptr;
    if (root -> key == k)    return root;
    if (root -> key > k)
        return search(root -> left, k);
    else
        return search(root -> right, k);
}

// Input:   The root node of the tree we want to insert the node into.
void insertnode(Node* &root, Node* node) {
    if (root == nullptr) {
        root = node;
        return;
    }
    if (root -> key > node -> key) {
        if (root -> left) {
            insertnode(root -> left, node);
        } else {
            root -> left = node;
            node -> parent = root;
        }
    } else if (root -> key < node -> key) {
        if (root -> right) {
            insertnode(root -> right, node);
        } else {
            root -> right = node;
            node -> parent = root;
        }
    }
    return;
}

// Transplant(root, x, y) links x's parent to y and y's parent is changed accordingly under the tree root
void transplant(Node* &root, Node* x, Node* y) {
    if (x -> parent == nullptr) {
        root = y;
    } else if (x -> parent -> left == x) {
        x -> parent -> left = y;
    } else {
        x -> parent -> right = y;
    }

    if (y) {
        y -> parent = x -> parent;
    }
    return;
}

// Input:   The root node of the tree and the node we want to delete
void deletenode(Node* &root, Node *x) {
    /* Case 1: x is a leaf */
    if (x -> left == nullptr && x -> right == nullptr)
        transplant(root, x, nullptr);
    /* Case 2: x has one child */
    else if (x -> left == nullptr)
        transplant(root, x, x -> right);
    else if (x -> right == nullptr)
        transplant(root, x, x -> left);
    /* Case 3: x has two children */
    else {
        Node* y = findmin(x -> right);
        if (y -> parent == x) {
            transplant(root, x, y);
            y -> left = x -> left;
            x -> left -> parent = y;
        } else {
            transplant(root, y, y -> right);
            transplant(root, x, y);
            y -> right = x -> right;
            y -> left = x -> left;
            x -> right -> parent = x -> left -> parent = y;
        }
    }
    free(x);
}

// Input:   The root node of the tree and the value of x
// Return:  The smallest element greater than or equal to x in the set.
//          If the value doesn't exist, return -1
int findlowerbound(Node *root, int x) {
    int ans = -1;
    if (x < root -> key) {
        if (root -> left != NULL)
            ans = findlowerbound(root -> left, x);

        if (ans != -1) 
            ans = min(root -> key, ans);
        else 
            ans = root -> key;
    } else if (x > root -> key) {
        if (root -> right != NULL)
            ans = findlowerbound(root -> right, x);
    } else /*(node -> key == x)*/
        ans = x;
    return ans;
}

// Input:   The root node of the tree and the value of x
// Return:  The smallest element greater than x in the set.
//          If the value doesn't exist, return -1
int findupperbound(Node *root, int x) {
    int ans = -1;
    if (x < root -> key) {
        if (root -> left != NULL)
            ans = findupperbound(root -> left, x);

        if (ans != -1)
            ans = min(root -> key, ans);
        else 
            ans = root -> key;
    } else /*if (x >= root -> key)*/ {
        if (root -> right != NULL)
            ans = findupperbound(root -> right, x);
    }
    return ans;
}

int main() {
    int t, cnt_distinct_node;  
    cin >> t;
    Node *root = nullptr;

    while (t--)
    {
        string op;
        int x;
            cin >> op >> x;
        switch(op[0])
        {
        case 'I':
            // only increase when x is not in the set 
            if(search(root, x) == nullptr)
                cnt_distinct_node++;
            Node* node = new Node(x);
            insertnode(root, node);
            cout << cnt_distinct_node << "\n";
            break;
        case 'D':
            // only delete node whenever it exists
            if(search(root, x) != nullptr)
                deletenode(root, search(root, x));
            // decrease if x all be deleted
            if(search(root, x) == nullptr)
                cnt_distinct_node--;
            cout << cnt_distinct_node << "\n";
            break;
        case 'C':
            int cnt = 0;
            while (search(root, x)!=nullptr)
            {
                cnt++;
            }
            
            cout << "I don't know how to write\n";
            break;
        case 'L':
            cout << findlowerbound(root, x) << "\n";
            break;
        case 'U':
            cout << findupperbound(root, x) << "\n";
            break;
        }
    }
    
    return 0;
}