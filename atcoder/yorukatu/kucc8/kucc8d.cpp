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
  string s; cin >> s;
  int n = s.size();

  auto issmall = [](char a) {
		   return 97 <= (int)a && (int)a <= 97+25;
		 };

  auto islarge = [](char a) {
		   return 97-32 <= (int)a && (int)a <= 97+25-32;
		 };

  if(s[0] == '_') {
    if(n == 1) {
      cout << s << "\n";
      return 0;
    }
    else {
      if(!issmall(s[1])) {
	cout << s << "\n";
	return 0;	
      }
    }
  }
  else {
    if(!issmall(s[0])) {
      cout << s << "\n";
      return 0;	
    }    
  }
  // snake?
  bool snake = true;
  rep(i,n) {
    if(islarge(s[i])) {
      snake = false;
      break;
    }
    if(s[i] == '_') {
       if(i + 1 == n) continue;
       if(!issmall(s[i+1])) {
	 snake = false;
	 break;
       }
    }       
  }
  if(snake) {
    string res = "";
    rep(i,n) {
      if(s[i] == '_' && (0 < i && i < n - 1)) continue;
      if(i >= 2 && s[i-1] == '_') {
	res.push_back((char)s[i] - 32);
      }
      else res.push_back(s[i]);      
    }
    cout << res << "\n";
    return 0;
  }

  //camel?
  bool camel = true;
  rep(i,n) {
    if(0 < i && i < n-1 && s[i] == '_') {
      camel = false;
      break;
    }
    if(islarge(s[i])) {
      if(s[i-1] == '_') {
	camel = false;
	break;
      }
    }
  }  
  if(camel) {
    string res = "";
    rep(i,n) {
      if(islarge(s[i])) {
	res.push_back('_');
	res.push_back((char)s[i] + 32);
      }
      else res.push_back(s[i]);
    }
    cout << res << "\n";
    return 0;
  }

  cout << s << "\n";
  
  return 0;
}
