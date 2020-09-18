#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
//k以下である要素の個数を求める
// int n;
// int a[110000];
// int cntltk(int k){
//   int lb=-1,ub=n;
//   while(ub-lb>1){
//     int mid=(lb+ub)/2;
//     if(a[mid]<=k) lb=mid;
//     else ub=mid;
//   }
//   return lb+1;
// }

int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(), a.end());

  // ソート済みの配列aの要素で、k以下のものの個数を求める
  auto cntltk = [&a,&n](int k) ->int{
		  int lb = -1, ub = n;
		  while(ub - lb > 1) {
		    int mid = (lb + ub) / 2;
		    (a[mid] <= k ? lb : ub) = mid;
		  }
		  return lb + 1;
		};
  
  
  cout << cntltk(k) << "\n";
  return 0;
}
