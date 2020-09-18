template <typename X>
class DST
{
private:
  int n;
  vector<X> dat,delay,delay2,delay3;
  const X init = 1e+9;

  void eval(int k,int l,int r)
  {
    if(delay[k] != 0){
      dat[k] = delay2[k];
      dat[k] += delay[k];
      dat[k] += delay3[k];      
      if(k < n-1){
	delay[2*k+1] += delay[k]/2;
	delay[2*k+2] += delay[k]/2;
	delay2[2*k+1] = delay2[k]; // change update
	delay2[2*k+2] = delay2[k];	
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
    delay2.assign(2*n-1,init);
    delay3.assign(2*n-1,init);    
  }

  void update(int a,int b,X x,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return ;
    
    if(a<=l&&r<=b){
      delay[k] += (r-l)*x;
      delay2[k] = x; // change update
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
    
    if(r<=a||b<=l) return init;

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

