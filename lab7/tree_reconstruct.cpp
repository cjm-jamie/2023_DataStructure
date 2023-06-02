#include <iostream>
#include <vector>
#define f first
#define s second
using namespace std;

int Build_Tree(vector<pair<int,int> >&T,vector<int>& P,vector<int>& I,vector<int>& M,int l,int r,int &i){
    // 找到 root 並回傳
	// cout << "Trying to find " << P[i] << " in " << l << " -> " << r << "\n";
	if(r<l) return -1;
	int cur_root = P[i]; // i: preorder的index, cur_root: 目前數字，這個subtree的root
	int where = M[cur_root];  // where: inorder 的位置
	if(where>r||where<l)
		return -1; // 超界，表示沒有小孩，到底了
	else i++;
    // 建立左子樹 (迭代的方式找左子樹的root)
	T[cur_root].f = Build_Tree(T,P,I,M,l,where-1,i);
    // 建立右子樹
	T[cur_root].s = Build_Tree(T,P,I,M,where+1,r,i);

	/* 先處理完所有的左子樹和右子樹才會 return root，所以當所有的左子樹和右子樹都處理完後*/
	/* 最後return的就會是整棵樹的root */
	return cur_root;
}

/* 改變cout的位置就能決定輸出的要是哪一種order */
/* preorder, inorder, postorder */
void dfs(int i,vector<pair<int,int> > &T){
	if(T[i].f!=-1) dfs(T[i].f,T);
	if(T[i].s!=-1) dfs(T[i].s,T);
	cout << i << " "; //postorder
}

int main(){
	int n;
	cin >> n;
	vector<int> pre; // 存 preorder 序列
	vector<int> in; // 存 inorder 序列
	vector<pair<int,int> > V(n+1,pair<int,int>(-1,-1)); // 存 left/ right child，預設(-1,-1)

	int tmp;
	for(int i = 0;i<n;i++){
		cin >> tmp;
		pre.push_back(tmp);
	}
	for(int i = 0;i<n;i++){
		cin >> tmp;
		in.push_back(tmp);
	}

    // 找到特定一個值在 inorder 序列中的位置 (通常是找root)
    // 因為 inorder 是 LxR，找到root就能知道他的前面是L，後面是R
    // ex: in ={4, 2, 1, 5, 3}
    //     map_in[1] = 2, map_in[2] = 1, map_in[3] = 4, map_in[4] = 0, map_in[5] = 3
	vector<int> map_in(n+1,-1);
	for(int i = 0;i<n;i++){
        // like inverse function of in[]
		map_in[in[i]] = i;
	}
    // cout << "\n";
	int begin = 0; // 起始位置
	int root = Build_Tree(V,pre,in,map_in,0,n-1,begin); //用 V 來建立 tree

    // for (int i = 0; i < V.size(); i++) 
    //     cout << i << " " << V[i].f << " " << V[i].s << "\n";
	// cout << "\n";

	dfs(root,V); // 印出 postorder 序列
	cout << "\n";
	return 0;
}