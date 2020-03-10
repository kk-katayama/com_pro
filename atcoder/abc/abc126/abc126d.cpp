#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
class Tree{
private:
  int n;//number of node
  int m;
  vector<vector<int>> edge;// edge does not have cost.
  vector<vector<pair<int,ll>>> edge2;// edge has cost.
  vector<ll> d;
public:  
  //*****Constructor************
  Tree(int n_){
    n = n_;
    edge.resize(n);
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b){
    n = n_;
    m = m_;
    edge.resize(n);
    rep(i,m){
      edge[a[i]].push_back(b[i]);
      edge[b[i]].push_back(a[i]);
    }
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b,vector<ll> c){
    n = n_;
    m = m_;
    edge2.resize(n);
    rep(i,m){
      edge2[a[i]].push_back({b[i],c[i]});
      edge2[b[i]].push_back({a[i],c[i]});
    }
  }  
  //*******************************************

  void bfs(){
    d.assign(n,-1);
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
      int v = q.front();q.pop();
      for(auto w:edge2[v]){
	if(d[w.first]>=0) continue;
	d[w.first] = d[v] + w.second;
	q.push(w.first);
      }
    }
    rep(i,n){
      if(d[i]%2==0) cout << 0 << "\n";
      else cout << 1 << "\n";
    }
  }
  
};



int main()
{
  int n;cin >> n;
  vector<int> a(n-1),b(n-1);
  vector<ll> c(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;b[i]--;
  }
  Tree tr(n,n-1,a,b,c);
  tr.bfs();
  return 0;
}
