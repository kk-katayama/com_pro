#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
vector<bool> func(string a, string b, string c) {
  vector<bool> ab;
  int na = a.size(), nb = b.size(), nc = c.size();
  rep(i,nc+1) ab.push_back(1);
  for(int d = nb-1; d >= 0; --d) {
    bool f = true;
    rep(i,min(nb - d, na)) {
      if(a[i] != b[i+d] && a[i] != '?' && b[i+d] != '?') f = false;
    }
    ab.push_back(f);
  }

  for(int d = 1; d < na; ++d) {
    bool f = true;
    rep(i,min(na - d, nb)) {
      if(a[i+d] != b[i] && a[i+d] != '?' && b[i] != '?') f = false;
    }
    ab.push_back(f);    
  }
  rep(i,nc+1) ab.push_back(1);  
  return ab;
}

int main()
{
  string a,b,c; cin >> a >> b >> c;
  int na = a.size(), nb = b.size(), nc = c.size();
  
  vector<bool> ab = func(a, b, c);
  vector<bool> bc = func(b, c, a);
  vector<bool> ac = func(a, c, b);

  int res = 1e+9;
  rep(i,ab.size()) {
    rep(j,ac.size()) {
      int aloc = 0;
      int bloc = i - nb - nc;
      int cloc = j - nb - nc;
      bool fbc = (0 <= j - i + na + nc && j - i + na + nc < bc.size() ? bc[j - i + na + nc] : 1);
      if(ab[i] && ac[j] && fbc) {
	int maxi = max({na, bloc + nb, cloc + nc});
	int mini = min({aloc, bloc, cloc});
	chmin(res, maxi - mini);
      }
    }
  }

  cout << res << "\n";
  
  return 0;
}
