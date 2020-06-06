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
  rep(i,n) cin >> a[i];

  vector<double> cnt(3, 0);
  rep(i,n) cnt[a[i] - 1]++;

  
  auto rec = [&](auto f, double i, double j, double k)-> double{
	       double res = 0;
	       res += i / (i+j+k) * f(f, i-1, j, k);
	       res += 
	     };

  
  return 0;
}
