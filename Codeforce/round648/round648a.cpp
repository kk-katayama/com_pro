#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int t; cin >> t;
  vector<string> res;
  while(t-- > 0) {
    int n,m; cin >> n >> m;
    vector<int> row(n, 0), col(m, 0);
    rep(i,n) {
      rep(j,m) {
	int c; cin >> c;
	row[i] += c;
	col[j] += c;
      }
    }
    int cntr = 0, cntc = 0;
    rep(i,n) cntr += (row[i] == 0 ? 1 : 0);
    rep(i,m) cntc += (col[i] == 0 ? 1 : 0);
    if(min(cntr, cntc) % 2 == 0) res.push_back("Vivek");
    else res.push_back("Ashish");
  }

  for(auto s: res) cout << s << "\n";
  return 0;
}
