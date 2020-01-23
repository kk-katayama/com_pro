#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  if(n==1&&k!=0){
    cout << 0 << "\n";
    return 0;
  }
  rep(i,n){
    if(k==0) break;
    if(i==0){
      if(s[i]!='1'){
	s[i]='1';
	--k;
      }
    }
    else{
      if(s[i]!='0'){
	s[i]='0';
	--k;
      }
    }

  }

  cout << s << "\n";
  return 0;
}
