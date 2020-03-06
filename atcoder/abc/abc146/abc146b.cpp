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
  rep(i,s.size()){
    int x = s[i]-'A';
    x = (x+n)%26;
    char c = 'A'+x;
    s[i] = c;
  }
  cout << s << "\n";
  return 0;
}
