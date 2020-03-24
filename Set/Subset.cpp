#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
int main()
{
  int mask;
  cin >> mask;
  cout << bitset<8>(mask) << "\n";
  // 集合maskの部分集合を全探索する
  // 空集合を除く
  cout << "without_0" << "\n";
  for(int i=mask;i>0;i=(i-1)&mask){ 
    cout << bitset<8>(i) << "\n";
  }
  // 空集合を含む
  cout << "with_0" << "\n";  
  for(int i=mask;i>=0;--i){
    i &= mask;
    cout << bitset<8>(i) << "\n";
  }

  // 集合maskを部分集合にもつような集合を全探索
  cout << "include_mask" << "\n";
  for(int i=mask;i<(1<<8);i=(i+1)|mask){
    cout << bitset<8>(i) << "\n";
  }

  return 0;
}

