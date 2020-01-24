#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct LIS{
  int n;
  vector<int> dp;
  vector<int> array;
  const int inf = 1<<30;
  
  LIS(vector<int> _array)
  {
    array = _array;
    n = array.size();
    dp.assign(n+1,inf);
  }
  //二分探索の条件
  bool cond(int x,int a)
  {
    return dp[x] > a;
  }
  //二分探索。[l,r]の範囲でcondの条件を満たすdp[index]のうち最小のindexを返す
  int upper(int l,int r,int a)
  {
    int lb = l-1,ub = r+1;
    while(ub-lb > 1){
      int mid = (lb+ub)/2;
      if(cond(mid,a)) ub = mid;
      else lb = mid;
    }
    return ub;
  }
  
  void solve()
  {
    rep(i,n){
      int index = upper(0,n-1,array[i]);
      dp[index] = array[i];
    }
  }

  int length()
  {
    int res = 0;
    while(dp[res] != inf) res++;
    return res;
  }

  vector<int> check()
  {
    vector<int> res(0);
    int index = 0;
    while(dp[index] != inf){
      res.push_back(dp[index++]);
    }
    return res;
  }
  
  
};

int main()
{
  int n;
  cin >> n;
  vector<int> c(n);
  rep(i,n){
    cin >> c[i];
  }

  LIS lis(c);
  lis.solve();
  cout << n - lis.length() << "\n";
  
  return 0;
}
