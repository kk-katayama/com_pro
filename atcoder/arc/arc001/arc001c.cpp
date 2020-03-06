#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool check(vector<string> v){
  // 縦
  rep(j,8){
    int cnt = 0;
    rep(i,8){
      if(v[i][j]=='Q') cnt++;
    }
    if(cnt>=2) return false;
  }
  // 右ななめ下
  rep(j,8){
    int i = 0;
    int cnt = 0;
    for(int k=j;k<8;++k){
      if(v[i++][k]=='Q') cnt++;
    }
    if(cnt>=2) return false;
  }

  rep(i,8){
    int j=0;
    int cnt=0;
    for(int k=i;k<8;++k){
      if(v[k][j++]=='Q') cnt++;
    }
    if(cnt>=2) return false;
  }

  rep(j,8){
    int i = 0;
    int cnt = 0;
    for(int k=j;k>=0;--k){
      if(v[i++][k]=='Q') cnt++;
    }
    if(cnt>=2) return false;
  }

  rep(i,8){
    int j=7;
    int cnt=0;
    for(int k=i;k<8;++k){
      if(v[k][j--]=='Q') cnt++;
    }
    if(cnt>=2) return false;
  }  

  return true;
}
bool f;
vector<string> res;
int row[8];
void dfs(int i,vector<string> v,string s){
  if(i!=0) v.push_back(s);
  if(i==8){
    if(check(v)){
      f = true;
      res = v;
    }
    return ;
  }
  if(row[i]>=0){
    string ss = "........";
    ss[row[i]] = 'Q';
    dfs(i+1,v,ss);
  }
  else{
    rep(j,8){ 
      string ss = "........";   
      ss[j] = 'Q';
      dfs(i+1,v,ss);
    }
  }
}
int main()
{
  rep(i,8) row[i] = -1;
  rep(i,8){
    rep(j,8){
      char c;cin >> c;
      if(c=='Q'){
	if(row[i]>=0){
	  cout << "No Answer" << "\n";
	  return 0;
	}
	else row[i] = j;
      }
    }
  }
  f = false;
  vector<string> v;
  string s;
  dfs(0,v,s);
  if(f){
    rep(i,8){
      rep(j,8) cout << res[i][j];
      cout  << "\n";
    }
  }
  else cout << "No Answer" << "\n";
  return 0;
}
