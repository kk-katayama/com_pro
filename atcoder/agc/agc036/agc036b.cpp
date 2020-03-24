#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int M = 210000;
int main()
{
  int n;cin >> n;
  ll k;cin >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  map<int,vector<int>> mp;
  rep(i,n){
    mp[a[i]].push_back(i);
  }
  vector<int> edge(n);
  for(auto m:mp){
    int nn = m.second.size();
    rep(i,nn) edge[m.second[i]] = (m.second[(i+1)%nn]+1)%n;
  }
  //  rep(i,n) cout << i << ":" << edge[i] << "\n";

  vector<int> b(1,0);
  int v = 0;
  while(edge[v] - v >= 2) v = edge[v];
  if(v == n-1 && edge[v] == 0) b.push_back(-1);
  // if(v == n-1 && edge[v] == 0){
  //   b.push_back(-1);
  // }
  v = edge[v];
  b.push_back(v);  
  while(v!=0){
    while(edge[v] - v >= 2) v = edge[v];
    if(v == n-1 && edge[v] == 0) b.push_back(-1);
    v = edge[v];
    b.push_back(v);
  }
  // rep(i,b.size()) cout << b[i] << " ";
  // cout  << "\n";

  ll y = b.size()-1;
  ll x = (k%y + y - 1) % y;
  //  cout << x << "\n";
  int j = b[x];
  
  vector<int> res;
  while(j<n){
    if(j<0) break;
    if(edge[j] - j >= 2) j = edge[j];
    else if(edge[j] == 0 && j != n-1) break;
    else{
      res.push_back(a[j]);
      j++;
    }
  }

  rep(i,res.size()) cout << res[i] << " ";
  cout << "\n";
  
  return 0;
}
