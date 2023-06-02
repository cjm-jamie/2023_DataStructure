#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

struct node {
    string s;
    node* left;
    node* right;
    node() : s(), left(nullptr), right(nullptr) {};
};

vector<string> chk;
int preidx = 0;

node* buildtree(vector<string>& pre, unordered_map<string, int>& inmap, int start, int end) {
    if (start > end) return nullptr;
    node* cur_root = new node();
    cur_root -> s = pre[preidx++]; //preidx 就是每一次增加1，一個一個找
    int idx = inmap[cur_root -> s]; //idx: inorder 的位置，區分左右子樹的邊界
    if(idx > end || idx < start) // 找到的idx有可能超出邊界
        return nullptr;
    cur_root->left = buildtree(pre, inmap, start, idx - 1);
    cur_root->right = buildtree(pre, inmap, idx + 1, end);
	/* 先處理完所有的左子樹和右子樹才會 return root，所以當所有的左子樹和右子樹都處理完後*/
	/* 最後return的就會是整棵樹的root */
    return cur_root;
}

/* 改變cout的位置就能決定輸出的要是哪一種order */
/* preorder, inorder, postorder */
void postorder_trav(node* root) {
    if (root == nullptr) return;
    else {
        postorder_trav(root->left);
        postorder_trav(root->right);
        chk.push_back(root->s);
    }
}

void check(vector<string>& post, int n) {
    int cnt = 0, x = chk.size(); 
    if (x != n) {
        cout << "no\n"; // 可能inorder和preorder不是同一棵樹
    }
    else { // 比對postorder的值
        for (int i = 0; i < x; i++) {
            if (chk[i] != post[i]) {
                cout << "no\n";
                return;
            }
        }
        cout << "yes\n";
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        preidx = 0;
        chk.clear();
        vector<string> pre(n + 1), post(n + 1);
        unordered_map<string, int> inmap;
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
        }
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            inmap[tmp] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> post[i];
        }
        node* root = buildtree(pre, inmap, 0, n - 1);
        postorder_trav(root);

        check(post, n);
    }
}
