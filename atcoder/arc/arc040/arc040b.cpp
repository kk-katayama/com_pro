#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,r;
  cin >> n >> r;
  string s;
  cin >> s;

  int t=0;
  rep(i,n){
    if(s[i]=='.'){
      rep(j,r){
	if(i+j>=n){
	  break;
	}
	s[i+j]='o';
      }
      t++;
    }
    bool f=true;
    rep(k,n){
      if(s[k]=='.'){
	f=false;
	break;
      } 
    }
    if(f) break;
    t++;
  }

  cout << t << "\n";
  return 0;
}
