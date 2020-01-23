#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(pair<int,string> &a,pair<int,string> &b){
  return a.first>b.first;
}

int main()
{
  int n;
  cin >> n;
  map<string,int> mp;
  rep(i,n){
    string s;
    cin >> s;
    mp[s]++;
  }

  vector<pair<int,string>> p(0);
  for(auto it=mp.begin();it!=mp.end();++it){
    p.push_back(make_pair(it->second,it->first));
  }
  
  sort(p.begin(), p.end(),comp);
  cout << p[0].second << "\n";
  
  return 0;
}
