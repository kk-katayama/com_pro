#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,a,b;
  cin >> n >> a >> b;

  if(n<a+b-1||a*b<n) {
    cout << -1 << "\n";
    return 0;
  }

  if(a==1) {
    rep(i,n) cout << n-i << " ";
    cout<< "\n";
    return 0;
  }
  vector<ll> res(0);
  
  ll x = (n-b-1)/(a-1);
  ll cnt = 1;
  
  rep(i,x){
    rep(j,a){
      res.push_back(cnt+a-1-j);
    }
    cnt += a;
  }

  ll y = n+x+2-b-cnt;

  rep(i,y) res.push_back(cnt+y-1-i);
  cnt += y;
  
  for(ll i=cnt;i<=n;++i) res.push_back(i);

  reverse(res.begin(), res.end());

  rep(i,n) cout << res[i] << " ";
  cout  << "\n";
  

  return 0;
}
