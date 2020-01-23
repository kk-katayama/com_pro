#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  int r,s,p;
  cin >> r >> s >> p;
  string t;
  cin >> t;

  vector<char> ss(n);
  rep(i,n){
    if(t[i]=='r'){
      ss[i] = 'p';
    }
    else if(t[i]=='s'){
      ss[i] = 'r';
    }
    else{
      ss[i] = 's';
    }
  }

  map<char,int> mp;
  mp['r'] = r;
  mp['s'] = s;
  mp['p'] = p;
  int res = 0;
  rep(i,n){
    if(i-k>=0){
      if(ss[i]!=ss[i-k]){
	res += mp[ss[i]];
      }
      else{
	ss[i] = '.';
      }
    }
    else{
      res += mp[ss[i]];
    }
  }
  cout << res << "\n";
  return 0;
}
