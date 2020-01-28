#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
class DST
{
private:
  int n;
  vector<X> dat,delay;
  const X init = 0;

  void eval(int k,int l,int r)
  {
    if(delay[k] != 0){
      dat[k] += delay[k];
      //      dat[k] = delay[k];      
      if(k < n-1){
	delay[2*k+1] += delay[k]/2;
	delay[2*k+2] += delay[k]/2;
	// delay[2*k+1] = delay[k]; // change update
	// delay[2*k+2] = delay[k];	
      }
      delay[k] = 0;
    }
  }
  

  
public:  
  DST(int _n)
  {
    n = 1;
    while(n < _n) n *= 2;
    dat.assign(2*n-1,init);
    delay.assign(2*n-1,init);
  }

  void update(int a,int b,X x,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return ;
    
    if(a<=l&&r<=b){
      delay[k] += (r-l)*x;
      //      delay[k] = x; // change update
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      dat[k] = dat[2*k+1] + dat[2*k+2];
      // dat[k] = dat[2*k+1]; //change update
      // dat[k] = dat[2*k+2];      
    }
  }

  X query(int a,int b,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return 0;

    if(a<=l&&r<=b) return dat[k];    
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return vl + vr;
    }
  }

  int size(){
    return n;
  }
  
  int get_dat(int x){
    return dat[n-1+x];
  }    
  
  void all_eval(){
    rep(i,2*n-1){
      eval(i,0,0);
    }
  }
  
  void show(){
    int index = 0;
    int num = 1;
    while(index<n){
      rep(i,num){
	cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
    index = 0;
    num = 1;
    while(index<n){
      rep(i,num){
	cout << delay[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;    
    }
  }
  
};


pair<ll,ll> xh[200010];
bool C(int xx,ll d){
  return xh[xx].first<=d;
}
int lower(int l,int r,ll d){//条件を満たす中で最大のものを返す
  int lb=l-1,ub=r+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(C(mid,d)) lb=mid;
    else ub=mid;
  }
  return lb;
}

int main()
{
  ll n,d;
  ll a;
  cin >> n >> d >> a;
  vector<int> h(n);
  rep(i,n){
    ll xx;
    ll hh;
    cin >> xx >> hh;
    xh[i] = {xx,hh};
  }
  sort(xh,xh+n);
  vector<pair<int,int>> p(n);
  rep(i,n){
    ll dd = xh[i].first+2*d;
    int ub = lower(1,n-1,dd);
    p[i] = {i,ub+1};
  }
  // rep(i,n){
  //   cout << p[i].first << ":" << p[i].second << "\n";
  // }

  DST<ll> dst(n);
  rep(i,n){
    dst.update(i,i+1,xh[i].second,0,0,dst.size());
    //    dst.show();
  }

  ll cnt = 0;
  rep(i,n){
    ll aa = dst.query(i,i+1,0,0,dst.size());
    // dst.show();
    // cout << aa << "\n";
    if(aa<=0) continue;
    ll ddd = (ll)(aa+a-1)/a;
    cnt += ddd;
    dst.update(p[i].first,p[i].second,-(ddd*a),0,0,dst.size());
  }
  cout << cnt << "\n";

  
  return 0;
}
