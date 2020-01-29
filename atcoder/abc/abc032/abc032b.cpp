#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  map<string,int> mp;
  int cnt=0;
  rep(i,(int)s.size()-k+1){
    string t = s.substr(i,k);
    mp[t]++;
    if(mp[t]==1){
      cnt++;
    }
  }
  cout << cnt << "\n";
  return 0;
}
