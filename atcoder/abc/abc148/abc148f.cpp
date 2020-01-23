#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,u,v;
  cin >> n >> u >> v;
  u--;
  v--;
  vector<int> a(n-1),b(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<vector<int>> edge(n);
  rep(i,n-1){
    edge[a[i]].push_back(b[i]);
    edge[b[i]].push_back(a[i]);    
  }
  
  vector<bool> f(n,false);
  vector<int> da(n,0),dt(n,0);

  queue<pair<int,int>> qa;
  qa.push(make_pair(v,0));
  while(!qa.empty()){
    int node = qa.front().first;
    int cnt = qa.front().second;    
    qa.pop();
    f[node] = true;
    for(auto w:edge[node]){
      if(f[w]) continue;
      da[w]=cnt+1;
      qa.push(make_pair(w,cnt+1));
    }
  }

  f.assign(n,false);
  queue<pair<int,int>> qt;
  qt.push(make_pair(u,0));
  while(!qt.empty()){
    int node = qt.front().first;
    int cnt = qt.front().second;    
    qt.pop();
    f[node] = true;
    for(auto w:edge[node]){
      if(f[w]) continue;
      dt[w]=cnt+1;
      qt.push(make_pair(w,cnt+1));
    }
  }

  int res = 0;
  rep(i,n){
    if(dt[i]<da[i]){
      res = max(res,da[i]-1);
    }
  }

  cout << res << "\n";
  
  
  // rep(i,n){
  //   cout << i << ":" << da[i] << "\n";
  // }
  // rep(i,n){
  //   cout << i << ":" << dt[i] << "\n";
  // }  
  
  
  return 0;
}
