#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
      //     dat[k] = delay[k];      
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

int main()
{
  int n,q;
  cin >> n >> q;
  vector<int> l(q),r(q);
  rep(i,q){
    cin >> l[i] >> r[i];
  }
  DST<int> dst(n);
  rep(i,q){
    dst.update(l[i]-1,r[i],1,0,0,dst.size());
    //    dst.show();
  }
  // dst.all_eval();
  // dst.show();
  string res="";
  rep(i,n){
    int buf = dst.query(i,i+1,0,0,dst.size());
    if(buf%2==0){
      res += '0';
    }
    else{
      res += '1';
    }
  }
  cout << res << "\n";
  return 0;
}
