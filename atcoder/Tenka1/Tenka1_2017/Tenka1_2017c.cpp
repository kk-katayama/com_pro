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
#define rep(i,n) for(ll i = 0; i < n; ++i)
#define rep1(i,n) for(ll i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  ll N; cin >> N;
  ll M = 3500;
  rep1(i,M) {
    rep1(j,M) {
      ll x = 4*i*j - N*i - N*j;
      if(x <= 0) continue;
      if(N*i*j % x == 0) {
	cout << i << " ";
	cout << j << " ";
	cout << N*i*j / x << "\n";
	return 0;
      }
    }
  }
  return 0;
}
