#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(pair<int,int> &a,pair<int,int> &b){
  if(abs(a.first-b.first)>2) return a.first>b.first;
  else return false;
}
int main()
{
  vector<int> a(3),b(3);
  // rep(i,3) cin >> a[i];
  vector<pair<int,int>> p(3);
  rep(i,3) cin >> a[i] >> b[i];
  rep(i,3) p[i] = {b[i],a[i]};
  sort(p.begin(), p.end(),comp);
  rep(i,3) cout << p[i].second << "," << p[i].first << "\n";

  return 0;
}
