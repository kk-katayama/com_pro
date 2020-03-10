#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int cnt = 0;
  vector<string> s(12);
  rep(i,12) cin >> s[i];
  rep(i,12){
    bool f = false;
    rep(j,s[i].size()) if(s[i][j]=='r') f = true;
    if(f) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}
