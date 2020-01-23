#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int T;
  cin >> T;
  vector<int> n(T);
  vector<vector<int>> a(T);
  rep(i,T){
    cin >> n[i];
    a[i].resize(n[i]);
    rep(j,n[i]){
      cin >> a[i][j];
    }
  }

  rep(i,T){
    int res = 1e+6;
    set<int> st;
    map<int,int> mp;
    rep(j,n[i]){
      if(st.count(a[i][j])==1){
	int d = j-mp[a[i][j]]+1;
	res = min(res,d);
	mp[a[i][j]]=j;
      }
      else{
	st.insert(a[i][j]);
	mp[a[i][j]]=j;
      }
    }
    if(res!=1e+6) cout << res << "\n";
    else cout << -1 << "\n";
  }
  
  return 0;
}
