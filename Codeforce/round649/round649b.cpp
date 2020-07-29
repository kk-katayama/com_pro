#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int t; cin >> t;
  vector<vector<int>> res(t);
  int cnt = 0;
  while(t-- > 0) {
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    
    bool f = (p[0] < p[1]);
    res[cnt].push_back(p[0]);    
    rep1(i,n-2) {
      if(f) {
	if(p[i] > p[i+1]) {
	  res[cnt].push_back(p[i]);
	  f = false;
	}
      }
      else {
	if(p[i] < p[i+1]) {
	  res[cnt].push_back(p[i]);
	  f = true;
	}	
      }
    }
    res[cnt].push_back(p[n-1]);    
    cnt++;
  }

  for(auto vec: res) {
    cout << (int)vec.size() << "\n";
    for(auto val: vec) cout << val << " ";
    cout  << "\n";
  }
  
  return 0;
}
