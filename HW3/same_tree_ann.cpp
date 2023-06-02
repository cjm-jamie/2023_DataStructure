#include<iostream>
#include<vector>
#include <unordered_map>
#include <string>
//想法：用pre和in order 建立tree, 再跑post order來和題目給的做對照，如果對不上就代表不是同一個tree
using namespace std;
bool flag = true;//用來記錄重建tree的post order和題目的post order有沒有對上，沒有的話換false
vector<string> ans={};//用來存重建tree的post order

int Build_Tree_prein(vector<pair<int,int>> &T,vector<string>& P,vector<string>& I,unordered_map<string, int>& M,int l,int r,int &i){//用pre in order建tree
    //returns the root of this subtree
	//cout << "Trying to find " << P[i] << " in " << l << " -> " << r << endl;
	if(r<l){
      //cout << "Here!" << endl;
      return -1;
    } 
	string here = P[i];//i: preorder index, here: 目前的字串
	int where = M[here];//where: inorder index
  	//cout <<" here: "<< here << " where: " << where << " M[here]: " << M[here]<< endl;
	if(where>r||where<l){//不是這的問題
      return -1;
    } 
	else i++;
	T[where].first = Build_Tree_prein(T,P,I,M,l,where-1,i);
	T[where].second = Build_Tree_prein(T,P,I,M,where+1,r,i);
  	//cout << "node: " << here <<" left "<< T[i].first <<" right "<< T[i].second <<endl;
	return M[here];//return inorder index of root of tree
}


void post_order(int i,vector<pair<int,int>> &T,vector<string> &I){//讓重建的tree跑post order並存在ans裡
  	//cout << i << " ";
	if(T[i].first!=-1){
      post_order(T[i].first,T,I);
    } 
	if(T[i].second!=-1) post_order(T[i].second,T,I);
  	//cout << " I[i]: "<<I[i] <<" post[i]: "<< post[i] <<endl;
  	ans.emplace_back(I[i]);
	//cout << i << " ";
}
int main(){
  	int t;
  	cin >>t;
  	while(t--){
      	int n;
		cin >> n;
		vector<string> pre;
		vector<string> in;
  		vector<string> post;
		vector<pair<int,int> > V(n+1,pair<int,int>(-1,-1)); //tree
		string tmp;
		for(int i = 0;i<n;i++){//pre_order
			cin >> tmp;
			pre.push_back(tmp);
		}
		for(int i = 0;i<n;i++){//in_order
			cin >> tmp;
			in.push_back(tmp);
		}
      	for(int i = 0;i<n;i++){//post_order
			cin >> tmp;
			post.push_back(tmp);
		}
      	
      	
		unordered_map<string, int> map_in;//存string的in order
		for(int i = 0;i<n;i++){
			map_in[in[i]] = i;
		}
		int begin = 0;
		int root = Build_Tree_prein(V,pre,in,map_in,0,n-1,begin);//重建
      	//cout << "root: " << root << endl;//root 是對的
      	
		post_order(root,V, in);//重建完再跑post order並check(root, tree, post, map, in)
      	//for(int i = 0;i<n;i++){//post_order print
        //  	cout << "post: " ;
		//	cout << post[i] << " " ;
        //  	cout <<endl;
			
		//}
      	
      	for(int i=0;i<n;i++){//讓建完的post order和題目的post order對照
        //cout << " ans[i]: "<<ans[i] <<" post[i]: "<< post[i] <<endl;
          if(ans[i] != post[i]){//如果有沒對上的flag便false
            flag = false;
          }
        }
    	
      	if(flag){
          cout << "yes" << endl;
        }
  		else{
          cout << "no" <<endl;
        }

		flag = true;
		ans.clear();
    
    }

}
