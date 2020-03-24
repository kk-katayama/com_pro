#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int sum = 0;
  rep(i,n) sum += a[i];
  if(sum%n!=0) cout << -1 << "\n";
  else{
    if(sum==0){
      cout << 0 << "\n";
      return 0;
    }
    int x = sum/n;
    int cnt = 0;
    int summ = 0;
    int res = 0;
    rep(i,n){
      summ += a[i];
      cnt++;
      if(summ%x==0&&summ/x==cnt){
	summ = 0;
	cnt = 0;
      }
      else res++;
    }
    cout << res << "\n";
  }
  return 0;
}
