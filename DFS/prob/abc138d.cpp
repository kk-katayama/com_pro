#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
class Tree{
private:
  int n;
  vector<vector<int>> edge;
  vector<int> d;
  vector<int> res;
public:
  Tree(int _n,vector<int> a,vector<int> b){
    n = _n;
    edge.resize(n);
    d.resize(n,0);
    res.resize(n,0);    
    rep(i,n-1){
      edge[a[i]].push_back(b[i]);
      edge[b[i]].push_back(a[i]);      
    }
  }

  void init(vector<int> p,vector<int> x){
    rep(i,p.size()) d[p[i]] += x[i];
  }

  void dfs(int v,int p,int point){
    for(auto w:edge[v]){
      if(w==p) continue;
      dfs(w,v,point+d[w]);
    }
    res[v] = point;
  }

  void solve(){
    dfs(0,-1,d[0]);
    rep(i,n) cout << res[i] << " ";
    cout  << "\n";
  }

};


int main()
{
  int n,q;
  cin >> n >> q;
  vector<int> a(n-1),b(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i];a[i]--;b[i]--;
  }
  Tree tr(n,a,b);

  vector<int> p(q),x(q);
  rep(i,q){
    cin >> p[i] >> x[i];p[i]--;
  }
  tr.init(p,x);
  tr.solve();

  
  return 0;
}
