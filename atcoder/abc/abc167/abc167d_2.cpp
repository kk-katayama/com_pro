#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n; cin >> n;
  ll k; cin >> k;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
    a[i]--;
  }

  int s = 0;
  while(k > 0) {
    if(k & 1) s = a[s];
    vector<int> na(n);
    rep(i,n) {
      na[i] = a[a[i]];
    }
    a = na;
    k >>= 1;
  }
  
  cout << s+1 << "\n";
  
  return 0;
}
