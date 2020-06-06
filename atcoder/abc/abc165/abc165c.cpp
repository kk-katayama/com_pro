#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int n,m,q;
int a[100],b[100],c[100],d[100];
int res;
void dfs(int cnt, int val, vector<int> &vec) {
  if(cnt == n) {
    int sum = 0;
    rep(i,q) {
      if((vec[b[i]] - vec[a[i]]) == c[i]) sum += d[i];
    }
    chmax(res, sum);
    rep(i,vec.size()) cout << vec[i] << " ";
    cout << "\n";
    return ;
  }
  vec.push_back(val);
  for (int i = val; i < m; ++i) {
    dfs(cnt+1 , i, vec);
  }
  vec.pop_back();
}
int main()
{
  cin >> n >> m >> q;
  
  rep(i,q) { 
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--; b[i]--;
  }

  res = 0;
  vector<int> vec;
  dfs(0, 0, vec);
  cout << res << "\n";
  
  return 0;
}
