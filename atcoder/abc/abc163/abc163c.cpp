#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n-1) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> res(n);
  rep(i,n-1) res[a[i]]++;

  rep(i,n) cout << res[i] << "\n";

  
  return 0;
}
