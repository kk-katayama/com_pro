#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string t = "CODEFESTIVAL2016";
  string s;
  cin >> s;
  int cnt = 0;
  rep(i,s.size()){
    if(t[i]!=s[i]) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}
