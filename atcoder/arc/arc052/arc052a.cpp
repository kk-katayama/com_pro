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

  int c = '0';
  rep(i,s.size()){
    int x = s[i];
    if(c<=x&&x<=c+9){
      cout << s[i];
    }
  }
  cout  << "\n";
  return 0;
}
