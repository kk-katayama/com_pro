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
  bool f = true;
  rep(i,n){
    if(i&1){
      if(s[i]=='R'){
	f = false;
	break;
      }
    }
    else{
      if(s[i]=='L'){
	f = false;
	break;
      }
    }
  }

  cout << (f?"Yes":"No") << "\n";
  
  
  return 0;
}
