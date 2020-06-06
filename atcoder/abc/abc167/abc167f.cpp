#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n;cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  
  using pi = pair<int,int>;
  vector<pi> up, down;
  rep(i,n) {
    int a = 0;
    int b = 0;
    int m = s[i].size();
    rep(j,m) {
      if(s[i][j] == '(') a++;
      else a--;
      chmin(b, a);
    }
    if(a >= 0) up.emplace_back(a, b);
    else {
      a = 0;
      b = 0;
      rep(j,m) {
	if(s[i][m-1-j] == ')') a++;
	else a--;
	chmin(b, a);
      }
      down.emplace_back(a, b);
    }
  }
  sort(up.begin(), up.end(), [](pi a, pi b) {
			       return a.second > b.second;
			     });

  sort(down.begin(), down.end(), [](pi a, pi b) {
			       return a.second > b.second;
			     });  
  
  int nowup = 0;
  for(auto p: up) {
    if(nowup + p.second < 0) {
      cout << "No" << "\n";
      return 0;
    }
    else nowup += p.first;
  }

  int nowdo = 0;
  for(auto p: down) {
    if(nowdo + p.second < 0) {
      cout << "No" << "\n";
      return 0;
    }
    else nowdo += p.first;
  }  

  if(nowup == nowdo) cout << "Yes" << "\n";
  else cout << "No" << "\n";

  return 0;
}
