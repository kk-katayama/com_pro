#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct solve{
  int n;
  vector<int> a;
  int k;

  solve(int _n,vector<int> _a,int _k){
    n = _n;
    a = _a;
    k = _k;
  }

  bool dfs(int i,int sum){
    if(i==n) return sum==k;
    if(dfs(i+1,sum+a[i])) return true;
    if(dfs(i+1,sum)) return true;
    return false;
  }

  void play(){
    if(dfs(0,0)) cout << "Yes" << "\n";
    else cout << "No" << "\n";
  }

};
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int k;
  cin >> k;

  solve sl(n,a,k);
  
  sl.play();
  
  return 0;
}
