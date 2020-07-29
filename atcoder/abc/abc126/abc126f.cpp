#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,k; cin >> n >> k;
  vector<int> pow2(n+1);
  pow2[0] = 1;
  rep(i,n) pow2[i+1] = pow2[i] * 2;

  if(pow2[n] <= k) {
    cout << -1 << "\n";
  }
  else if(k == 0) {
    rep(i,pow2[n]) {
      cout << i << " ";
      cout << i << " ";      
    }
    cout << "\n";
  }
  else if(n == 1) {
    cout << -1 << "\n";
  }
  else {
    rep(i,pow2[n]) {
      if(i == k) continue;
      cout << i << " ";
    }
    cout << 0 << " ";
    cout << k << " ";    
    rep(i,pow2[n] - 1) {
      if(pow2[n] - i - 1== k) continue;
      cout << pow2[n] - i - 1 << " ";
    }
    cout << k << "\n";
  }
  
  return 0;
}
