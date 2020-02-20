#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int MAX_ROW = 110; // to be set appropriately
const int MAX_COL = 110000; // to be set appropriately
struct BitMatrix {
  int H, W;
  bitset<MAX_COL> val[MAX_ROW];
  BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
  inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
  void show(){
    rep(i,H){
      rep(j,W){
	cout << val[i][j] << " ";
      }
      cout  << "\n";
    }
  }
};

int GaussJordan(BitMatrix &A, bool is_extended = false) {
  int rank = 0;
  vector<bool> used(A.H,0);
  for (int col = 0; col < A.W; ++col) {
    if (is_extended && col == A.W - 1) break;
    int pivot = -1;
    for (int row = 0; row < A.H; ++row) {
      if(used[row]) continue;
      if (A[row][col]) {
	pivot = row;
	break;
      }
    }
    if (pivot == -1) continue;
    used[pivot]=1;
    //    if (pivot != rank) A[rank] ^= A[pivot];
    //        swap(A[pivot], A[rank]);
    for (int row = 0; row < A.H; ++row) {
      if (row != pivot && A[row][col]) A[row] ^= A[pivot];
    }
    ++rank;
    // cout << "****************" << "\n";
    // A.show();
  }
  return rank;
}

int linear_equation(BitMatrix A, vector<int> b, vector<int> &res) {
  int m = A.H, n = A.W;
  BitMatrix M(m, n + 1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
    M[i][n] = b[i];
  }
  int rank = GaussJordan(M, true);

  // check if it has no solution
  for (int row = rank; row < m; ++row) if (M[row][n]) return -1;

  // answer
  res.assign(n, 0);
  for (int i = 0; i < rank; ++i) res[i] = M[i][n];
  return rank;
}
const int DMAX=60;
int main()
{
  int n;
  cin >> n;
  //  n = 4;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }

  // rep1(ii,100){
  //   rep1(jj,100){
  //     rep1(kk,100){
  // 	rep1(lll,100){
  // 	  a[0]=ii;a[1]=jj;a[2]=kk;a[3]=lll;
  ll res = 0;
  BitMatrix B(DMAX+1,n+1);
  int row = 0;
  for(ll d=DMAX;d>=0;--d){
    int cnt = 0;
    rep(i,n){
      if((a[i]>>d)&1) cnt++;
    }
    if(cnt==0) continue;
    else if(cnt%2==1){
      res += (1LL<<d);
      continue;
    }

    int index = 0;
    rep(i,n){
      if((a[i]>>d)&1) B[DMAX-d][i] = 1;
    }
    B[DMAX-d][n] = 1;
    row++;
  }
  
  //  B.show();

  BitMatrix C(row,n+1);
  int index=0;
  map<int,ll> mp;
  rep(d,DMAX+1){
    if(B[d][n]){
      rep(i,n+1){
	C[index][i] = B[d][i];
      }
      mp[index] = (ll)DMAX - d;
      index++;
    }
  }

  // cout << "********" << "\n";
  // C.show();

  GaussJordan(C,true);

  rep(i,row){
    bool f=true;
    rep(j,n){
      if(C[i][j]){
	f = false;
	break;
      }
    }
    if(!(f&&C[i][n])) res += 2*(1LL<<mp[i]);
  }

  cout << res << "\n";

  // debag
  // ll ress = 0;
  // for(ll mask=1;mask<(1LL<<n);++mask){
  //   int num=0;
  //   ll aa=0,bb=0;
  //   for(ll i=0;i<n;++i){
  //     if((mask>>i)&1){
  // 	aa ^= a[i];
  // 	num++;
  //     }
  //     else{
  // 	bb ^= a[i];
  //     }
  //   }
  //   if(num==0) break;
  //   ress = max(ress,aa+bb);
  // }

  // cout << ress << "\n";
  //  if(res!=ress) cout << ii << ":" << jj << ":" << kk << ":" << lll << "\n";
  //	}}}}
  
  return 0;
}
