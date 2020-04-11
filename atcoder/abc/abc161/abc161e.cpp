#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k,c;cin >> n >> k >> c;
  string s;cin >> s;
  int x = 0;
  vector<int> v;
  rep(i,n) {
    if(s[i] == 'o') {
      v.push_back(i);
      x++;
      i += c;
    }
  }
  if(x > k) {
    cout << "\n";
    return 0;
  }

  int j = v.size() - 1;
  vector<int> res;
  for(int i = n - 1;i >= 0;--i) {
    if(s[i] == 'o') {
      if(v[j] == i) res.push_back(i);
      j--;
      i -= c;
    }
  }

  reverse(res.begin(), res.end());
  rep(i,res.size()) cout << res[i]+1 << "\n";
  
  return 0;
}
