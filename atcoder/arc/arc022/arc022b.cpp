#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int s=0,t=1;
  set<int> st;
  int res=0;
  st.insert(a[0]);
  while(t!=n){
    // for(auto it=st.begin();it!=st.end();++it) cout << *it << " ";
    // cout  << "\n";
    if(st.find(a[t])==st.end()){
      st.insert(a[t]);
      t++;
    }
    else{
      res = max(res,t-s);
      while(a[s]!=a[t]){
	st.erase(a[s]);
	s++;
      }
      st.erase(a[s]);
      s++;
    }
  }

  res = max(res,t-s);
  cout << res << "\n";
  
  return 0;
}
