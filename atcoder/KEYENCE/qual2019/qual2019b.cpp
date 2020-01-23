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
  string k = "keyence";
  int cnt1 = 0;
  rep(i,k.size()){
    if(s[i]==k[i]){
      cnt1++;
    }
    else{
      break;
    }
  }

  int cnt2 = 0;
  rep(i,k.size()){
    if(s[s.size()-1-i]==k[k.size()-1-i]){
      cnt2++;
    }
    else{
      break;
    }
  }  

  if(cnt1+cnt2>=(int)k.size()){
    cout << "YES" << "\n";
  }
  else {
    cout << "NO" << "\n";
  }

  
  return 0;
}
