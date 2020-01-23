#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> p(m);
  vector<string> s(m);
  rep(i,m){
    cin >> p[i] >> s[i];
  }

  vector<bool> f(n+1,false);
  vector<int> cnt(n+1,0);
  rep(i,m){
    if(s[i]=="AC"){
      if(!f[p[i]]){
	f[p[i]] = true;
      }
    }
    else{
      if(!f[p[i]]){
	cnt[p[i]]++;
      }
    }
  }

  int ac = 0;
  int wa = 0;
  rep1(i,n){
    if(f[i]){
      ac++;
      wa += cnt[i];
    }
  }
  cout << ac << " ";
  cout << wa << "\n";
  
  
  return 0;
}
