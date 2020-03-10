#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
void dfs(int i,string s,char c){
  if(i!=0) s.push_back(c);
  if(i==n){
    cout << s << "\n";
    return ;
  }
  rep(j,3){
    char cc = 'a' + j;
    dfs(i+1,s,cc);
  }
}
int main()
{
  cin >> n;
  dfs(0,"",'x');
  return 0;
}
