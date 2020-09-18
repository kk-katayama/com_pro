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
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
//**********************************************************************************
// KMP法、文字列sの中から文字列tと一致する部分があるかを判定。あるならその文字列が始まる位置を返す
vector<int> table;
void kmp_table(string t){
  int ts = t.size();
  table.resize(ts+1);
  table[0] = -1;
  int j = -1;
  rep(i,ts){
    while(j>=0&&t[i]!=t[j]) j = table[j];
    j++;
    table[i+1] = j;
  }
}

vector<int> kmp(string s,string t){
  vector<int> res;
  kmp_table(t);
  int ss = s.size(),ts = t.size();
  bool f = false;
  int i = 0,j = 0;
  while(i<ss){
    while(s[i]==t[j]){
      i++;j++;
      if(j==ts){
	f = true;
	res.push_back(i-j);
	break;
      }
      if(i==ss) break;
    }
    if(j==0) i++;
    else j = table[j];
  }
  return res;
}
//*************************************************************************************

int main()
{
  int n; cin >> n;
  string s; cin >> s;
  vector<string> t(n);
  rep(i,n) cin >> t[i];

  int ns = s.size();
  vii pat(ns+1);
  rep(i,n) {
    int nt = t[i].size();
    vi tmp = kmp(s, t[i]);
    for(auto val: tmp) {
      pat[val].push_back(val + nt);
    }
  }
  ll MOD = 1e+9+7;
  vector<ll> dp(ns+1, 0);
  dp[0] = 1;
  rep(i,ns) {
    for(auto val: pat[i]) {
      dp[val] = (dp[val] + dp[i]) % MOD;
    }
  }
  cout << dp[ns] << "\n";
  
  return 0;
}
