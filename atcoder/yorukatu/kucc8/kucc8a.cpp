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
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  auto change = [](char a)-> int{
		  if(a == 'b' || a == 'c' || a == 'B' || a == 'C') return 1;
		  else if(a == 'd' || a == 'w' || a == 'D' || a == 'W') return 2;
		  else if(a == 't' || a == 'j' || a == 'T' || a == 'J') return 3;
		  else if(a == 'f' || a == 'q' || a == 'F' || a == 'Q') return 4;
		  else if(a == 'l' || a == 'v' || a == 'L' || a == 'V') return 5;
		  else if(a == 's' || a == 'x' || a == 'S' || a == 'X') return 6;
		  else if(a == 'p' || a == 'm' || a == 'P' || a == 'M') return 7;
		  else if(a == 'h' || a == 'k' || a == 'H' || a == 'K') return 8;
		  else if(a == 'n' || a == 'g' || a == 'N' || a == 'G') return 9;
		  else if(a == 'z' || a == 'r' || a == 'Z' || a == 'R') return 0;
		  else return -1;
		};
  bool ff = true;
  rep(i,n) {
    bool f = false;
    for(auto val: s[i]) {
      int res = change(val);
      if(res != -1) {
	if((!f) && (!ff)) cout << " ";
	ff = false;
	cout << res;
	f = true;
      }
    }
  }
  cout << "\n";
  return 0;
}
