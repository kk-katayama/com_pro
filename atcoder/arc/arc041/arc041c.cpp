#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n,l; cin >> n >> l;
  vector<ll> a(n);
  vector<char> b(n);
  rep(i,n) cin >> a[i] >> b[i];

  vector<ll> x;
  vector<char> d;
  if(b[0] == 'L') {
    x.push_back(0);
    d.push_back('R');
  }
  rep(i,n) {
    x.push_back(a[i]);
    d.push_back(b[i]);
  }
  if(b[n-1] == 'R') {
    x.push_back(l+1);
    d.push_back('L');
  }
  x.push_back(l+2);
  d.push_back('R');
  
  bool flag = true;
  ll cnt = 0;
  ll rpos, lpos;
  ll rcnt, lcnt;
  ll res = 0;
  rep(i,x.size()) {
    if(flag) { // R
      if(d[i] == 'R') {
	cnt++;
	rpos = x[i];
      }
      else {
	ll j = 0;
	rcnt = cnt;
	while(cnt > 0) {
	  res += rpos - j - x[i-1-j];
	  cnt--;
	  j++;
	}
	flag = false;
	lpos = x[i];
	cnt = 1;
      }
    }
    else { // L
      if(d[i] == 'L') {
	cnt++;
      }
      else {
	ll j = 0;
	lcnt = cnt;
	while(cnt > 0) {
	  res += x[i - lcnt + j] - lpos - j;
	  cnt--;
	  j++;
	}
	flag = true;
	cnt = 1;
	res += max(rcnt, lcnt) * (lpos - rpos - 1);
	rpos = x[i];
      }
    }
  }

  cout << res << "\n";
  
  return 0;
}
