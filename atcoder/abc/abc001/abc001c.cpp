#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
double round_n(double x,double n){
  x *= pow(10,n-1);
  x = round(x);
  x /= pow(10,n-1);
  return x;
}
int main()
{
  double deg,dis;
  cin >> deg >> dis;
  string w;
  if(112.5<=deg&&deg<337.5){
    w = "NNE";
  }
  else if(112.5<=deg&&deg<337.5){
    w = "NNE";
  }  
  return 0;
}
