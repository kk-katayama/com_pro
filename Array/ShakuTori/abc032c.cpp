#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct Array{
  vector<X> array;
  int n;
  vector<X> sum;
  
  Array(vector<X> _array)
  {
    array = _array;
    n = array.size();    
  }
  //累積和作成、最初にやる
  void make_sum()
  {
    sum.resize(n+1);
    sum[0] = 0;
    rep(i,n){
      sum[i+1] = sum[i]+array[i];
    }
  }
  
  //array[l]+...+array[r]を返す
  X segsum(int l,int r)
  {
    return sum[r+1] - sum[l];
  }

  int abc032d_solve(X k)
  {
    rep(i,n) if(array[i]==0) return n;
    int l = 0;
    int r = 1;
    int res = 0;
    X sum = array[0];
    while(1){
      while(sum<=k||r==l){
	res = max(res,r-l);
	r++;
	if(r == n+1) break;
	sum *= array[r-1];
      }
      if(r == n+1) break;
      sum /= array[l];
      l++;
    }
    return res;
    
  }
  
};
int main()
{
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> s(n);
  rep(i,n) cin >> s[i];

  Array<ll> arr(s);
  cout << arr.abc032d_solve(k) << "\n";
  
  
  return 0;
}
