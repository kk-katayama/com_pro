#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  priority_queue<ll> q;
  rep(i,n) q.push(a[i]);
  ll res = 0;
  rep(i,n) res += a[i];
  rep(i,m){
    ll x = q.top();
    q.pop();
    res -= (x+1)/2;
    q.push(x/2);
  }
  
  cout << res << "\n";
  
  return 0;
}
