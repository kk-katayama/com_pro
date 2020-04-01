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
  int n = s.size();
  string t = s.substr(0,( n - 1 ) / 2 );
  string u = s.substr(( n + 1 ) / 2 , ( n - 1 ) / 2 );

  string sr = s, tr = t, ur = u;
  reverse(sr.begin(), sr.end());
  reverse(tr.begin(), tr.end());
  reverse(ur.begin(), ur.end());  

  if(s == sr && t == tr && u == ur) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
