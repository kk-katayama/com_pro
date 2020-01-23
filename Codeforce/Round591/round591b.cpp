#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int q;
  cin >> q;
  vector<string> s(q),t(q);
  rep(i,q) cin >> s[i] >> t[i];

  rep(i,q){
    vector<bool> sc(26,false),tc(26,false);
    for(auto& c:s[i]){
      sc[(int)c-'a']=true;
    }
    for(auto& c:t[i]){
      tc[(int)c-'a']=true;
    }
    bool f=false;
    rep(j,26){
      if(sc[j]&&tc[j]){
	f=true;
	break;
      }
    }
    if(f) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
  return 0;
}
