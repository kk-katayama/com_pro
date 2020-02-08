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
  if(s[s.size()-1]=='T'){
    cout << "YES" << "\n";
  }
  else{
    cout << "NO" << "\n";
  }
  return 0;
}
