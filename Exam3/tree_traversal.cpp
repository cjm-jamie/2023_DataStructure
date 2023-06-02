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
int postidx;

/* build tree by inorder and postorder */
node* buildtree(vector<string>& post, unordered_map<string, int>& inmap, int start, int end) {
	// cout << "Trying to find " << post[postidx] << " in " << start << " -> " << end << "\n";
    if (start > end) return nullptr;
    node* cur_root = new node();
    cur_root -> s = post[postidx]; //postidx 就是每一次減少1，一個一個找
    int idx = inmap[cur_root -> s]; //idx: inorder 的位置，區分左右子樹的邊界
    if(idx > end || idx < start) // 找到的idx有可能超出邊界
        return nullptr;
    postidx --;
    cur_root->right = buildtree(post, inmap, idx + 1, end);
    cur_root->left = buildtree(post, inmap, start, idx - 1);
	/* 先處理完所有的左子樹和右子樹才會 return root，所以當所有的左子樹和右子樹都處理完後*/
	/* 最後return的就會是整棵樹的root */
    return cur_root;
}

/* 改變cout的位置就能決定輸出的要是哪一種order */
/* preorder, inorder, postorder */
void preorder_trav(node* root) {
    if (root == nullptr) return;
    else {
        chk.push_back(root->s);
        preorder_trav(root->left);
        preorder_trav(root->right);
    }
}

void check(vector<string>& post, int n) {
    int cnt = 0, x = chk.size(); 
    if (x != n) {
        cout << "Impossible\n"; // 可能inorder和preorder不是同一棵樹
    }
    else { // 比對postorder的值
        for (int i = 0; i < x; i++) {
            cout << chk[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        postidx = n-1;
        chk.clear();
        vector<string> in(n), post(n);
        unordered_map<string, int> inmap;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> post[i];
        }

        for (int i = 0; i < n; i++) {
            inmap[in[i]] = i;
        }

        node* root = buildtree(post, inmap, 0, n - 1);
        preorder_trav(root);

        check(post, n);
    }
}