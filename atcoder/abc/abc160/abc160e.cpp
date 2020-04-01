#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
bool comp(ll &a,ll &b){
  return a > b;
}
int main()
{
  int x,y,a,b,c;cin >> x >> y >> a >> b >> c;
  vector<ll> p(a),q(b),r(c);
  rep(i,a) cin >> p[i];
  rep(i,b) cin >> q[i];
  rep(i,c) cin >> r[i];

  sort(p.begin(), p.end(), comp);
  sort(q.begin(), q.end(), comp);  
  priority_queue<ll,vector<ll>,greater<ll>> pq;
  ll res = 0;
  rep(i,x){
    pq.push(p[i]);
    res += p[i];
  }
  rep(i,y){
    pq.push(q[i]);
    res += q[i];
  }
  sort(r.begin(), r.end(), comp);
  rep(i,c){
    int tmp = pq.top();
    if(tmp < r[i]){
      res += r[i] - tmp;
      pq.pop();
    }
    else break;
  }
  cout << res << "\n";
  return 0;
}
