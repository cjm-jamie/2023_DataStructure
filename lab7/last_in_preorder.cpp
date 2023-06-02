#include<iostream>
#include<vector>
#define f first
#define s second

using namespace std;

void dfs(int sub_root,vector<pair<int,int> >& T,int &ans){
    // cout << index << " ";
	ans = sub_root;
	if(T[sub_root].f!=-1) dfs(T[sub_root].f,T,ans);
	if(T[sub_root].s!=-1) dfs(T[sub_root].s,T,ans);
	return;
}

/* redundant function */
void search(int index,vector<pair<int,int> >&T,int &ans){
	if(T[index].s!=-1) search(T[index].s,T,ans);
	else if(T[index].f!=-1) search(T[index].f,T,ans);
	else ans = index;
}

int main(){
	long long n;
	cin >> n;
	vector<pair<int,int> > T(n+1,pair<int,int>(-1,-1));

	/* 假設是 binary tree ，連續並且數值從1開始 */
	/* 把所有的數字加起來 1+2+3+...*/
	long long root = n*(n+1)/2;
	int ans;
	for(int i = 1;i<=n;i++){
		int l,r;
		cin >> l >> r;
		/* 然後再把所有小孩的數值扣掉 */
		if(l!=-1){T[i].f = l;root-=l;}
		if(r!=-1){T[i].s = r;root-=r;}
	}
	/* 最後就會得到root的數值 */
	dfs(root,T,ans);
    // cout << "\n";
	// search(root,T,ans);
	cout << ans << "\n";
	return 0;
}