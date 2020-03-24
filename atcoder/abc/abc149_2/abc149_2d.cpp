#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int R,S,P;
int p(char c){
  if(c=='r') return P;
  if(c=='p') return S;
  if(c=='s') return R;  
}
int main()
{
  int n,k;cin >> n >> k;
  cin >> R >> S >> P;
  string t;cin >> t;
  int res = 0;
  rep(i,n){
    if(i-k>=0){
      if(t[i-k]==t[i]) t[i] = 'x';
      else res += p(t[i]);
    }
    else res += p(t[i]);
  }
  cout << res << "\n";
  return 0;
}
