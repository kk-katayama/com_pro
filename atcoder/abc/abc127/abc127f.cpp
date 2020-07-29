#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
int main()
{
  int q; cin >> q;
  vector<int> f(q);
  vector<ll> a(q),b(q);
  rep(i,q) {
    cin >> f[i];
    if(f[i] == 1) cin >> a[i] >> b[i];
  }

  multiset<pl> st;
  ll lsize = 0, rsize = 0;
  ll size = 0;
  ll piv,idx;
  ll sum = 0, lsum = 0, rsum = 0;
  rep(i,q) {
    if(f[i] == 1) {
      sum += b[i];
      if(size == 0) {
	size++;
	piv = a[i];
	idx = i;
	st.insert({a[i], i});
      }
      else if(piv <= a[i]) {
	if(size % 2 == 0) {
	  st.insert({a[i], i}); size++;
	  auto it = st.find({piv, idx});
	  it++;
	  lsum += piv; lsize++;
	  rsum += a[i] - (*it).first;
	  piv = (*it).first; idx = (*it).second;
	}
	else {
	  st.insert({a[i], i}); size++;
	  rsum += a[i]; rsize++;
	}
      }
      else {
	if(size % 2 == 0) {
	  st.insert({a[i], i}); size++;
	  lsum += a[i]; lsize++;	  
	}
	else {
	  st.insert({a[i], i}); size++;	  
	  auto it = st.find({piv, idx});
	  it--;
	  rsum += piv; rsize++;
	  lsum += a[i] - (*it).first;	  
	  piv = (*it).first; idx = (*it).second;	  
	}
      }
    }
    else {
      ll res = sum + piv*lsize - lsum + rsum - piv*rsize;
      cout << piv << " ";
      cout << res << "\n";      
    }
  }
  
  return 0;
}
