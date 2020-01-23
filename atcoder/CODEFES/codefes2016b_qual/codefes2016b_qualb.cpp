#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,a,b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  
  int c = a + b;
  rep(i,n){
    if(c==0){
      cout << "No" << "\n";
    }
    else if(s[i]=='a'){
      cout << "Yes" << "\n";
      c--;
    }
    else if(s[i]=='b'){
      if(b==0){
	cout << "No" << "\n";
      }
      else{
	cout << "Yes" << "\n";
	c--;
	b--;
      }
    }
    else{
      cout << "No" << "\n";
    }
  }
  
  
  return 0;
}
