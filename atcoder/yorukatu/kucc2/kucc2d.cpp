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
  string s;cin >> s;
  int n = s.size();
  if(n == 1 && s[0] == 'a') cout << "NO" << "\n";
  else if(n == 20 && s == "zzzzzzzzzzzzzzzzzzzz") cout << "NO" << "\n";
  else {
    bool f = true;
    int index;
    rep(i,n-1) {
      if(s[i] != s[i+1]) {
	f = false;
	index = i;
	break;
      }
    }
    if(f) {
      if(s[0] == 'a') {
	rep(i,n-2) cout << 'a';
	cout << 'b' << "\n";
      }
      else if(s[0] == 'z') {
	rep(i,n-2) cout << 'z';
	cout << "ya" << "\n";	
      }
      else if(n == 1) {
	char c = s[0] - 1;
	cout << c  << 'a'<< "\n";
      }
      else {
	s[0]++;s[1]--;
	cout << s << "\n";
      }
    }
    else {
      swap(s[index], s[index+1]);
      cout << s << "\n";
    }
  }
  return 0;
}
