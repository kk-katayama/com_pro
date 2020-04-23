#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n;cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  vector<char> head = {'M', 'A', 'R', 'C', 'H'};
  vector<ll> cnt(5,0);
  rep(i,n) {
    rep(j,5) {
      if(s[i][0] == head[j]) {
	cnt[j]++;
      }
    }
  }

  ll res = 0;
  for(int i = 0;i < 5;++i) {
    for(int j = i+1; j < 5; ++j) {
      for(int k = j+1; k < 5;++k) {
	res += cnt[i] * cnt[j] * cnt[k];
      }
    }
  }
  cout << res << "\n";
  
  return 0;
}
