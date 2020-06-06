#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n;cin >> n;
  string s, t;
  cin >> s >> t;

  auto isnum = [](int a)-> bool{ return (0 <= a && a <= 9); };

  vector<bool> c(26, true);
  rep(j,n) {
    rep(i,n) {
      int ss = s[i] - '0';
      int tt = t[i] - '0';
      int xs = s[i] - 'A';
      int xt = t[i] - 'A';
      if(isnum(ss) && !isnum(tt)) {
	c[xt] = false;
      }
      else if(!isnum(ss) && isnum(tt) ) {
	c[xs] = false;
      }
      else if(!isnum(ss) && !isnum(tt) ) {
	if(c[xs] && !c[xt]) {
	  c[xs] = false;
	}
	else if(!c[xs] && c[xt]) {
	  c[xt] = false;
	}
      }
    }
  }

  ll res = 1;
  rep(i,n) {
    int ss = s[i] - '0';
    int tt = t[i] - '0';    
    int xs = s[i] - 'A';
    int xt = t[i] - 'A';
    if(!isnum(ss) && !isnum(tt) ) {
      if(c[xs] && c[xt]) {
	if(i == 0) res *= 9;
	else res *= 10;
	c[xs] = false;
	c[xt] = false;
      }
    }    
  }


  cout << res << "\n";
  return 0;
}
