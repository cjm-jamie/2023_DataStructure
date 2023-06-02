#include <iostream>
#include <unordered_set>

using namespace std;

typedef struct node{
    int index;
    node* left;
    node* right;
    
    node(int i, node* l, node* r) : index(i), left(l), right(r) {}
}node;

void dfs(node* current, int& ans) {
    if (current == nullptr)
        return;
    // cout << current->index << " ";
    ans = current->index;
    
    dfs(current->left, ans);
    dfs(current->right, ans);
}

node* findRoot(const std::unordered_set<int>& childSet) {
    for (auto& pair : childSet) {
        if (childSet.find(pair - 1) == childSet.end()) {
            return new node(pair, nullptr, nullptr);
        }
    }
    return nullptr;
}

/* redundant function */
void search(node* current, int& ans) {
    if (current == nullptr)
        return;

    search(current->right, ans);
    if (current->right == nullptr)
        search(current->left, ans);
    
    if (current->left == nullptr && current->right == nullptr)
        ans = current->index;
}

int main() {
    int n, ans;
    cin >> n;

    unordered_set<int> childSet;
    /* 因為值是從1開始，所以要建n+1個nodes pointer */
    node* nodes[n + 1];

    /* 建立 tree nodes */
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;

        node* newNode = new node(i, nullptr, nullptr);
        nodes[i] = newNode;

        if (l != -1) {
            /* 把left指到left child那個pointer*/
            childSet.insert(l);
            newNode->left = nodes[l];
        }
        if (r != -1) {
            childSet.insert(r);
            newNode->right = nodes[r];
        }
    }
    node* root = findRoot(childSet);

    dfs(root, ans);
    cout << ans << "\n";

    return 0;
}
