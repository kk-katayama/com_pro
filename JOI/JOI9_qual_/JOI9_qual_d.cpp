#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;cin >> n >> k;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  
  map<string,int> mp;
  int res = 0;
  // n個のうちからサイズがk個の集合を全探索
  int comb=(1<<k)-1;//辞書順最小
  while(comb<(1<<n)){//n個の要素から選ぶのでcomb>=(1<<n)となってはいけない
    vector<int> vec;
    rep(i,n){
      if((1<<i)&comb) vec.push_back(i);
    }
    // vectorの全並び替えを全探索

    do{
      string s = "";      
      for(int x : vec) s += to_string(v[x]);
      if(mp[s] == 0) res++;
      mp[s]++;
    } while(next_permutation(vec.begin(), vec.end()));
    
    
    int x=comb&-comb;//最下位の1bitを独立させたもの
    int y=comb+x;//combの最下位の1の連続した部分を0に変え、その部分より1つ上の位を1に変える
    comb=((comb&~y)/x>>1)|y;
    //z=comb&~yは最下位の1の連続した部分を取り出す。
    //z/xでzの最下位の1の連続した部分より下位にある0を消し、右に1ビットシフトする。
    //それとyのorをとれば求めたい次のビット列が得られる。
  }
  cout << res << "\n";
  return 0;
}