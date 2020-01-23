#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  if(a[n-1]-a[0]>1){
    cout << "No" << "\n";
  }
  else if(a[n-1]==a[0]){
    if(a[0]==n-1){
      cout << "Yes" << "\n";
    }
    else if(n/2>=a[0]){
      cout << "Yes" << "\n";
    }
    else{
      cout << "No" << "\n";
    }
  }
  else{
    int cnt=1;
    rep(i,n-1){
      if(a[i]!=a[i+1]){
	break;
      }
      else{
	cnt++;
      }
    }
    if(cnt<a[n-1]){
      if((n-cnt)/(a[n-1]-cnt)>=2){
	cout << "Yes" << "\n";
      }
      else{
	cout << "No" << "\n";
      }
    }
    else{
      cout << "No" << "\n";
    }
  }  
  
  
  return 0;
}
