#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
// 座圧.配列aを入れると、0-indexedで座圧した配列を返す.同じ要素は同じ数に圧縮される.
vector<int> compress(vector<int> a) {
  int n = a.size();
  vector<int> vals;
  rep(i,n) vals.push_back(a[i]);

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  vector<int> res;
  rep(i,n) {
    int id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    // id + 1にすれば1-indexedになる
    res.push_back(id);
  }

  return res;
}

int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  vector<int> res = compress(a);
  rep(i,n) cout << res[i] << " ";
  cout << "\n";
  return 0;
}
