#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n,q; ll t;
  cin >> n >> t >> q;
  vector<ll> a(n);
  vector<int> d(n);
  rep(i,n) cin >> a[i] >> d[i];
  vector<int> x(q);
  rep(i,q) {
    cin >> x[i];
    x[i]--;
  }

  set<ll> st;
  rep(i,n-1) {
    if(d[i] == 1 && d[i+1] == 2) {
      st.insert( (a[i] + a[i+1]) / 2);
    }
  }

  rep(i,q) {
    int index = x[i];
    auto it = st.upper_bound(a[index]);
    if(d[index] == 1) {
      if(it == st.end()) cout << a[index] + t << "\n";
      else cout << (ll)min(a[index] + t, *it) << "\n";
    }
    else {
      if(it == st.begin()) cout << a[index] - t << "\n";
      else {
	it--;
	cout << (ll)max(a[index] - t, *it) << "\n";
      }
    }
  }
  
  return 0;
}
