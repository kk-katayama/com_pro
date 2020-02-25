#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(pair<pair<string,int>,int> &a,pair<pair<string,int>,int> &b){
  if(a.first.first==b.first.first) return a.first.second>b.first.second;
  else return a.first.first<b.first.first;
}
int main()
{
  int n;cin >> n;
  vector<pair<pair<string,int>,int>> p(n);
  rep(i,n){
    string s;int x;
    cin >> s >> x;
    p[i] = {{s,x},i+1};
  }
  sort(p.begin(), p.end(),comp);
  rep(i,n){
    cout << p[i].second << "\n";
  }    

  
  return 0;
}
