#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct RMQ{
  vector<X> dat;
  int n;
  X init;
  
  RMQ(int _n,X _init)
  {
    n = 1;
    init = _init;
    while(n < _n) n *= 2;
    dat.resize(2*n-1);
    rep(i,2*n-1){
      dat[i] = init;
    }
  }
  
  void update(int k,X a)
  {
    k += n - 1;
    dat[k] = a;
    while(k > 0){
      k = (k - 1)/2;
      dat[k] = max(dat[2*k+1],dat[2*k+2]);
    }
  }
  
  X query(int a,int b,int k,int l,int r)
  {
    if(r<=a||b<=l) return init;

    if(a<=l&&r<=b) return dat[k];
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return max(vl,vr);
    }
  }
};


int main()
{
  int t;
  cin >> t;
  vector<int> n(t);
  vector<vector<int>> a(t);
  vector<int> m(t);
  vector<vector<int>> p(t),s(t);
  vector<vector<pair<int,int>>> h(t);
  rep(i,t){
    cin >> n[i];
    a[i].resize(n[i]);
    rep(j,n[i]) cin >> a[i][j];
    cin >> m[i];
    p[i].resize(m[i]);
    s[i].resize(m[i]);
    h[i].resize(m[i]);
    rep(j,m[i]) {
      cin >> p[i][j] >> s[i][j];
      h[i][j] = make_pair(p[i][j],s[i][j]);
    }
  }
  
  rep(i,t){
    int index=0;
    map<int,int> mp;
    sort(h[i].begin(), h[i].end());
    rep(j,m[i]-1){
      if(h[i][j].first!=h[i][j+1].first){
  	mp[h[i][j].first]=index++;
      }
    }
    mp[h[i][m[i]-1].first]=index++;
    RMQ<int> rmq(index,0);
    rep(j,m[i]-1){
      if(h[i][j].first!=h[i][j+1].first){
  	rmq.update(mp[h[i][j].first],h[i][j].second);
      }
    }
    rmq.update(mp[h[i][m[i]-1].first],h[i][m[i]-1].second);
    int inf = 1e+9+10;
    mp[inf] = inf;
    vector<int> d(n[i]);
    bool f =false;
    rep(j,n[i]){
      int lb = mp.lower_bound(a[i][j])->second;
      if(lb==inf){
  	f = true;
  	break;
      }
      d[j] = rmq.query(lb,rmq.n,0,0,rmq.n);
    }
    if(f){
      cout << -1 << "\n";
      continue;
    }
    int cnt=0;
    int mini=inf;
    int res=1;
    rep(j,n[i]){
      cnt++;
      mini=min(mini,d[j]);
      if(cnt>mini){
  	cnt=1;
  	res++;
      }
    }
    cout << res << "\n";
  }

  
  
  return 0;
}
