#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Set
{
  int n;

  Set(int _n)
  {
    n = _n;
  }

  void size_search(int k)
  {
    int comb=(1<<k)-1;//辞書順最小
    while(comb<(1<<n)){//n個の要素から選ぶのでcomb>=(1<<n)となってはいけない
      rep(i,n){
	if((1<<i)&comb) cout << i << " ";
      }
      cout << "\n";
      int x=comb&-comb;//最下位の1bitを独立させたもの
      int y=comb+x;//combの最下位の1の連続した部分を0に変え、その部分より1つ上の位を1に変える
      comb=((comb&~y)/x>>1)|y;
      //z=comb&~yは最下位の1の連続した部分を取り出す。
      //z/xでzの最下位の1の連続した部分より下位にある0を消し、右に1ビットシフトする。
      //それとyのorをとれば求めたい次のビット列が得られる。
    }
  }

};
int main()
{
  int n,k;
  cin >> n >> k;
  
  Set st(n);
  st.size_search(k);
  return 0;
}
