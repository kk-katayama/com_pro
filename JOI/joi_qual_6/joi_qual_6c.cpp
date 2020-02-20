#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
char conv(char c){
  if(c=='A'){
    return 'X';
  }
  if(c=='B'){
    return 'Y';
  }
  if(c=='C'){
    return 'Z';
  }  
  char a = c - 3;
  return a;
}
int main()
{
  string s;
  cin >> s;

  rep(i,s.size()){
    s[i] = conv(s[i]);
  }
  cout << s << "\n";
  
  return 0;
}
