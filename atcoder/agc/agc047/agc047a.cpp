#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int n; cin >> n;
  vector<string> a(n);
  rep(i,n) {
    cin >> a[i];
  }
  vector<ll> b(n, 0);
  rep(i,n) {
    ll cnt = 0;
    bool f = false;
    rep(j,a[i].size()) {
      if(a[i][j] == '.') {
	f = true;
      }
      else {
	b[i] += (ll)a[i][j] - '0';
	b[i] *= (ll)10;	
	if(f) {
	  cnt++;
	}
      }
    }
    b[i] *= pow((ll)10, 8 - cnt);
  }
  
  //  rep(i,n) cout << b[i] << "\n";

  using vl = vector<ll>;
  using vll = vector<vl>;
  vll d(19, vl(19, 0));
  rep(i,n) {
    ll cnt2 = 0;
    while(b[i] % 2 == 0) {
      cnt2++;
      b[i] /= 2;
    }
    ll cnt5 = 0;
    while(b[i] % 5 == 0) {
      cnt5++;
      b[i] /= 5;
    }
    cnt2 = min((ll)18, cnt2);
    cnt5 = min((ll)18, cnt5);
    d[cnt2][cnt5]++;
  }

  // rep(i,19) cout << i << " ";
  // cout  << "\n";
  // rep(i,19) {
  //   cout << i << " ";
  //   rep(j,19) {
  //     cout << d[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  
  
  ll res = 0;
  rep(i,19) rep(j,19) rep(k,19) rep(l,19) {
    if(i == k && j == l) {
      if(i >= 9 && j >= 9) {
	res += d[i][j] * (d[i][j] - 1);
      }
    }
    else {
      if(i + k >= 18 && j + l >= 18) res += d[i][j] * d[k][l];
    }
  }
  cout << res/2 << "\n";
  return 0;
}
