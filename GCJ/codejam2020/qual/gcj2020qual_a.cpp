#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool check(vector<int> a) {
  sort(a.begin(), a.end());
  bool f = true;
  rep(i,a.size()-1) {
    if(a[i] == a[i+1]) f = false;
  }
  return f;
}
int main()
{
  int t;cin >> t;
  vector<int> n(t);
  vector<vector<vector<int>>> m(t);
  rep(i,t) {
    cin >> n[i];
    m[i].resize(n[i], vector<int>(n[i]));
    rep(j, n[i]) rep(k, n[i]) cin >> m[i][j][k];
  }

  rep(i,t) {
    int k = 0, r = 0, c = 0;
    rep(j,n[i]) k += m[i][j][j];
    rep(j,n[i]) if( !check(m[i][j]) ) r++;
    rep(l,n[i]) {
      vector<int> v(n[i]);
      rep(j,n[i]) {
	v[j] = m[i][j][l];
      }
      if( !check(v) ) c++;
    }
    cout << "Case #" << i+1 << ": ";
    cout << k << " " << r << " " << c << "\n";
  }
  return 0;
}
