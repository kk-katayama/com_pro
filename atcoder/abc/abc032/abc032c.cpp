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
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) {
    cin >> a[i];
  }
  rep(i,n) {
    if(a[i] == 0) {
      cout << n << "\n";
      return 0;
    }
  }

  int right = 0;
  ll sum = 1;
  int res = 0;
  rep(left,n) {
    while(right < n && sum * a[right] <= k) {
      sum *= a[right];
      right++;
    }

    chmax(res, right - left);
    if(right == left) right++;
    else sum /= a[left];
  }
  cout << res << "\n";
  return 0;
}
