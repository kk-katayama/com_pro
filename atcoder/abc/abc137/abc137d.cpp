#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n,m;
int a[100010],b[100010];
pair<int,int> p[100010];
vector<int> v[100010];
priority_queue<int> q;
int main()
{
  cin >> n >> m;
  rep(i,n) cin >> a[i] >> b[i];
  rep(i,n) p[i] = make_pair(a[i],b[i]);
  rep(i,100001) v[i].push_back(0); 
  rep(i,n){
    v[p[i].first].push_back(p[i].second);
  }
  
  int res = 0;
  rep(i,m){
    int vs=v[i+1].size();
    rep(j,vs){
      q.push(v[i+1][j]);
    }
    
    res += q.top();
    q.pop();
  }
  cout << res << "\n";
  
  return 0;
}
