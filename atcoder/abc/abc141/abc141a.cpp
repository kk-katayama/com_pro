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

  if(s[0]=='S') cout << "Cloudy" << "\n";
  else if(s[0]=='C') cout << "Rainy" << "\n";
  else cout << "Sunny" << "\n";
  return 0;
}
