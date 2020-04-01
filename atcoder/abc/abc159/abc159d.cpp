#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;cin >> n;
  map<int,ll> mp;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
    mp[ a[i] ]++;
  }

  ll sum = 0;
  for(auto m:mp){
    sum += m.second * (m.second - 1) / 2;
  }

  rep(i,n){
    if(mp[ a[i] ] == 1) cout << sum << "\n";
    else{
      ll res = sum - mp[ a[i] ] * ( mp[ a[i] ] - 1 ) / 2 + ( mp[ a[i] ] - 1 ) * ( mp[ a[i] ] - 2 ) / 2;
      cout << res << "\n";
    }
  }
  
  return 0;
}
