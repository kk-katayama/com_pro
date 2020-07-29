#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n; cin >> n;
  deque<ll> dq;
  rep(i,n) {
    ll a; cin >> a;
    dq.push_back(a);
  }

  ll res = 0;
  while( dq.size() > 1) {
    ll fro1 = dq.front(); dq.pop_front();
    ll fro2 = dq.front(); 
    ll bac1 = dq.back(); dq.pop_back();
    ll bac2 = dq.back();
    ll fcos = 1 + 2*fro1 + fro2;
    ll bcos = 1 + 2*bac1 + bac2;
    if(fcos <= bcos) {
      res += fcos;
      dq.pop_front();
      ll nfro = 2 + fro1 + fro2 + dq.front();
      dq.pop_front();
      dq.push_front(nfro);
      dq.push_back(bac1);
    }
    else {
      res += bcos;
      dq.pop_back();
      ll nbac = 2 + bac1 + bac2 + dq.back();
      dq.pop_back();
      dq.push_back(nbac);
      dq.push_front(fro1);
    }
  }

  cout << res << "\n";
  
  return 0;
}
