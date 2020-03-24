#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
void show(vector<int> a,int x){
  rep(i,x) cout << a[i] << " ";
  cout  << "\n";
}
int main()
{
  int n;cin >> n;
  string s;cin >> s;  
  vector<int> a(n);
  bool in1 = false;
  rep(i,n){
    a[i] = (int)s[i] - '1';
    if(a[i] == 1) in1 = true;
  }

  int x = 0;
  rep(i,n){
    if(a[i] == 1 && (n-1 == (i | (n-1-i)))) x = (x+1)%2;
  }
  if(x%2 == 1) cout << 1 << "\n";
  else if(in1) cout << 0 << "\n";
  else{
    x = 0;
    rep(i,n){
      if(a[i] == 2 && (n-1 == (i | (n-1-i)))) x = (x+1)%2;      
    }
    if(x%2 == 0) cout << 0 << "\n";
    else cout << 2 << "\n";
  }
  
  
  return 0;
}
