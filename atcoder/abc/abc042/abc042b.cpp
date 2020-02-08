#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,l;
  cin >> n >> l;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }

  sort(s.begin(), s.end());
  string res = "";
  rep(i,n){
    res += s[i];
  }
  cout << res << "\n";
  return 0;
}
