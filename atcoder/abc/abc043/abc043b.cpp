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

  string res = "";
  rep(i,s.size()){
    if(s[i]=='0'){
      res += "0";
    }
    else if(s[i]=='1'){
      res += "1";
    }
    else{
      if(res.size()!=0){
	auto it = res.begin()+res.size()-1;
	res.erase(it);
      }
    }
  }
  cout << res << "\n";
  return 0;
}
