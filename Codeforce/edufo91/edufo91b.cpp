#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int n; cin >> n;
  while(n-- > 0) {
    string s; cin >> s;
    int R = count(s.begin(), s.end(), 'R');
    int S = count(s.begin(), s.end(), 'S');
    int P = count(s.begin(), s.end(), 'P');
    if(S <= R && P <= R) {
      rep(i,s.size()) cout << 'P';
      cout << "\n";
    }
    else if(R <= S && P <= S) {
      rep(i,s.size()) cout << 'R';
      cout << "\n";
    }
    else if(S <= P && R <= P) {
      rep(i,s.size()) cout << 'S';
      cout << "\n";
    }    
  }
  return 0;
}
