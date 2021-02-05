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

class WaveletMatrix{
public:
  int siz;
  int bitmx;
  vector<BitVector> bv;
  vector<int> offset;
  vector<int> t;
  int mx_elem;
  
  //  WaveletMatrix(int n) : siz(n){}
  WaveletMatrix() {}  

  void build(vector<int> v) {
    siz = sz(v);
    int mx = 0;
    for(auto val: v) {
      chmax(mx, val);
    }
    t.resize(mx+1);
    mx_elem = mx;
    int cnt = 0;
    while(mx > 0) {
      cnt++;
      mx /= 2;
    }
    bitmx = cnt;
    
    // wavelet matrixの構築
    bv.resize(bitmx, BitVector(siz));
    offset.resize(bitmx + 1, 0);
    rep(i,bitmx) {
      vector<int> nv;
      rep(j,sz(v)) {
	if((v[j] >> (bitmx - i - 1)) & 1) {
	  bv[i].set(j, 1);
	}
	else {
	  bv[i].set(j, 0);
	  nv.push_back(v[j]);
	}
      }
      offset[i+1] = nv.size();
      rep(j,sz(v)) {
	if((v[j] >> (bitmx - i - 1)) & 1) {
	  nv.push_back(v[j]);
	}
      }
      v = nv;
      bv[i].build();
    }

    t[v[0]] = 0;
    rep1(i,sz(v)-1) {
      if(v[i] != v[i-1]) t[v[i]] = i;
    }
  }


  // 元の配列vのv[pos]を返す
  int access(int pos) {
    int res = 0;
    rep(i,bitmx) {
      int x = bv[i].access(pos);
      res += x * pow(2, bitmx - 1 - i);
      pos = (x == 0 ? 0 : offset[i+1]) + bv[i].rank(pos+1, x) - 1;
    }
    return res;
  }

  // [0, pos) に数値cがいくつ現れたかを返す
  int rank(int pos, int c) {
    rep(i,bitmx) {
      if((c >> (bitmx - 1 - i)) & 1) {
	pos = bv[i].rank(pos, 1) + offset[i+1];
      }
      else {
	pos = bv[i].rank(pos, 0);
      }
    }
    return pos - t[c];
  }

  // 元の数列vでk番目の数値cの位置を返す
  int select(int k, int c) {
    int pos = t[c] + k - 1;
    for(int i = bitmx-1; i >= 0; --i) {
      if((c >> (bitmx - 1 - i)) & 1) {
	pos = bv[i].select(pos - offset[i+1] + 1, 1);
      }
      else {
	pos = bv[i].select(pos + 1, 0);	
      }
    }
    return pos;
  }

  // [left, right) に含まれる0以上num未満の要素の個数を返す
  int rank_less_than(int left, int right, int num) {
    if(num > mx_elem) return right - left;

    int res = 0;
    for(int i = 0; i < bitmx && left < right; ++i) {
      int b = (num >> (bitmx - 1 - i)) & 1;

      int rank0_left = bv[i].rank(left, 0);
      int rank0_right = bv[i].rank(right, 0);
      int rank1_left = bv[i].rank(left, 1);
      int rank1_right = bv[i].rank(right, 1);
      if(b) {
	res += rank0_right - rank0_left;
	left = offset[i+1] + rank1_left;
	right = offset[i+1] + rank1_right;
      }
      else {
	left = rank0_left;
	right = rank0_right;
      }
    }
    return res;
  }

  // [left, right) に含まれるmn以上、mx未満の要素の個数を返す
  int range_less_than(int left, int right, int mn, int mx) {
    return rank_less_than(left, right, mx) - rank_less_than(left, right, mn);
  }
  
  
  void test() {
    vector<int> v = {5, 4, 5, 5, 2, 1, 5, 6, 1, 3, 5, 0};
    build(v);
    cout << access(6) << "\n";
    // 5
    cout << rank(9, 5) << "\n";
    // 4
    cout << select(4, 5) << "\n";
    // 6
    cout << range_less_than(1, 9, 4, 6) << "\n";
    // 4
  }
  
};


int main()
{
  WaveletMatrix wm;
  wm.test();
  
  return 0;
}
