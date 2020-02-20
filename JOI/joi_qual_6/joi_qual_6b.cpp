#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  vector<bool> v(30,0);
  rep(i,28){
    int x;
    cin >> x;
    x--;
    v[x]=1;
  }

  rep(i,30){
    if(!v[i]){
      cout << i+1 << "\n";
    }
  }
  
  return 0;
}
