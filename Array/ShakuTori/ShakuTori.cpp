#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct ShakuTori{
  vector<X> array;
  int n;
  vector<X> sum;
  
  ShakuTori(vector<X> _array)
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
  
  //[l,r)の和array[l]+...+array[r-1]を返す
  X segsum(int l,int r)
  {
    return sum[r] - sum[l];
  }
  
  int worm_count(X x)
  {
    int res = 0;
    int l = 0,r = 1;
    X sum = segsum(l,r);
    while(1){
      while(sum<=x){
	res += r - l;
	if(r == n) break;
	r++;
	sum = segsum(l,r);
      }
      if(r == n) break;
      l++;
      sum = segsum(l,r);
    }
    return res;
  }
    
};

int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  
  ShakuTori<int> arr(a);
  arr.make_sum();

  cout << arr.worm_count(k) << "\n";
  
  return 0;
}
