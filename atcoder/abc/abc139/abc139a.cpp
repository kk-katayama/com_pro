#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
string s,t;
int main()
{
  cin >> s >> t;
  int res = 0;
  rep(i,3){
    if(s[i]==t[i]) res++;
  }
  cout << res << "\n";
  return 0;
}
