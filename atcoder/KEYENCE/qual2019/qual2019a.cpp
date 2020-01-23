#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  vector<int> a(4);
  rep(i,4){
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  if(a[0]==1&&a[1]==4&&a[2]==7&&a[3]==9){
    cout << "YES" << "\n";
  }
  else{
    cout << "NO" << "\n";
  }

  
  return 0;
}
