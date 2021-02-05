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
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
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
  vi a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  
  int l = -inf, r = inf;
  vector<pi> p = rle(b);
  int id = 0;
  for(auto val: p) {
    auto [num, siz] = val;
    int lb = -1, ub = n;
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (a[mid] <= num ? lb : ub) = mid;
    }
    int usiro = lb;
    lb = -1; ub = n;
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (a[mid] >= num ? ub : lb) = mid;
    }
    int mae = ub + n;
    // cout << mae << "\n";
    //    cout << usiro - id + 1 << ":" << mae - (id + siz) << "\n";    
    chmax(l, usiro - id + 1);
    chmin(r, mae - (id + siz));
    id += siz;
  }

  //  cout << l << ":" << r << "\n";  
  if(l > r) cout << "No" << "\n";
  else {
    cout << "Yes" << "\n";
    rep(i,n) {
      cout << b[(i-l+2*n) % n] << " ";
    }
    cout << "\n";
  }
  
  return 0;
}
