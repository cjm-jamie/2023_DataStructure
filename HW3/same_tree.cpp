#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> ans_post; // 存最後 postorder 的值

int Build_Tree_by_in_and_pre(vector<pair<int,int> >&T,vector<string>& P,vector<string>& I,unordered_map<string, int>& M,int l,int r,int &i){
    // 找到 root 並回傳
	// cout << "Trying to find " << P[i] << " in " << l << " -> " << r << "\n";
	if(r<l) return -1; // 超界，表示沒有小孩，到底了
	string cur_root = P[i]; // i: preorder的index, cur_root: 目前數字，這個subtree的root
	int where = M[cur_root]; // where: inorder 的位置，區分左右子樹的邊界

	if(where>r||where<l) // 可能inorder和preorder不是同一棵樹?
        return -1;  
	else i++;

    // 建立左子樹 (迭代的方式找左子樹的root)
	T[where].first = Build_Tree_by_in_and_pre(T,P,I,M,l,where-1,i);
    // 建立右子樹
	T[where].second = Build_Tree_by_in_and_pre(T,P,I,M,where+1,r,i);

    // 因為 root 是字串，不好直接回傳
    // 回傳 root 在 inorder 的位置，之後用 I[where] = cur_root
	return where; 
}

/* 改變cout的位置就能決定輸出的要是哪一種order */
/* preorder, inorder, postorder */
void consruct_post_order(int i,vector<pair<int,int> > &T, vector<string> &I){
	if(T[i].first!=-1) consruct_post_order(T[i].first,T,I);
	if(T[i].second!=-1) consruct_post_order(T[i].second,T,I);
	// cout << I[i] << " ";
    ans_post.push_back(I[i]);
}

int main(){
	int t, n;
	cin >> t;

    bool flag = true;

    while (t--)
    {
        cin >> n;
        vector<string> pre;
        vector<string> in;
        vector<string> post;

        vector<pair<int,int> > V(n+1,pair<int,int>(-1,-1));

        string tmp;

        for(int i = 0;i<n;i++){
            cin >> tmp;
            pre.push_back(tmp);
        }
        for(int i = 0;i<n;i++){
            cin >> tmp;
            in.push_back(tmp);
        }
        for(int i = 0;i<n;i++){
            cin >> tmp;
            post.push_back(tmp);
        }

        // 找到特定一個 "字串" 在 inorder 序列中的位置 (通常是找root)
        // 因為 inorder 是 LxR，找到root就能知道他的前面是L，後面是R
        // ex: in ={4, 2, 1, 5, 3}
        //     map_in[1] = 2, map_in[2] = 1, map_in[3] = 4, map_in[4] = 0, map_in[5] = 3
        
        unordered_map<string, int> map_in; 
        for(int i = 0;i<n;i++){
            // like inverse function of in[]
            map_in[in[i]] = i;
        }
        // cout << "\n";
        int begin = 0;
        int root = Build_Tree_by_in_and_pre(V,pre,in,map_in,0,n-1,begin);

        consruct_post_order(root,V,in);
        // cout << "\n"
        
        if(ans_post.size() < n){ //代表preorder和inorder沒辦法建成一棵樹
            cout << "no\n";
            continue;
        }

        for(int i=0; i<n; i++){
            if(ans_post[i] != post[i])
                flag = false; // 輸入進來的序列不等於自己建的
        } 

      	if(flag)
          cout << "yes\n";
  		else
          cout << "no\n";

        flag = true;
        ans_post.clear();        
    }
    
	return 0;
}