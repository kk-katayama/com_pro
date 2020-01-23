#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  map<int,int> mp;
  int a,b;
  cin >> a >> b;
  mp[a]++;
  mp[b]++;
  int k;
  cin >> k;
  rep(i,k){
    int p;
    cin >> p;
    mp[p]++;
    if(mp[p]>=2){
      cout << "NO" << "\n";
      return 0;
    }
  }
  cout << "YES" << "\n";


  
  return 0;
}
