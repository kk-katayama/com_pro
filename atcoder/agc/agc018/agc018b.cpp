#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<queue<int>> q(n);
  rep(i,n){
    rep(j,m){
      int a;
      cin >> a;
      q[i].push(a);
    }
  }
  
  int res=400;
  set<int> st;
  rep(I,m){
    map<int,int> mp;
    rep(i,n){
      while(st.find(q[i].front())!=st.end()){
	q[i].pop();
      }
      mp[q[i].front()]++;
    }
    int mx=0;
    int nax;
    for(auto it=mp.begin();it!=mp.end();++it){
      if(mx<it->second){
	mx = it->second;
	nax = it->first;
      }
    }
    res = min(res,mx);
    st.insert(nax);

  }
  cout << res << "\n";
  return 0;
}
