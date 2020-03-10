#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,q;cin >> n >> q;
  vector<int> l(q),r(q),t(q);
  rep(i,q) cin >> l[i] >> r[i] >> t[i];
  vector<int> res(n,0);
  rep(i,q){
    l[i]--;r[i]--;
    for(int j=l[i];j<=r[i];++j) res[j] = t[i];
  }

  rep(i,n) cout << res[i] << "\n";
  return 0;
  
}
