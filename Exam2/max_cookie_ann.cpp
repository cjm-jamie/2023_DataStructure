#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

void bfs(vector<vector<int>> &AL,vector<bool> &V, int x, vector<int> goal, vector<pair<int,int>> &ans){  //bfs的凾式
 priority_queue<int> find_max;
 int cookies_counter=0;
 
 queue<pair<int,int>> Q = {};  //建立確定的queue為Q，pair(位置，距離)
 Q.push(make_pair(x,0));  //將起始點push進queue
   
 while(!Q.empty()){  //當Q不是空的(代表還沒有bfs完)
  pair<int,int> tmp = Q.front();  //將Q的最前端存進tmp
  Q.pop();  //把最前端的丟掉
  if(V[tmp.first]){  //如果踩過這個地方
          continue;  //直接開始新的迴圈
        }
  
       for(auto k: goal){  //對所有餅乾的位置來說
          if (tmp.first == k){  //如果餅乾的值和剛丟掉的位置一樣，代表踩到餅乾上
            cookies_counter++;  //餅乾數+1
            //break;  //直接離開for迴圈
          }
        }
  //cout <<"tmp  " << tmp.first << " " << tmp.second <<endl; 
        
        
        find_max.push(tmp.first);//把該點存進heap
  V[tmp.first] = true;  //要不然把那個位置的flag翻正
       //cout << "看鄰居";
  for(auto i:AL[tmp.first]){  //對被處裡的這個點的所有鄰居來說
   if(!V[i]){  //如果沒有被踩過
              //cout << i << " ";
              Q.push(make_pair(i,tmp.second+1));  //把它塞進queue裡且距離+1
            } 
  }
       //cout << "\n";
 }
    //cookies_counter--;
 ans.emplace_back(make_pair(cookies_counter,find_max.top()));
   //cout << "here" <<endl;
   //cout << find_max.top() << " " << cookies_counter <<endl;
}

bool first_cmp(pair <int, int> fir, pair <int, int> sec){
  return fir.first > sec.first;
}

int main(){
  int t, n, m;  //t:testcase number, n: node number, m: line number
  int a, b;  //存cin的小工具
  int cookies_num;  //start_pt:start point, cookies_num: amount of cookies
  cin >> t;  //輸入testcase
  while(t--){  //做幾次testcase
    cin >> n >> m;  //輸入圖的node數和line數
    
    vector<pair<int,int>> ans={};//<amounts of cookies,max of its number>
    vector<vector<int>> adj_list(n+1,vector<int>{});  //建立size為n+1的二維陣列，每隔裡面塞vector<int>
    vector<bool> check(n+1,false);  //建立旗子陣列，size為n+1，預設沒踩過(false)
    for(int i = 0; i < m; i++){  //要存m條路線
      cin >> a >> b;  //將有連起來的路線吃進來
      adj_list[a].emplace_back(b);  //node a connect to b
      adj_list[b].emplace_back(a);  //node b connect to a 
    }
    
    
    cin >> cookies_num;  //input start point and amount of cookies
    vector<int> cookies = {};  //construct a set for cookies position
    for(int i = 0; i < cookies_num; i++){  //insert cookies position
      cin >> a;
      cookies.emplace_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){
            bfs(adj_list, check, i, cookies,ans);  //run bfs func(graph,flag,start_point, cookies position set)
        }
    }
    sort(ans.begin(),ans.end(),first_cmp);
    cout << ans[0].second << " " << ans[0].first <<endl;
    
  }
}