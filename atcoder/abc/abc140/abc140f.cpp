#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(int &a,int &b){
  return a > b;
}
int main()
{
  int n;cin >> n;
  int m = ( 1 << n );
  vector<int> s(m);
  rep(i,m) cin >> s[i];
  sort(s.begin(), s.end(), comp);
  int jj = 1;
  int com = s[0];
  bool f = true;
  rep(i,n){
    for(int j = 0;j < (1 << (n - 1 - i) );++j){
      if(com <= s[j + jj]){
	f = false;break;
      }
    }
    if(!f) break;
    com = s[(1 << i)];
    jj = ( 1 << (i + 1) );
  }
  if(f) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  
  return 0;
}
