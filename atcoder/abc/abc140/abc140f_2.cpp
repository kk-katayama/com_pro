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
#define sz(v) (int)v.size()
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// ランレングス圧縮.配列の連続している要素をまとめてしまう圧縮.
vector<pair<int,int>> rle(vector<int> a){
  vector<pair<int,int>> res;
  int n = a.size();
  int cnt = 1;
  pair<int,int> p;
  p.first = a[0];
  rep(i,n-1){
    if(a[i]==a[i+1]){
      cnt++;
    }
    else{
      p.second = cnt;
      res.push_back(p);
      cnt = 1;
      p.first = a[i+1];
    }
  }
  p.second = cnt;
  res.push_back(p);
  return res;
}

int main()
{
  int n; cin >> n;
  vi a((1 << n));
  rep(i,(1<<n)) {
    cin >> a[i];
  }

  sort(a.begin(), a.end(), [](int a, int b){
			     return a > b;
			   });

  vector<pi> p = rle(a);
  
  priority_queue<int> q;
  q.push((1<<(n+1))-1);
  rep(i,sz(p)) {
    int x = p[i].second;
    if(q.size() < x) {
      cout << "No" << "\n";
      return 0;
    }
    vi tmp;
    while(x-- > 0) {
      tmp.push_back(q.top()); q.pop();
    }
    for(auto val: tmp) {
      while(val/2 > 0) {
	q.push(val/2);
	val /= 2;
      }
    }
  }

  cout << "Yes" << "\n";
  
  return 0;
}
