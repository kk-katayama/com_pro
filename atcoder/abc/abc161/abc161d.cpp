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
  int n;cin >> n;
  queue<ll> q;
  rep1(i,9) q.push(i);

  ll res;
  rep(i,n) {
    res = q.front(); q.pop();
    ll x = res % 10;
    if(x != 0) q.push( res*10 + x - 1);
    q.push( res*10 + x );
    if(x != 9) q.push( res*10 + x + 1);      
  }

  cout << res << "\n";
  return 0;
}
