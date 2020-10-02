# 一次元座圧  

座標圧縮  

## ライブラリ  
[ライブラリ](https://github.com/kk-katayama/com_pro/blob/master/Array/Compress/Compress_1D/Compress_1D.cpp)  

## 中身  
### add(val)  
配列に要素を追加。  
### build()  
座圧を実行。これを忘れると何も起きないので注意。  
### data  
座圧後の配列はここに入っている。  
### mp  
keyが元の配列の値。valが座圧後の配列の値。となっているmap。  

### a2data  
オンラインで座圧してくれる。mapを二分探索しているので、limitを超えた値を入れるとバグる。番兵を入れようね。
