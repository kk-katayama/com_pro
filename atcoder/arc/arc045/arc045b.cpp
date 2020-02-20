#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
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
      if(k < n-1){
	delay[2*k+1] += delay[k]; 
	delay[2*k+2] += delay[k];
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
      delay[k] += x;
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      dat[k] = min(dat[2*k+1],dat[2*k+2]);
    }
  }

  X query(int a,int b,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return 1e+9;

    if(a<=l&&r<=b) return dat[k];    
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return min(vl,vr);
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
	if(dat[i+index]==1e+9) cout << "inf" << " ";
	else cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
    index = 0;
    num = 1;
    while(index<n){
      rep(i,num){
	if(delay[i+index]==1e+9) cout << "inf" << " ";	
	else cout << delay[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;    
    }
  }
  
};



int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> s(m),t(m);
  rep(i,m) cin >> s[i] >> t[i];

  DST<int> dst(n);
  dst.update(n,dst.size(),1e+9,0,0,dst.size());
  rep(i,m){
    dst.update(s[i]-1,t[i],1,0,0,dst.size());
    //    dst.show();
  }

  // dst.all_eval();
  // dst.show();

  vector<int> res;
  rep(i,m){
    if(dst.query(s[i]-1,t[i],0,0,dst.size())!=1){
      res.push_back(i+1);
    }
  }

  cout << (int)res.size() << "\n";
  rep(i,res.size()) cout << res[i] << "\n";
  
  
  return 0;
}
