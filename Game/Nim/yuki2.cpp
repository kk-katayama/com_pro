#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
map<int,int> mp;
map<int,int> prime_factor(int n){
  map<int,int> res;
  for(int i=2;i*i<=n;++i){
    while(n%i==0){
      res[i]++;
      n /= i;
    }
  }
  if(n!=1) res[n]++;
  return res;
}
int _n;
int main()
{
  cin >> _n;
  mp = prime_factor(_n);

  int nim = 0;
  for(auto itr=mp.begin();itr!=mp.end();++itr){
    nim ^= itr->second;
  }
  cout << (nim?"Alice":"Bob") << "\n";
  
  return 0;
}
