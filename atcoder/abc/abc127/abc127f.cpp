#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int q;
  cin >> q;
  vector<int> com(q);
  vector<ll> a(q),b(q);
  rep(i,q){
    cin >> com[i];
    if(com[i]==1) cin >> a[i] >> b[i];
  }

  ll asum = 0,bsum = 0;
  multiset<ll> st;
  auto medit = st.end();  
  rep(i,q){
    if(com[i]==1){
      bsum += b[i];
      int ss = st.size();
      if(ss==0){
	st.insert(a[i]);
	medit = st.begin();
      }
      else if(ss%2==0){
	ll med = *medit;
	st.insert(a[i]);	
	if(med<=a[i]){
	  ++medit;
	  asum += a[i] - *medit;
	}
	else{
	  asum += med - a[i];
	}
      }
      else{
	ll med = *medit;
	st.insert(a[i]);	
	if(med<=a[i]){
	  asum += a[i] - med;
	}
	else{
	  asum += med - a[i];
	  --medit;	  
	}
      }
    }
    else{
      cout << *medit << " " << asum+bsum << "\n";
    }
  }

  
  return 0;
}
