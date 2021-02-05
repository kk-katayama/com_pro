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
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  ll a,b; cin >> a >> b;

  vi bb;
  while(b > 0) {
    bb.push_back(b%10);
    b /= 10;
  }

  reverse(bb.begin(), bb.end());
  vvl dp1(2, vl(2, 0));
  dp1[0][0] = 1;
  rep(i,sz(bb)) {
    vvl dp2(2, vl(2, 0));
    // 1,0
    dp2[1][0] += dp1[1][0]*8;
    dp2[1][1] += dp1[1][0]*2;
    // 1,1
    dp2[1][1] += dp1[1][1]*10;
    // 0,0
    if(bb[i] == 9) {
      dp2[0][1] += dp1[0][0]; // 9
      dp2[1][0] += dp1[0][0]*8;
      dp2[1][1] += dp1[0][0]; // 4
    }
    if(4 < bb[i] && bb[i] < 9) {
      dp2[0][0] += dp1[0][0]; // bb[i] 
      dp2[1][0] += dp1[0][0]*(bb[i] - 1); 
      dp2[1][1] += dp1[0][0]; // 4      
    }
    if(bb[i] == 4) {
      dp2[0][1] += dp1[0][0]; // 4
      dp2[1][0] += dp1[0][0]*4;
    }
    if(bb[i] < 4) {
      dp2[0][0] += dp1[0][0];
      dp2[1][0] += dp1[0][0]*bb[i];
    }
    // 0,1
    dp2[0][1] += dp1[0][1];
    dp2[1][1] += dp1[0][1]*bb[i];
    swap(dp1, dp2);
  }

  ll bres = dp1[0][1] + dp1[1][1];

  a--;
  vi aa;
  while(a > 0) {
    aa.push_back(a%10);
    a /= 10;
  }

  reverse(aa.begin(), aa.end());
  dp1.assign(2, vl(2, 0));
  dp1[0][0] = 1;
  rep(i,sz(aa)) {
    vvl dp2(2, vl(2, 0));
    // 1,0
    dp2[1][0] += dp1[1][0]*8;
    dp2[1][1] += dp1[1][0]*2;
    // 1,1
    dp2[1][1] += dp1[1][1]*10;
    // 0,0
    if(aa[i] == 9) {
      dp2[0][1] += dp1[0][0]; // 9
      dp2[1][0] += dp1[0][0]*8;
      dp2[1][1] += dp1[0][0]; // 4
    }
    if(4 < aa[i] && aa[i] < 9) {
      dp2[0][0] += dp1[0][0]; // aa[i] 
      dp2[1][0] += dp1[0][0]*(aa[i] - 1); 
      dp2[1][1] += dp1[0][0]; // 4      
    }
    if(aa[i] == 4) {
      dp2[0][1] += dp1[0][0]; // 4
      dp2[1][0] += dp1[0][0]*4;
    }
    if(aa[i] < 4) {
      dp2[0][0] += dp1[0][0];
      dp2[1][0] += dp1[0][0]*aa[i];
    }
    // 0,1
    dp2[0][1] += dp1[0][1];
    dp2[1][1] += dp1[0][1]*aa[i];
    swap(dp1, dp2);
  }

  ll ares = dp1[0][1] + dp1[1][1];
  cout << bres - ares << "\n";
  
  return 0;
}
