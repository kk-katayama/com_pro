#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename F,typename T>
struct DST{
  T identity;
  F merge;
  int size;
  vector<T> dat,delay;

  DST(F f,T id):merge(f),identity(id){}
  
};
int main()
{

  return 0;
}
