#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }

  int rcnt=0,bcnt=0;
  rep(i,n){
    rep(j,s[i].size()){
      if(s[i][j]=='R') rcnt++;
      else if(s[i][j]=='B') bcnt++;
    }
  }
  if(rcnt>bcnt) cout << "TAKAHASHI" << "\n";
  else if(rcnt<bcnt) cout << "AOKI" << "\n";
  else cout << "DRAW" << "\n";
  return 0;
}
