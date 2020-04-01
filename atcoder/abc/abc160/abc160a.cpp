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
  if(s[2] == s[3] && s[4] == s[5]) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
