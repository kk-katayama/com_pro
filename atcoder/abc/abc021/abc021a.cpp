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
  vector<int> res;
  rep(i,5){
    if((n>>i)&1){
      res.push_back((1<<i));
    }
  }
  cout << (int)res.size() << "\n";
  rep(i,res.size()){
    cout << res[i] << "\n";
  }
  return 0;
}
