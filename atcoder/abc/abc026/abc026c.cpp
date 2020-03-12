#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
class Tree{
private:
  int n;//number of node
  int m;
  vector<vector<int>> edge;// edge does not have cost.
  vector<vector<pair<int,int>>> edge2;// edge has cost.
  vector<int> d;
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
    d.resize(n,-1);
    rep(i,m){
      edge[a[i]].push_back(b[i]);
      //      edge[b[i]].push_back(a[i]);
    }
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b,vector<int> c){
    n = n_;
    m = m_;
    edge2.resize(n);
    rep(i,m){
      edge2[a[i]].push_back(make_pair(b[i],c[i]));
      edge2[b[i]].push_back(make_pair(a[i],c[i]));
    }
  }
  //*******************************************

  int dfs(int v){
    int ax = 0,in = 1e+9;
    for(auto w:edge[v]){
      int x = dfs(w);
        ax = max(x,ax);
      in = min(x,in);
    }
    if(in==1e+9) in = 0;
    return ax + in + 1;
  }
  
};


int main()
{
  int n;cin >> n;
  vector<int> a(n-1),b(n-1);
  rep(i,n-1){
    cin >> a[i];a[i]--;
    b[i] = i+1;
  }
  Tree tr(n,n-1,a,b);
  cout << tr.dfs(0) << "\n";
  
  return 0;
}
