#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
using ll = long long;

// ランレングス圧縮.配列の連続している要素をまとめてしまう圧縮.
vector<pair<ll,int>> rle(vector<ll> a){
  vector<pair<ll,int>> res;
  int n = a.size();
  int cnt = 1;
  pair<ll,int> p;
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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<pair<ll,int>> rl = rle(a);

  for(auto val: rl) {
    auto [a, b] = val;
    cout << a << ":" << b << "\n";
  }
  
  return 0;
}
