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
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  for(int i=a.size()-1;i>=0;--i){
    if(a[i]!=a[i-1]){
      cout << a[i-1] << "\n";
      break;
    }
  }
  return 0;
}
