#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;cin >> n;
  string s;cin >> s;
  string left = s.substr(0, n);
  string right = s.substr(n, n);
  reverse(right.begin(), right.end());

  map<pair<string,string>,ll> mp;
  rep(mask, (1 << n)) {
    string red = "", blue = "";
    rep(i,n) {
      if( (mask >> i) & 1) red += left[i];
      else blue += left[i];
    }
    mp[ {red, blue} ]++;
  }

  ll res = 0;
  rep(mask, (1 << n)) {
    string red = "", blue = "";
    rep(i,n) {
      if( (mask >> i) & 1) red += right[i];
      else blue += right[i];
    }
    res += mp[ {red, blue} ];
  }
  cout << res << "\n";
  
  return 0;
}
