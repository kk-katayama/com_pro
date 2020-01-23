#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,x,y,z;
  cin >> n >> x >> y >> z;

  vector<int> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }

  int res=0;
  rep(i,n){
    if(x<=a[i]&&y<=b[i]&&z<=a[i]+b[i]) res++;
  }

  cout << res << "\n";
  return 0;
}
