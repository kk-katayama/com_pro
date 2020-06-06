#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  string s; cin >> s;
  int n = s.size();
  
  vector<set<int>> st(26);
  rep(i,n) {
    int idx = s[i] - 'a';
    st[idx].insert(i);
  }

  using pi = pair<int,int>;
  using psi = pair<char,pi>;
  queue<psi> q;
  int num = 0;
  q.push({' ', {-1, 0}});
  while( !q.empty() ) {
    psi p = q.front(); q.pop();
    num++;
    char tmp = p.first;
    int piv = p.second.first;
    int cnt = p.second.second;
    for(int i = 0;i < 26; ++i) {
      char c = 'a' + i;
      auto it = st[i].upper_bound(piv);
      if(it != st[i].end() ) {
  	q.push({c, {*it, cnt+1}});
      }
      else {
	cout << num << "\n";
  	rep(j,cnt-1) cout << 'a';
  	cout << tmp;
  	cout << c << "\n";
  	return 0;
      }
    }
  }
  
  return 0;
}
