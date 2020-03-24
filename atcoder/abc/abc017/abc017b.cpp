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
  bool f = true;
  rep(i,n){
    if(s[i] == 'o' || s[i] == 'k' || s[i] == 'u') continue;
    else if(s[i] == 'c'){
      if(i+1 >= n){f = false;break;}
      else if(s[i+1] == 'h'){i++;continue;}
      else{f = false;break;}
    }
    else{f = false;break;}
  }
  if(f) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}
