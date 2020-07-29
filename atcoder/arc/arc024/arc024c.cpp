#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,k; cin >> n >> k;
  string s; cin >> s;

  map<vector<int>,int> mp;
  vector<int> a(26, 0);
  vector<int> b(26, 0);  
  rep(i,k-1) {
    int c = s[i] - 'a';
    a[c]++;
  }
  rep(i,k-1) {
    int c = s[i + k] - 'a';
    b[c]++;    
  }
  rep(i,n-2*k+1) {
    int c = s[i+k-1] - 'a';
    a[c]++;
    mp[a]++;
    int cc = s[i+2*k-1] - 'a';
    b[cc]++;
    if(mp[b] > 0) {
      cout << "YES" << "\n";
      return 0;
    }
    int d = s[i] - 'a';
    a[d]--;
    int dd = s[i+k] - 'a';
    b[dd]--;
  }

  // for(auto m: mp) {
  //   for(auto val: m.first) cout << val << " ";
  //   cout << "\n";
  // }
  
  cout << "NO" << "\n";
  
  return 0;
}
