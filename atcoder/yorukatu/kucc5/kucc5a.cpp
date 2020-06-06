#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int n;
string s;
bool check(int a, int b) {
  vector<int> res(n);
  // 1 = sheep , -1 = wolf
  res[0] = a, res[1] = b;
  for (int i = 2; i < n; ++i) {
    if(s[i-1] == 'o') {
      if(res[i-1] == 1) res[i] = res[i-2];
      else res[i] = -res[i-2];
    }
    else {
      if(res[i-1] == 1) res[i] = -res[i-2];
      else res[i] = res[i-2];
    }    
  }

  auto show = [&]()-> void {
		rep(i,n) cout << (res[i] == 1 ? 'S' : 'W');
		cout << "\n";
	      };

  bool f = false;
  if(s[n-1] == 'o') {
    if(res[n-1] == 1) {
      if(res[n-2] == res[0]) {
	f = true;
      }
    }
    else {
      if(res[n-2] != res[0]) {
	f = true;
      }
    }
  }
  else {
    if(res[n-1] == 1) {
      if(res[n-2] != res[0]) {
	f = true;
      }      
    }
    else {
      if(res[n-2] == res[0]) {
	f = true;
      }      
    }    
  }

  if(!f) return false;

  if(s[0] == 'o') {
    if(res[0] == 1) {
      if(res[n-1] == res[1]) {
	show();
	return true;
      }
    }
    else {
      if(res[n-1] != res[1]) {
	show();
	return true;
      }
    }
  }
  else {
    if(res[0] == 1) {
      if(res[n-1] != res[1]) {
	show();
	return true;
      }      
    }
    else {
      if(res[n-1] == res[1]) {
	show();
	return true;
      }      
    }    
  }  
  
  return false;
}

int main()
{
  cin >> n;
  cin >> s;

  if(check(1,1)) return 0;
  if(check(1,-1)) return 0;
  if(check(-1,1)) return 0;  
  if(check(-1,-1)) return 0;
  cout << -1 << "\n";
  return 0;
}
