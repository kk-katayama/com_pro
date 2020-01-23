#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  const int WMAX = 2e+6+1; 
  vector<bool> wei(WMAX,0);
  vector<pair<int,int>> com(WMAX);
  
  rep(i,n) rep(j,m){
    int temp = a[i] + b[j];
    if(wei[temp]){
      cout << com[temp].first << " ";
      cout << com[temp].second << " ";
      cout << i << " ";
      cout << j << "\n";
      return 0;
    }
    else{
      com[temp] = make_pair(i,j);
      wei[temp] = true;
    }
  }
  cout << -1 << "\n";
  return 0;
}
