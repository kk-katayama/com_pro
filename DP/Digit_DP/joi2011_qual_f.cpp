#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
typedef long long ll;
const ll MOD=10000;
struct mint{
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator-=(const mint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator*=(const mint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  mint operator+(const mint a) const{
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const{
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const{
    mint res(*this);
    return res*=a;
  }
};
string a,b;
int M;
mint dpa[510][10][510][4][2],dpb[510][10][510][4][2];
int main()
{
  cin >> a >> b >> M;

  dpa[0][0][0][0][0].x = 1;
  
  int as = a.size(),bs = b.size();

  rep(i,as+1) rep(j,10) rep(k,M) rep(l,4) rep(m,2) {
    int ai = a[i] - '0';
    rep(jj,(m?10:ai+1)){
      if(l==2&&jj>j) dpa[i+1][jj][(10*j+jj)%M][3][m||jj<ai] += dpa[i][j][k][l][m];
      else if(l==3&&jj<j) dpa[i+1][jj][(10*j+jj)%M][2][m||jj<ai] += dpa[i][j][k][l][m];
      else if(l==1&&jj!=j) dpa[i+1][jj][(10*j+jj)%M][2+(jj>j)][m||jj<ai] += dpa[i][j][k][l][m];
      else if(l==0) dpa[i+1][jj][(10*j+jj)%M][l||jj!=0][m||jj<ai] += dpa[i][j][k][l][m]; 
    }
  }

  dpb[0][0][0][0][0].x = 1;
  
  rep(i,bs+1) rep(j,10) rep(k,M) rep(l,4) rep(m,2) {
    int bi = b[i] - '0';
    rep(jj,(m?10:bi+1)){
      if(l==2&&jj>j) dpb[i+1][jj][(10*j+jj)%M][3][m||jj<bi] += dpb[i][j][k][l][m];
      else if(l==3&&jj<j) dpb[i+1][jj][(10*j+jj)%M][2][m||jj<bi] += dpb[i][j][k][l][m];
      else if(l==1&&jj!=j) dpb[i+1][jj][(10*j+jj)%M][2+(jj>j)][m||jj<bi] += dpb[i][j][k][l][m];
      else if(l==0) dpb[i+1][jj][(10*j+jj)%M][l||jj!=0][m||jj<bi] += dpb[i][j][k][l][m]; 
    }
  }

  mint resa,resb;
  rep(j,10) rep(l,4) rep(m,2) resa += dpa[as][j][0][l][m];
  rep(j,10) rep(l,4) rep(m,2) resb += dpb[bs][j][0][l][m];  
  resa -= 1;
  resb -= 1;  
  
  mint res = resb - resa;

  mint p;

  if(as==1) p.x = 1;
  else{
    int zz = a[0]-'0';
    int bef = a[1]-'0';
    bool f = ((zz<bef)?1:0);
    bool ff = true;
    if(zz!=bef){
      rep1(i,as-2){
	int now = a[i+1] - '0';
	if(f&&bef<=now){
	  ff = false;
	  break;
	}
	if(!f&&bef>=now){
	  ff = false;
	  break;
	}
	bef = now;
	f = !f;
      }
      if(ff) p.x = 1;
    }    
  }
  res += p;
  
  cout << res.x << "\n";
  return 0;
}
