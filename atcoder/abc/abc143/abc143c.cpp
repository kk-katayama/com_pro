#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  string s;cin >> s;
  int res = 1;
  rep(i,n-1){
    if(s[i] != s[i+1]) res++;
  }
  cout << res << "\n";
  return 0;
}
