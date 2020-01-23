#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
vector<vector<ll> > comb;
void pascal(int n)
{
  comb.resize(n+1);
  rep(i,n+1) comb[i].assign(n+1,1);

  for(int i=2;i<=n;++i){
    for(int j=1;j<i;++j){
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    }
  }
}
int main()
{
  int a,b;
  cin >> a >> b;
  pascal(a);
  cout << comb[a][b] << "\n";
  
  return 0;
}
