#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
string v,w;
vector<string> res;
void dfs(int i,int j,vector<string> s){
  if(i==v.size()){
    res = s;
    return ;
  }
  int x = v[i] - '0';
  if(s[x] == ""){
    rep1(l,3){
      s[x] = w.substr(j,l);
      dfs(i+1,j+l,s);
    }
  }
  else{
    int ns = s[x].size();
    if(s[x] != w.substr(j,ns)) return ;
    else dfs(i+1,j+ns,s);
  }
}
int main()
{
  int k,n;cin >> k >> n;
  v = "";w = "";
  rep(i,n){
    string vv,ww;cin >> vv >> ww;
    v += vv;w += ww;
    v.push_back('0');w.push_back('A');
  }

  vector<string> s(k+1,"");
  s[0] = "A";
  dfs(0,0,s);
  rep1(i,k) cout << res[i] << "\n";
  
  return 0;
}
