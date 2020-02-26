#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<pair<int,int>> U,D,R,L;
  rep(i,n){
    int x,y;cin >> x >> y;
    char d;cin >> d;
    if(d=='U') U.push_back({x,y});
    else if(d=='D') D.push_back({x,y});
    else if(d=='R') R.push_back({x,y});
    else if(d=='L') L.push_back({x,y});            
  }
  //U
  int ux=-1e+9,uy=-1e+9,uz=-1e+9;
  rep(i,U,size()){ ux=max(ux,U[i].second); }
  rep(i,D,size()){ uy=max(uy,D[i].second); }
  rep(i,R,size()){ uz=max(uz,R[i].second); }
  rep(i,L,size()){ uz=max(uz,L[i].second); }
  // D
  int dx=1e+9,dy=1e+9,dz=1e+9;
  rep(i,U,size()){ dx=min(dx,U[i].second); }
  rep(i,D,size()){ dy=min(dy,D[i].second); }
  rep(i,R,size()){ dz=min(dz,R[i].second); }
  rep(i,L,size()){ dz=min(dz,L[i].second); }
  // R
  int rx=-1e+9,ry=-1e+9,rz=-1e+9;
  rep(i,U,size()){ rx=max(rx,U[i].first); }
  rep(i,D,size()){ ry=max(ry,D[i].first); }
  rep(i,R,size()){ rz=max(rz,R[i].first); }
  rep(i,L,size()){ rz=max(rz,L[i].first); }
  // L
  int lx=1e+9,ly=1e+9,lz=1e+9;
  rep(i,U,size()){ lx=min(lx,U[i].first); }
  rep(i,D,size()){ ly=min(ly,D[i].first); }
  rep(i,R,size()){ lz=min(lz,R[i].first); }
  rep(i,L,size()){ lz=min(lz,L[i].first); }        


  vector<pair<pair<double,char>,pair<double,double>>> p;
  // U
  if(ux!=-1e+9&&uy!=-1e+9){
    double t = (double)(uy-ux)/2;
    if(t>=0){
      double xx = (double)t+ux;
      
    }
  }
    
  
  
  return 0;
}
