#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define scan(arg) cin>>arg
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
using namespace std;
typedef long long ll;
const int INF=1e+9;
struct edge{
  int to,cap,rev;
};
vector<edge> g[100010];//グラフに隣接リスト表現
bool used[100010];//DFSですでに調べたかのグラフ
//fromからtoへ向かう容量capの辺をグラフに追加
void add_edge(int from,int to,int cap){
  g[from].push_back((edge){to,cap,g[to].size()});
  g[to].push_back((edge){from,0,g[from].size()-1});
}
//増加パスをDFSで探す
int dfs(int v,int t,int f){
  if(v==t) return f;
  used[v]=true;
  rep(i,g[v].size()){
    edge &e=g[v][i];
    if(!used[e.to]&&e.cap>0){
      int d=dfs(e.to,t,min(f,e.cap));
      if(d>0){
	e.cap-=d;
	g[e.to][e.rev].cap+=d;
	return d;
      }
    }
  }
  return 0;
}
//sからtへの最大流を求める
int max_flow(int s,int t){
  int flow=0;
  while(1){
    memset(used,0,sizeof(used));
    int f=dfs(s,t,INF);
    if(f==0) return flow;
    flow+=f;
  }
}



int main(){
  /*  add_edge(0,1,10);
  add_edge(1,3,6);  
  add_edge(1,2,6);
  add_edge(0,2,2);
  add_edge(3,2,3);  
  add_edge(2,4,5);
  add_edge(3,4,8);
  prin(max_flow(0,4));
  */
  add_edge(0,1,1);
  add_edge(0,2,1);
  add_edge(0,3,1);  
  add_edge(1,4,1);
  add_edge(2,4,1);
  add_edge(3,4,1);
  add_edge(1,5,1);
  add_edge(2,5,1);
  add_edge(3,5,1);
  add_edge(4,6,1);
  add_edge(5,6,1);
  prin(max_flow(0,6));
  
  return 0;
}
