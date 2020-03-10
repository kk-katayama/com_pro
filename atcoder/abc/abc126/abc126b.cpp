#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;cin >> s;
  bool a,b;
  if(s[0]=='0'&&s[1]!='0') a = true;
  else if(s[0]=='1'&&(s[1]=='0'||s[1]=='1'||s[1]=='2')) a = true;
  else a = false;

  if(s[2]=='0'&&s[3]!='0') b = true;
  else if(s[2]=='1'&&(s[3]=='0'||s[3]=='1'||s[3]=='2')) b = true;
  else b = false;

  if(a&&b) cout << "AMBIGUOUS" << "\n";
  else if(a&&(!b)) cout << "MMYY" << "\n";
  else if((!a)&&b) cout << "YYMM" << "\n";  
  else cout << "NA" << "\n";
  return 0;
}
