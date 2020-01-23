#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int t;
  cin >> t;
  vector<int> n(t);
  vector<string> s(t);

  rep(i,t){
    cin >> n[i];
    cin >> s[i];
  }

  rep(i,t){
    int res = 0;
    bool f = true;
    int low = 0;
    int high = 0;
    rep(j,s[i].size()){
      if(s[i][j]=='1'){
	if(f){
	  low = j+1;
	  high = s[i].size()-j;
	  f = false;
	}
	high = s[i].size()-j;
      }
      res = max(res,max(low,high)*2);
    }
    res = max(res,(int)s[i].size());
    cout << res << "\n";
  }

  
  return 0;
}
