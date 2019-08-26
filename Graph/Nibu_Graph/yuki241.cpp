#include<iostream>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int INF=1e+9;
struct edge{
  int to,cap,rev;
};
int n;
int a[60];
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
    rep(i,n) used[i] = false;
    int f=dfs(s,t,INF);
    if(f==0) return flow;
    flow+=f;
  }
}

int main()
{
  cin >> n;
  rep(i,n) cin >> a[i];

  rep(i,n){
    rep(j,n){
      if(j == a[i]) continue;
      add_edge(i,j,1);
    }
  }

  rep(i,n) add_edge(n,i,1);
  rep(i,n) add_edge(i,n+1,1);  

  
  
  return 0;
}
