#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll x; cin >> x;

  vector<ll> v;
  rep(i,121) {
    v.push_back((ll)pow(i,5));
  }

  rep(i,121) {
    rep(j,121) {
      if(v[i] - v[j] == x) {
	cout << i << " " << j << "\n";
	return 0;
      }
    }
  }
  
  rep(i,121) {
    rep(j,121) {
      if(v[i] + v[j] == x) {
	cout << i << " " << -j << "\n";
	return 0;
      }
    }
  }  
  return 0;
}
