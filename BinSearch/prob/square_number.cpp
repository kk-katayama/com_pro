#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
ll upper_bound(ll k){
  ll left = -1,right = 1e+9;
  while(right-left>1){
    ll mid=(right+left)/2;
    if(mid*mid >= k) right=mid;
    else left=mid;
  }
  return right;
}

int main()
{
  ll n;cin >> n;
  ll res = upper_bound(n);
  cout << res << "*" << res << " = " << res*res << "\n";
  return 0;
}
