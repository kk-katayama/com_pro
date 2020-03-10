#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int t;cin >> t;
  vector<int> n(t);
  vector<vector<int>> a(t);
  rep(i,t){
    cin >> n[i];
    a[i].resize(n[i]);
    rep(j,n[i]){
      cin >> a[i][j];
      a[i][j] *= -1;
    }
  }

  rep(i,t) sort(a[i].begin(), a[i].end());
  rep(i,t){
    rep(j,n[i]){
      cout << -a[i][j] << " ";
    }
    cout  << "\n";
  }
  
  return 0;
}
