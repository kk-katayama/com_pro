#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int m;
  cin >> m;
  vector<ll> d(m),c(m);
  rep(i,m){
    cin >> d[i] >> c[i];
  }
  
  ll sum=0;
  ll res=-1;
  rep(i,m){
    res+=c[i];
    sum+=d[i]*c[i];
  }
  cout << res+(sum-1)/9 << "\n";
  
  return 0;
}
