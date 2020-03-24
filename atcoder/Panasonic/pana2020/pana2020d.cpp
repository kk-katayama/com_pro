#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
vector<string> res;
int n;
void dfs(int i,char c,string s,int x){
  s.push_back(c);
  if(i==n){
    res.push_back(s);
    return ;
  }
  rep(j,x+1){
    char cc = 'a' + j;
    if(j==x) dfs(i+1,cc,s,x+1);
    else dfs(i+1,cc,s,x);
  }
}
int main()
{
  cin >> n;
  dfs(1,'a',"",1);
  sort(res.begin(), res.end());
  rep(i,res.size()) cout << res[i] << "\n";
  return 0;
}
