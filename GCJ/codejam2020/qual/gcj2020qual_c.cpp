#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int t;cin >> t;
  vector<int> n(t);
  vector<vector<pair<int,int>>> p(t);
  rep(i,t) {
    cin >> n[i];
    if(n[i] > 10) return 0;
    p[i].resize(n[i]);
    rep(j,n[i]) {
      int s, e;
      cin >> s >> e;
      p[i][j] = {s, e};
    }
  }

  rep(i,t) {
    bool ff = false;
    rep(mask, (1<<n[i]) ) {
      vector<pair<int,int>> v ,w;
      rep(j,n[i]) {
	if( (mask >> j) & 1) v.push_back(p[i][j]);
	else w.push_back(p[i][j]);	
      }
      sort(v.begin(), v.end());
      sort(w.begin(), w.end());
      bool f = true;
      if(v.size() >= 2) {
	rep(a, v.size()-1) {
	  if(v[a].second > v[a+1].first) f = false; 
	}
      }
      if(w.size() >= 2) {      
	rep(a, w.size()-1) {
	  if(w[a].second > w[a+1].first) f = false; 
	}
      }
      if(f) {
	ff = true;
	cout << "Case #" << i + 1 << ": ";
	rep(j,n[i]) {
	  if( (mask >> j) & 1) cout << 'C';
	  else cout << 'J';
	}
	cout << "\n";
	break;
      }
    }
    if(!ff) {
      cout << "Case #" << i + 1 << ": ";
      cout << "IMPOSSIBLE" << "\n";
    }
  }
    
  return 0;
}
