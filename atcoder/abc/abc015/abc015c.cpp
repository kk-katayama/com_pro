#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n,k;
int t[10][10];
bool f;
void rec(int i,int r){
  if(i==n){
    //    cout << r << "\n";
    if(r==0) f=false;
    return ;
  }
  rep(j,k){
    rec(i+1,t[i][j]^r);
  }
}

int main()
{

  cin >> n >> k;
  rep(i,n) rep(j,k) cin >> t[i][j];
  f = true;
  rec(0,0);
  if(!f) cout << "Found" << "\n";
  else cout << "Nothing" << "\n";
  return 0;
}
