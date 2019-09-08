#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<int> p(n);  
  rep(i,n) {
    cin >> p[i];
    p[i]--;
  }
  map<int,ll> mp;
  rep(i,n) mp[p[i]] = (ll)i;
  set<ll> st;
  
  ll res = 0;
  for(int i=n-1;i>=0;--i){
    ll index = mp[i];
    st.insert(index);
    vector<ll> l(2,-1);
    vector<ll> r(2,n);
    {
      auto itr = st.find(index);
      rep(j,2){
	if(itr == st.begin()) break;
	--itr;
	l[j] = *itr;
      }
    }
    {
      auto itr = st.find(index);
      rep(j,2){
	++itr;	
	if(itr == st.end()) break;
	r[j] = *itr;
      }      
    }
    ll c = (r[1]-r[0])*(index-l[0])+(r[0]-index)*(l[0]-l[1]);
    res += c*((ll)i+1);
  }
  
  cout << res << "\n";
  
  return 0;
}
