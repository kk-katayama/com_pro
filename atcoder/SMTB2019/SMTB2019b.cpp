#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;

  bool f=true;
  rep1(i,n){
    int x = i*108/100;
    if(x==n){
      cout << i << "\n";
      f=false;
    }
  }
  if(f) cout << ":(" << "\n";
  return 0;
}
