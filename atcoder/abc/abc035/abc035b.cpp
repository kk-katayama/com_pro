#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;
  cin >> s;
  int t;
  cin >> t;
  map<char,int> mp;
  rep(i,s.size()){
    mp[s[i]]++;
  }
  int ud = abs(mp['U']-mp['D']);
  int lr = abs(mp['L']-mp['R']);
  int x = ud + lr;
  if(t==1){
    cout << x + mp['?'] << "\n";
  }
  else{
    if(x>=mp['?']){
      cout << x-mp['?'] << "\n";
    }
    else{
      cout << (int)(mp['?']-x)%2 << "\n";
    }
  }
  return 0;
}
