#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;
  cin >> s;
  int x = s[0];
  if('a'<=x&&x<='z'){
    char c = s[0] - 32;
    s[0] = c;
  }
  rep1(i,s.size()-1){
    int y = s[i];
    if('A'<=y&&y<='Z'){
      s[i] = s[i] + 32;
    }
  }

  cout << s << "\n";
  return 0;
}
