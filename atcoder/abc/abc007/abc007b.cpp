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
  if(s.size()>=2){
    rep(i,s.size()-1){
      cout << s[i];
    }
    cout  << "\n";
  }
  else if(s[0]=='a'){
    cout << -1 << "\n";
  }
  else{
    char c = s[0] - 1;
    cout << c << "\n";
  }

  return 0;
}
