#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(int &a,int &b){
  if(abs(a-b)>eps) return a<b;
  else true;
}
int main()
{
  int n = 5;
  vector<int> a(5);
  rep(i,5) cin >> a[i];
  set<int> st;
  int k = 3;
  vector<int> res;
  int comb=(1<<k)-1;//辞書順最小
  while(comb<(1<<n)){//n個の要素から選ぶのでcomb>=(1<<n)となってはいけない
    int sum = 0;
    rep(i,n){
      if((1<<i)&comb){
	sum += a[i];
      }
    }
    if(st.find(sum)==st.end()){
      res.push_back(sum);
      st.insert(sum);
    }
    int x=comb&-comb;//最下位の1bitを独立させたもの
    int y=comb+x;//combの最下位の1の連続した部分を0に変え、その部分より1つ上の位を1に変える
    comb=((comb&~y)/x>>1)|y;
  }

  sort(res.begin(), res.end(),comp);

  cout << res[(int)res.size()-3] << "\n";
  
  return 0;
}
