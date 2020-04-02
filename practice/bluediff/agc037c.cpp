#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;cin >> n;
  vector<ll> a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  vector<ll> bb = b;
  priority_queue<pair<ll,int>> q;
  bool f = true;
  rep(i,n) {
    if(a[i] < b[i]) q.push({b[i], i});
    else if(a[i] > b[i]) f = false;
  }

  ll res = 0;
  while(!q.empty()) {
    int index = q.top().second; q.pop();
    ll x = bb[ (index - 1 + n) % n ];
    ll y = bb[index];
    ll z = bb[ (index + 1) % n ];
    if(y <= x + z) {
      f = false;
      break;
    }
    ll tmp = (y - (ll)1) / (x + z);
    bb[index] -= (x + z) * tmp;
    if(bb[index] > a[index]) q.push({bb[index], index});
    else if(bb[index] < a[index]) {
      f = false;
      break;
    }
    res += tmp;
  }
  if(f) cout << res << "\n";
  else cout << -1 << "\n";

  // f = true;
  // res = 0;
  // bb = b;
  // rep(i,n) {
  //   if(a[i] < b[i]) q.push({b[i], i});
  //   else if(a[i] > b[i]) f = false;
  // }  
  // while(!q.empty()) {
  //   int index = q.top().second; q.pop();
  //   bb[index] -= bb[ (index - 1 + n) % n ] + bb[ (index + 1) % n ];
  //   if(bb[index] > a[index]) q.push({bb[index], index});
  //   else if(bb[index] < a[index]) {
  //     f = false;
  //     break;
  //   }
  //   res++;
  // }
  // if(f) cout << res << "\n";
  // else cout << -1 << "\n";
  
  return 0;
}
