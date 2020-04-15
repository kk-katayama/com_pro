#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int sum = 0;
  rep(i,k) {
    sum += a[i];
  }

  int res = sum;

  int left = 0, right = k;
  while(right < n) {
    sum -= a[left];
    sum += a[right];
    res = max(res, sum);
    left++;
    right++;
  }

  cout << res << "\n";
  
  return 0;
}
