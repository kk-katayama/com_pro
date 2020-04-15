#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;cin >> s;
  bool f = true;
  rep(i,3) {
    if(s[i] == '7') f = false;
  }

  if(f) cout << "No" << "\n";
  else cout << "Yes" << "\n";
  return 0;
}
