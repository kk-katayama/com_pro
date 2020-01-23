#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  int m=0;
  rep(i,n) {
    cin >> a[i] >> b[i];
    b[i]++;
    m = max(m,b[i]);
  }
  vector<int> imos(m,0);
  rep(i,n){
    imos[a[i]]++;
    imos[b[i]]--;
  }
  int res=0;
  int kk=0;
  rep(i,m+1){
    kk+=imos[i];
    res=max(res,kk);
  }

  cout << res << "\n";
  
  return 0;
}
