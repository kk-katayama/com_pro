#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;
  cin >> s;
  int n = s.size();
  
  if(n&1){
    if(s[0]==s[n-1]) cout << "Second" << "\n";
    else cout << "First" << "\n";
  }
  else{
    if(s[0]==s[n-1]) cout << "First" << "\n";
    else cout << "Second" << "\n";
  }
  return 0;
}
