#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
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
  
};
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> l(m),r(m);
  rep(i,m) cin >> l[i] >> r[i];
  
  Array<int> arr(a);

  arr.make_sum();

  rep(i,m) cout << arr.segsum(l[i],r[i]) << "\n";
  
  return 0;
}
