#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfs(vector<vector<int> > &AL,vector<bool> &V,int x){
	V[x] = true;
	for(auto i:AL[x]){
		if(!V[i]) dfs(AL,V,i);
	}
}
void bfs(vector<vector<int> > &AL,vector<bool> &V,int x){
	queue<int> Q;
	Q.push(x);
	while(!Q.empty()){
		int tmp = Q.front();
		Q.pop();
		if(V[tmp]) continue;
		V[tmp] = true;
		for(auto i:AL[tmp]){
			if(!V[i]) Q.push(i);
		}
	}
}
int main(){
	int t,n,m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int x,y;
		int ans = 0;
		vector<vector<int> > AL(n+1);
		vector<bool> visited(n+1,false);
		for(int i = 0;i<m;i++){
			cin >> x >> y;
			AL[x].push_back(y);
			AL[y].push_back(x);
		}
		//Finished input
		for(int i = 1;i<=n;i++){
			if(!visited[i]){ans++;bfs(AL,visited,i);}//Call bfs or dfs
		}
		cout << ans << endl;
	}
	return 0;
}