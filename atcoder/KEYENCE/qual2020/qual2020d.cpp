#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct BIT
{
  vector<X> dat;
  int n;

  BIT(int _n){
    n = _n+1;
    dat.assign(n,0);
  }
  
  X sum(int i)
  {
    X s = 0;
    while(i > 0){
      s += dat[i];
      i -= i&(-i);
    }
    return s;
  }

  void add(int i,X x)
  {
    while(i<=n){
      dat[i] += x;
      i += i&(-i);
    }
  }

};




int main()
{
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    cin >> b[i];
  }
  rep(i,n){
    cout << i << ":" << __builtin_popcount(a[i]) << "\n";
  }
  
  // vector<pair<int,int>> p(n);
  // rep(i,n){
  //   p[i] = make_pair(a[i],b[i]);
  // }

  const int inf = 1e+9;
  int res = inf;

  rep(S,(1<<n)){
    vector<pair<int,pair<int,int>>> p2(n+1);    
    int cnt3 = 0;
    rep(i,n){
      if((S>>i)&1){
	p2[i] = make_pair(b[i],make_pair(i,1));
	cnt3++;
      }
      else{
	p2[i] = make_pair(a[i],make_pair(i,0));	
      }
    }
    if(cnt3%2==1) continue;
    p2[n] = make_pair(100,make_pair(n,0));    
    sort(p2.begin(), p2.end());

    // rep(i,n+1){
    //   cout << i << ":" << p2[i].first << ":" << p2[i].second.first << ":" << p2[i].second.second << "\n";
    // }
        
    bool f = false;
    bool ff = false;
    int cnt1=0,cnt2=0;

    rep(i,n){
      // if(ff||p2[i].first==p2[i+1].first){
      // 	if(!ff){
      // 	  cnt1=0;
      // 	  cnt2=0;
      // 	  ff = true;
      // 	}
      // 	cnt1 += abs(i-p2[i].second.second)%2;
      // 	//	cout << abs(i-p2[i].second.second) << "***\n";	
      // 	cnt2 += p2[i].second.first;
      // 	cout << "cnt" << "\n";
      // 	cout << cnt1 << ":" << cnt2 << "\n";	
      // 	//	cout << i << "\n";
      // 	//	cout << p2[i].first << ":" << p2[i+1].first << "\n";
      // 	if(p2[i].first!=p2[i+1].first){
      // 	  //	  cout << cnt1 << ":" << cnt2 << "\n";
      // 	  if(cnt1%2!=cnt2%2){
      // 	    f=true;
      // 	    break;
      // 	  }
      // 	  ff = false;
      // 	}
      // }
      if(abs(i-p2[i].second.first)%2==1&&p2[i].second.second==0){
	f = true;
	break;
      }
      else if(abs(i-p2[i].second.first)%2==0&&p2[i].second.second==1){
	f = true;
	break;
      }
      //      cout << 0 << "\n";
    }
    //    p2.erase(p2.begin()+n);

    if(f) continue;
    //    cout << S << "\n";
    BIT<int> bit(n+1);
    int ans = 0;
    rep(i,n+1){
      ans += i - bit.sum(p2[i].second.first+1);
      bit.add(p2[i].second.first+1,1);
    }

    res = min(res,ans);
  }
  if(res==inf) cout << -1 << "\n";
  else cout << res << "\n";
  
  return 0;
}
