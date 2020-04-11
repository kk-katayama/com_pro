#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k,q;cin >> n >> k >> q;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> b = a;
  sort(b.begin(), b.end());
  
  int res = 1e+9;
  
  rep(i,n) {
    int sum = 0;
    int cnt = 0;
    int piv = a[i];
    int x = 0;
    vector<int> v;
    vector<int> w;
    rep(j,n) {
      if(i == j) continue;
      if(piv > a[j]) {
	int tmp = max(0, cnt - k + 1);
	sort(v.begin(), v.end());
	cnt = 0;
	rep(l,tmp) w.push_back(v[l]);
	sum += tmp;
	v.clear();
      }
      else {
	v.push_back(a[j]);
	cnt++;
      }
    }
    int tmp = max(0, cnt - k + 1);
    sort(v.begin(), v.end());
    rep(l,tmp) w.push_back(v[l]);
    sum += tmp;

    if(q - 1 <= sum) res = min(res, w[q-2] - piv );
  }

  cout << res << "\n";
  
  return 0;
}
