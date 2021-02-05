// 任意MODが使えるModint 
// 型宣言の前にmodint::set_mod(MOD) をしてね
struct modint{
  long long x;

  modint() : x(0) {}
  modint(long long x):x(x%mod()){}

  static int &mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md) {
    mod() = md;
  }

  modint& operator+=(const modint a){
    if((x+=a.x)>=mod()) x-=mod();
    return *this;
  }
  modint& operator-=(const modint a){
    if((x += mod()-a.x)>=mod()) x-=mod();
    return *this;
  }
  modint& operator*=(const modint a){
    (x*=a.x)%=mod();
    return *this;
  }
  modint operator+(const modint a) const{
    modint res(*this);
    return res+=a;
  }
  modint operator-(const modint a) const{
    modint res(*this);
    return res-=a;
  }
  modint operator*(const modint a) const{
    modint res(*this);
    return res*=a;
  }
  modint pow(long long t) const{
    if(!t) return 1;
    modint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  modint inv() const{
    return pow(mod()-2);
  }
  modint& operator/=(const modint a){
    return (*this) *= a.inv();
  }
  modint operator/(const modint a) const{
    modint res(*this);
    return res/=a;
  }
};

