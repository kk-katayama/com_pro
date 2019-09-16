#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  string a;
  cin >> a;
  int n = a.size();

  map<char,ll> mp;
  rep(i,n) mp[a[i]] = 0;
  
  rep(i,n){
    mp[a[i]]++;
  }

  ll res = 0;
  for(auto& itr:mp){
    ll x = itr.second;
    res += x*(x-1)/2;
  }

  ll nn = (ll)n;

  cout << nn*(nn-1)/2+1-res << "\n";
  
  return 0;
}
