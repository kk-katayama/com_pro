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
  vector<int> vec(n);
  rep(i,n) cin >> vec[i];

  sort(vec.begin(), vec.end());
  
  do{
    // rep(i,n) cout << vec[i] << " ";
    // cout  << "\n";
  } while(next_permutation(vec.begin(), vec.end()));
  
  return 0;
}
