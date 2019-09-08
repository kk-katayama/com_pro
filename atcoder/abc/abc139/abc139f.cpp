#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
vector<pair<double,double> > p;
bool comp(pair<double,double> &a,pair<double,double> &b){
  return atan2(a.second,a.first) < atan2(b.second,b.first);
}
int main()
{
  cin >> n;
  p.resize(n);
  rep(i,n) cin >> p[i].first >> p[i].second;

  sort(p.begin(),p.end(),comp);

  double res = 0;

  rep(i,n) rep(j,n){
    double x=0,y=0;
    if(i<=j){
      for(int k=i;k<=j;++k){
	x += p[k].first;
	y += p[k].second;
	res = max(res,fabs(sqrt(x*x+y*y)));
      }
    }
    else{
      for(int k=i;k<=n-1;++k){
	x += p[k].first;
	y += p[k].second;
	res = max(res,fabs(sqrt(x*x+y*y)));	
      }
      for(int k=0;k<=j;++k){
	x += p[k].first;
	y += p[k].second;
	res = max(res,fabs(sqrt(x*x+y*y)));
      }
    }
  }

  printf("%.10f\n",res);
  
  return 0;
}
