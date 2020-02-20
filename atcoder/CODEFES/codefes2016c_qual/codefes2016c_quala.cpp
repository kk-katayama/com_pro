#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;
  cin >> s;
  bool f = false;
  rep(i,s.size()){
    if(s[i]=='C') f = true;
    else if(f&&s[i]=='F'){
      cout << "Yes" << "\n";
      return 0;
    }
  }
  cout << "No" << "\n";
  return 0;
}
