#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n;cin >> n;
  n++;
  int cnt = 0;
  while(n>1){
    if(cnt%2==0){
      n = (n+1)/2;
    }
    else{
      n = n/2;
    }
    cnt++;
  }
  if(cnt%2==0) cout << "Takahashi" << "\n";
  else cout << "Aoki" << "\n";
  return 0;
}
