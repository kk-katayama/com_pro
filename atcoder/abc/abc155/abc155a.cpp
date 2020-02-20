#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  vector<int> a(3);
  rep(i,3){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if(a[0]==a[1]&&a[1]!=a[2]){
    cout << "Yes" << "\n";
  }
  else if(a[0]!=a[1]&&a[1]==a[2]){
    cout << "Yes" << "\n";
  }
  else{
    cout << "No" << "\n";
  }
  return 0;
}
