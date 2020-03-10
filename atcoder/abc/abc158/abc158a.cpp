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
  if(s[0]==s[1]&&s[1]==s[2]) cout << "No" << "\n";
  else cout << "Yes" << "\n";
  return 0;
}
