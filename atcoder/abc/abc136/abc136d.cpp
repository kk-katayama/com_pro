#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;cin >> s;
  int p=0;int cntr=1;int cntl=0;
  vector<int> pl,num;
  rep(i,s.size()-1){
    if(s[i]!=s[i+1]){
      if(p%2==0){
	pl.push_back(i);pl.push_back(i+1);
	num.push_back(cntr);
	cntl=1;
      }
      else{
	num.push_back(cntl);
	cntr=1;
      }
      p++;
    }
    else{
      cntr++;cntl++;
    }
  }
  num.push_back(cntl);

  vector<int> res(s.size(),0);
  for(int i=0;i<pl.size();i+=2){
    res[pl[i]] = (num[i]+1)/2 + num[i+1]/2;
    res[pl[i+1]] = num[i]/2 + (num[i+1]+1)/2;
  }
  rep(i,s.size()) cout << res[i] << " ";
  cout  << "\n";

  
  return 0;
}
