#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <random>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll D; cin >> D;
  vector<ll> c(26);
  rep(i,26) cin >> c[i];
  vector<vector<ll>> s(D, vector<ll>(26));
  rep(i,D) {
    rep(j,26) {
      cin >> s[i][j];
    }
  }

  vector<ll> t(D);  
  vector<ll> last(26, -1);
  rep(i,D) {
    ll score = -1000000000;
    rep(j,26) {
      ll tmp = 0;
      rep(k,26) {
	if(j == k) {
	  tmp += s[i][j];
	}
	else {
	  tmp -= c[k] * (i - last[k]);
	}
      }
      if( chmax(score, tmp) ) {
	t[i] = j;
      }
    }
    last[t[i]] = i;
  }

  
  
  rep(i,D) cout << t[i]+1 << "\n";
  
  return 0;
}
