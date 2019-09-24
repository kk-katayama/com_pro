#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
vector<int> Slide_Min(vector<int> a,int n,int k){
  deque<int> deq;
  vector<int> b(0);
  rep(i,k){
    while((!deq.empty()) && a[*(deq.end()-1)] >= a[i]) deq.pop_back();
    deq.push_back(i);
  }

  b.push_back(*deq.begin());
  if(*deq.begin()==0) deq.pop_front();

  rep(i,n-k){
    while((!deq.empty()) && a[*(deq.end()-1)] >= a[i+k]) deq.pop_back();
    deq.push_back(i+k);
    //    while(*deq.begin() < i+1) deq.pop_front();
    b.push_back(*deq.begin());
    if(*deq.begin() == i+1) deq.pop_front();
  }
  return b;
}
vector<int> Slide_Max(vector<int> a,int n,int k){
  deque<int> deq;
  vector<int> b(0);
  rep(i,k){
    while((!deq.empty()) && a[*(deq.end()-1)] <= a[i]) deq.pop_back();
    deq.push_back(i);
  }

  b.push_back(*deq.begin());
  if(*deq.begin()==0) deq.pop_front();

  rep(i,n-k){
    while((!deq.empty()) && a[*(deq.end()-1)] <= a[i+k]) deq.pop_back();
    deq.push_back(i+k);
    //    while(*deq.begin() < i+1) deq.pop_front();
    b.push_back(*deq.begin());
    if(*deq.begin() == i+1) deq.pop_front();
  }
  return b;
}

int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i,n) cin >> p[i];

  vector<int> smin = Slide_Min(p,n,k);
  vector<int> smax = Slide_Max(p,n,k);  

  vector<int> rle(0);
  int cnt = 1;
  rep(i,n-1){
    if(p[i]<p[i+1]) cnt++;
    else{
      rle.push_back(cnt);
      cnt = 1;
    }
  }
  rle.push_back(cnt);

  vector<int> len(0);
  rep(i,rle.size()){
    while(rle[i]>0){
      len.push_back(rle[i]);
      rle[i]--;
    }
  }

  bool f = false;
  if(len[n-k]>=k) f =true;

  int res = 1;
  rep(i,n-k){
    if(len[i] >= k){
      if(!f){
	res++;
	f =true;
      }
      continue;
    }
    if(!(smin[i]==i&&smax[i+1]==i+k)) res++;
  }

  cout << res << "\n";
  
  return 0;
}
