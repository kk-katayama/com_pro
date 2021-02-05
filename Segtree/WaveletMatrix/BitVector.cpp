#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();

using u8 = unsigned char;
using u16 = unsigned short;
class BitVector{
public:
  const u16 siz;
  vector<u8> bit;
  vector<u16> chunk;
  vector<vector<u8>> block;
  u16 csiz, bsiz;
  const int cw = 256;
  const int bw = 8;

  BitVector(int n) : siz(n) {
    csiz = (siz + cw - 1) / cw;
    bsiz = cw / bw;

    bit.assign(csiz * bsiz, 0);
    chunk.assign(csiz + 1, 0);
    block.assign(csiz + 1, vector<u8>(bsiz, 0));
  }

  // pos桁目をbに変更
  void set(int pos, int b) {
    int bpos = pos / bw;
    int offset = pos % bw;

    if(b == 1) bit[bpos] |= (1 << offset);
    else bit[bpos] &= ~(1 << offset);
  }

  // pos桁目の値を返す
  int access(int pos) {
    int bpos = pos / bw;
    int offset = pos % bw;

    return ( ( bit[bpos] >> offset) & 1);
  }

  // chunk配列とblock配列の作成
  void build() {
    chunk[0] = 0;
    rep(i,csiz) {
      block[i][0] = 0;
      rep(j,bsiz-1) {
	block[i][j+1] = block[i][j] + __builtin_popcount(bit[i * bsiz + j]);
      }
      chunk[i+1] = chunk[i] + block[i][bsiz - 1] + __builtin_popcount(bit[i * bsiz + bsiz - 1]);
    }
  }

  // [0, pos) の範囲にあるbの数を返す
  int rank(int pos, int b) {
    int cpos = pos / cw;
    int bpos = (pos % cw) / bw;
    int offset = pos % bw;

    u8 mask = (bit[cpos * bsiz + bpos]) & ((1 << offset) - 1);
    int res = chunk[cpos] + block[cpos][bpos] + __builtin_popcount(mask);
    return (b == 0 ? pos - res : res);
  }

  // k番目に現れるbの位置を返す
  int select(int k, int b) {
    if(k == 0) return 0;
    if(rank(siz, b) < k) return -1;
    int lb = -1, ub = siz;
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (k <= rank(mid, b) ? ub : lb) = mid;
    }
    return ub - 1;
  }
  
};

void test() {
  BitVector bv(11);
  vi tmp = {1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1};
  rep(i,11) {
    bv.set(i, tmp[i]);
  }
  bv.build();
  rep(i,12) {
    cout << bv.rank(i, 0) << "\n";
  }
  cout << bv.select(2, 0) << "\n";
}
int main()
{
  test();
  
  return 0;
}
