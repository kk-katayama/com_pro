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
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  map<int,int> mp;
  rep(i,n) {
    mp[a[i]]++;
  }
  int m8 = 0, m6 = 0, m4 = 0, m2 = 0, ot = 0;
  for(auto val:mp) {
    if(val.second >= 8) m8++;    
    else if(val.second >= 6) m6++;
    else if(val.second >= 4) m4++;
    else if(val.second >= 2) m2++;
    else ot++;
  }
  
  int q; cin >> q;
  while(q-- > 0) {
    char c;
    int x;
    cin >> c >> x;
    if(c == '+') {
      mp[x]++;
      if(mp[x] == 8) {
	m6--;
	m8++;
      }      
      else if(mp[x] == 6) {
	m4--;
	m6++;
      }
      else if(mp[x] == 4) {
	m2--;
	m4++;
      }
      else if(mp[x] == 2) {
	ot--;
	m2++;
      }
      else if(mp[x] == 1) ot++;
    }
    else {
      mp[x]--;
      if(mp[x] == 7) {
	m8--;
	m6++;
      }      
      else if(mp[x] == 5) {
	m6--;
	m4++;
      }
      else if(mp[x] == 3) {
	m4--;
	m2++;
      }
      else if(mp[x] == 1) {
	m2--;
	ot++;
      }
      else if(mp[x] == 0) ot--;
    }
    if(m8 >= 1) cout << "YES" << "\n";
    else if(m6 >= 2) cout << "YES" << "\n";
    else if(m6 == 1 && (m4 >= 1 || m2 >= 1)) cout << "YES" << "\n";
    else if(m4 >= 2) cout << "YES" << "\n";
    else if(m4 == 1 && m2 >= 2)  cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
  return 0;
}
