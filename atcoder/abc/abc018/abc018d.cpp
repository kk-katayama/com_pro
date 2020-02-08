#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(int &a,int &b){
  return a>b;
}
int main()
{
  int n,m,p,q,r;
  cin >> n >> m>> p >> q >>r;
  vector<int> x(r),y(r),z(r);
  rep(i,r){
    cin >> x[i] >> y[i] >> z[i];
    x[i]--;
    y[i]--;
  }

  int comb=(1<<p)-1;//辞書順最小
  int res = 0;
  while(comb<(1<<n)){//n個の要素から選ぶのでcomb>=(1<<n)となってはいけない
    vector<int> man(m,0);
    rep(i,r){
      if((comb>>x[i])&1){
	man[y[i]] += z[i];
      }
    }
    sort(man.begin(), man.end(),comp);
    int tmp=0;
    rep(i,q){
      tmp += man[i];
    }
    res = max(res,tmp);
    int x=comb&-comb;//最下位の1bitを独立させたもの
    int y=comb+x;//combの最下位の1の連続した部分を0に変え、その部分より1つ上の位を1に変える
    comb=((comb&~y)/x>>1)|y;
  }

  cout << res << "\n";
    


  
  return 0;
}
