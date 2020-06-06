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
  rep1(i,1000) {
    rep1(j,1000) {
      if(i >= j) continue;
      int k = 1000 - i - j;
      if(j >= k) continue;
      if(i*i + j*j == k*k) {
	cout << i*j*k << "\n";
	return 0;
      }
    }
  }
  return 0;
}
