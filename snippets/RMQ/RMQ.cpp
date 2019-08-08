typedef long long ll;
const int NMAX = 300010;
const int INF = 1e+9;
/***************RMQ(Range Minimum Query)************/
class RMQ{
public:
  ll dat[NMAX*2-1];
  int nn;
  RMQ(int n_);
  void update(int k,ll a);
  ll query(int a,int b,int k,int l,int r);
};
RMQ::RMQ(int n_){
  nn=1;
  while(nn<n_) nn*=2;
  for(int i = 0 ; i < 2*nn-1 ; ++i){
    dat[i]=INF; 
  }
}
void RMQ::update(int k,ll a){
  k+=nn-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=min(dat[2*k+1],dat[2*k+2]);
  }
}
ll RMQ::query(int a,int b,int k,int l,int r) {
  if(r<=a||b<=l) return INF;
  if(a<=l&&r<=b) return dat[k];
  else{
    ll v1=query(a,b,2*k+1,l,(l+r)/2);
    ll v2=query(a,b,2*k+2,(l+r)/2,r);
    return min(v1,v2);
  }
}
/********************************************************/
