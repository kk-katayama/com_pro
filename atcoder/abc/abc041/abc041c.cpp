#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<pair<int,int>> p(n);
  rep(i,n){
    int a;cin >> a;
    p[i] = {-a,i+1};
  }
  sort(p.begin(),p.end());
  rep(i,n) cout << p[i].second << "\n";
  
  return 0;
}
