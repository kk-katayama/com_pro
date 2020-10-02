# 二次元座圧  

二次元座圧。  

## ライブラリ  
[ライブラリ](https://github.com/kk-katayama/com_pro/blob/master/Array/Compress/Compress_2D/Compress_2D.cpp)  

## 中身  
### add(x, y)  
座標を追加する。  
### build()  
座圧を実行する。  
### p  
もとの座標の集合。  
### data  
座圧後の座標の集合。  
### xmp, ymp  
key:元の座標。val:座圧後の座標。が詰められたmap。  
### xpm, ypm  
idx:座圧後の座標。val:元の座標。となっているvector。  
### xmax, ymax  
座圧後の最大値。元の座標の最大値は当然xpm[xmax]、ypm[ymax]。  
