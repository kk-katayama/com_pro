#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  set<int> st;
  for (int j = 2; j <= 150; ++j) {
    st.insert(j*j);
  }
  map<int,int> mp;
  for (int j = 2; j <= 150; ++j) {
    mp[j*j] = j;
  }  
  rep1(i,n) {
    int res = 0;
    for (int j = 2; j <= 150; ++j) {
      for (int k = 2; k <= 150; ++k) {
	int l = 2*i - j*j - k*k;
	if(l <= 0) continue;
	if(st.find(l) == st.end()) continue;
	l = mp[l];
	if(j + k - l > 0 && (j + k - l) % 2 == 0) {
	  if(j - k + l > 0 && (j - k + l) % 2 == 0) {
	    if(-j + k + l > 0 && (-j + k + l) % 2 == 0) {
	      res++;
	    }
	  }
	}
      }
    }
    cout << res << "\n";
  }
  return 0;
}
