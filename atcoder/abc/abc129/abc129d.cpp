#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int h,w;
vector<int> row[2100],col[2100];

int height(int j,int x){
  int lb=0,ub=col[j].size()+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(col[j][mid]<x) lb=mid;
    else ub=mid;
  }
  int left=col[j][lb];
  lb=0;ub=col[j].size()+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(col[j][mid]>x) ub=mid;
    else lb=mid;
  }  
  return col[j][ub]-left-1;
}

int width(int i,int x){
  int lb=0,ub=row[i].size()+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(row[i][mid]<x) lb=mid;
    else ub=mid;
  }
  int left=row[i][lb];
  lb=0;ub=row[i].size()+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(row[i][mid]>x) ub=mid;
    else lb=mid;
  }  
  return row[i][ub]-left-1;
}


int main()
{
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  rep1(i,h){
    row[i].push_back(0);
    rep(j,w) if(s[i-1][j]=='#') row[i].push_back(j+1);
    row[i].push_back(w+1);
  }

  rep1(j,w){
    col[j].push_back(0);
    rep(i,h) if(s[i][j-1]=='#') col[j].push_back(i+1);
    col[j].push_back(h+1);
  }  

  // rep1(i,h){
  //   rep(j,row[i].size()) cout << row[i][j] << " ";
  //   cout  << "\n";
  // }

  // rep1(j,w){
  //   rep(i,col[j].size()) cout << col[j][i] << " ";
  //   cout  << "\n";
  // }

  int res = 0;
  rep1(i,h) rep1(j,w){
    if(s[i-1][j-1]=='#') continue;
    //    cout << i << ":" << j << ":" << width(i,j) << ":" << height(j,i) << "\n";
    int kk = width(i,j)+height(j,i)-1;
    res = max(res,kk);
  }
  cout << res << "\n";
  return 0;
}
