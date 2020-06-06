#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  vector<string> s(5);
  rep(i,5) cin >> s[i];

  vector<int> res(n+1);
  rep1(j,n) {
    if(s[0][4*j-3] == '.') res[j] = 1;
    else if(s[0][4*j-2] == '.') res[j] = 4;
    else {
      if(s[1][4*j-3] == '.') { // 2,3,7
	if(s[2][4*j-2] == '.') res[j] = 7;
	else {
	  if(s[3][4*j-3] == '.') res[j] = 3;
	  else res[j] = 2;
	}
      }
      else if(s[1][4*j-1] == '.') { // 5,6
	if(s[3][4*j-3] == '.') res[j] = 5;
	else res[j] = 6;
      }
      else { // 0,8,9
	if(s[2][4*j-2] == '.') res[j] = 0;
	else {
	  if(s[3][4*j-3] == '.') res[j] = 9;
	  else res[j] = 8;
	}
      }
    }
  }

  rep1(i,n) cout << res[i];
  cout << "\n";
  
  return 0;
}
