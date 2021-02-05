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
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  int q; cin >> q;
  vi pow2(15);
  pow2[0] = 1;
  rep(i,13) {
    pow2[i+1] = pow2[i]*2;
  }
  while(q-- > 0) {
    int n; cin >> n;
    cout << n+5 << "\n";
    int cnt = n+5;
    if(n > pow2[13]) {
      for (int i = 2; i < n; ++i) {
	if(i == pow2[13] || i == pow2[8]) {
	  continue;
	}
	cout << i << " " << n << "\n";
	cnt--;
      }
      cout << n << " " << pow2[13] << "\n";
      cnt--;
      cout << n << " " << pow2[13] << "\n";
      cnt--;            
      int x = pow2[13], y = pow2[8];
      while(cnt-- > 0) {      
	cout << x << " " << y << "\n";
	swap(x, y);
      }                }
    else if(n > pow2[8]) {
      for (int i = 2; i < n; ++i) {
	if(i == pow2[5] || i == pow2[8]) {
	  continue;
	}
	cout << i << " " << n << "\n";
	cnt--;	
      }
      cout << n << " " << pow2[8] << "\n";
      cnt--;
      cout << n << " " << pow2[8] << "\n";
      cnt--;            
      int x = pow2[8], y = pow2[5];
      while(cnt-- > 0) {      
	cout << x << " " << y << "\n";
	swap(x, y);
      }                  
    }
    else if(n > pow2[5]) {
      for (int i = 2; i < n; ++i) {
	if(i == pow2[5] || i == pow2[3]) {
	  continue;
	}
	cout << i << " " << n << "\n";
	cnt--;	
      }
      cout << n << " " << pow2[5] << "\n";
      cnt--;
      cout << n << " " << pow2[5] << "\n";
      cnt--;            
      int x = pow2[5], y = pow2[3];
      while(cnt-- > 0) {      
	cout << x << " " << y << "\n";
	swap(x, y);
      }            
    }
    else if(n > pow2[3]) {
      for (int i = 2; i < n; ++i) {
	if(i == pow2[3] || i == pow2[2]) {
	  continue;
	}
	cout << i << " " << n << "\n";
	cnt--;	
      }
      cout << n << " " << pow2[3] << "\n";
      cnt--;
      cout << n << " " << pow2[3] << "\n";
      cnt--;            
      int x = pow2[3], y = pow2[2];
      while(cnt-- > 0) {      
	cout << x << " " << y << "\n";
	swap(x, y);
      }      
    }
    else if(n > pow2[2]) {
      for (int i = 2; i < n; ++i) {
	if(i == pow2[2] || i == pow2[1]) {
	  continue;
	}
	cout << i << " " << n << "\n";
	cnt--;	
      }
      cout << n << " " << pow2[2] << "\n";
      cout << n << " " << pow2[2] << "\n";      
      cnt--;
      cnt--;            
      int x = pow2[2], y = pow2[1];
      while(cnt-- > 0) {      
	cout << x << " " << y << "\n";
	swap(x, y);
      }
    }
    else if(n > pow2[1]) {
      for (int i = 2; i < n; ++i) {
	if(i == pow2[1]) {
	  continue;
	}	
	cout << i << " " << n << "\n";
	cnt--;	
      }
      cout << n << " " << pow2[1] << "\n";
      cnt--;      
      cout << n << " " << pow2[1] << "\n";
      cnt--;      
    }
    while(cnt-- > 0) {
      cout << 1 << " " << 2 << "\n";
    }    
  }
  return 0;
}
