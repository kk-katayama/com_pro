#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
int main()
{

  cin >> mask;
  cout << bitset<8>(mask) << "\n";
  int mask;  
  // 集合maskの部分集合を全探索する
  // 空集合を除く
  for(int i=mask;i>0;i=(i-1)&mask){ 
    //    cout << bitset<8>(i) << "\n";
  }
  // 空集合を含む
  for(int i=mask;i>=0;--i){
    i &= mask;
    //    cout << bitset<8>(i) << "\n";
  }

  // 集合maskを部分集合にもつような集合を全探索
  for(int i=mask;i<(1<<8);i=(i+1)|mask){
    //    cout << bitset<8>(i) << "\n";
  }

  return 0;
}

