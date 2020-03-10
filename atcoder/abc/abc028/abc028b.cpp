#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;cin >> s;
  map<char,int> mp;
  rep(i,s.size()) mp[s[i]]++;
  cout << mp['A'] << " ";
  cout << mp['B'] << " ";
  cout << mp['C'] << " ";
  cout << mp['D'] << " ";
  cout << mp['E'] << " ";
  cout << mp['F'] << "\n";

  
  return 0;
}
