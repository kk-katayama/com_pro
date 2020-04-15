#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;cin >> n;
  string s;cin >> s;

  vector<int> r, g;
  ll b = 0;
  rep(i,n) {
    if(s[i] == 'R') r.push_back(i+1);
    else if(s[i] == 'G') g.push_back(i+1);
    else b++;
  }

  ll res = 0;
  rep(i,r.size() ) {
    rep(j,g.size()) {
      int rr = r[i];
      int gg = g[j];
      ll bb = b;
      if(rr < gg) {
	int index;
	if( (rr + gg) % 2 == 0) {	
	  index = (rr + gg) / 2;	
	  if(rr < index && index < gg) {
	    if(s[index-1] == 'B') bb--;
	  }
	}
	index = 2*gg - rr;
	if(gg < index && index <= n) {
	  if(s[index-1] == 'B') bb--;
	}
	index = 2*rr - gg;	
	if(1 <= index && index < gg) {
	  if(s[index-1] == 'B') bb--;
	}	
      }
      else {
	int index;
	if( (rr + gg) % 2 == 0) {	
	  index = (rr + gg) / 2;	
	  if(gg < index && index < rr) {
	    if(s[index-1] == 'B') bb--;
	  }
	}
	index = 2*rr - gg;
	if(rr < index && index <= n) {
	  if(s[index-1] == 'B') bb--;
	}
	index = 2*gg - rr;	
	if(1 <= index && index < rr) {
	  if(s[index-1] == 'B') bb--;
	}	
      }
      res += max((ll)0,bb);      
    }
  }
  cout << res << "\n";
  return 0;
}
