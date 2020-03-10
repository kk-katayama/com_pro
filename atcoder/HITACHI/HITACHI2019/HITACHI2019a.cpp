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
  if((int)s.size()%2==1){
    cout << "No" << "\n";
  }
  else{
    rep(i,s.size()){
      if(i%2==0&&s[i]!='h'){
	cout << "No" << "\n";
	return 0;
      }
      if(i%2==1&&s[i]!='i'){
	cout << "No" << "\n";
	return 0;
      }      
    }
    cout << "Yes" << "\n";
  }
  return 0;
}
