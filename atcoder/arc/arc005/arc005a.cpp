#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  vector<string> s(n);
  rep(i,n) {
    cin >> s[i];
  }

  s[n-1].pop_back();
  
  int res = 0;
  rep(i,n) {
    if(s[i] == "TAKAHASHIKUN" || s[i] == "Takahashikun" || s[i] == "takahashikun") res++;
  }
  cout << res << "\n";
  return 0;
}
