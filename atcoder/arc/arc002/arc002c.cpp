#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<string> com = {
			"AA","AB","AX","AY","BA","BB","BX","BY",
			"XA","XB","XX","XY","YA","YB","YX","YY"
  };

  int res =n;
  rep(i,16){
    rep(j,16){
      if(i>=j) continue;
      int cnt=0;
      rep(k,n){
	if(k==n-1){
	  cnt++;
	  break;
	}
	if(s[k]==com[i][0]&&s[k+1]==com[i][1]){
	  cnt++;
	  k++;
	}
	else if(s[k]==com[j][0]&&s[k+1]==com[j][1]){
	  cnt++;
	  k++;
	}
	else {
	  cnt++;
	}
      }
      res = min(res,cnt);
    }
  }

  cout << res << "\n";
  
  return 0;
}
