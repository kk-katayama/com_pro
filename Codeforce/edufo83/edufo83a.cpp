#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int t;cin >> t;
  vector<int> n(t),m(t);
  rep(i,t) cin >> n[i] >> m[i];
  rep(i,t){
    if(n[i]%m[i]==0) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
  return 0;
}
