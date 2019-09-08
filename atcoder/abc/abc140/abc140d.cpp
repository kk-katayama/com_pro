#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n,k;
string s;
int main()
{
  cin >> n >> k;
  cin >> s;
  bool lr = false,rl = false;
  int cnt = 0,xx = 0;  
  rep(i,n-1){
    if(s[i]=='L'&&s[i+1]=='R'){
      if(rl){
	cnt++;
	rl = false;
      }
      else lr = true;
    }
    if(s[i]=='R'&&s[i+1]=='L'){    
      if(lr){
	cnt++;
	lr = false;
      }
      else rl = true;
    }
    if(s[i]=='R'&&s[i+1]=='R'){
      xx++;
    }
    if(s[i]=='L'&&s[i+1]=='L'){
      xx++;
    }
  }
  int c=0;
  if(lr||rl) c=1;
  int a;
  if(k>cnt) a=cnt*2+xx+1;
  else a=k*2+xx;
  int res = min(n-1,a);
  cout << res << "\n";
  
  return 0;
}
