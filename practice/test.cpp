#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 正しい移動かを調べる (y, x)が移動先
bool is_valid_move(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
  int N = board.size();
  int M = board[y].size();
  
  // 移動先がマス目の外である場合
  if (y <= -1 || y >= N || x <= -1 || x >= M) {
    return false;
  }
  // 移動先が壁マス
  if (board.at(y).at(x) == '#') {
    return false;
  }
  // 既に調べているマスへの移動は調べないのでfalseを返す
  if (checked.at(y).at(x)) {
    return false;
  }

  // それ以外なら正しい移動
  return true;
}

// (y, x)にいる状態から(gy, gx)に到達できるか
// board: マス目の種類
// checked: そのマスを既に調べたかを持つ二次元配列
bool reachable(vector<string> &board, vector<vector<bool>> &checked, int x, int y, int gx, int gy) {
  int N = board.size();

  // ベースケース
  if (x == gx && y == gy) {
    // ゴールにいる状態
    return true;
  }

  // 再帰ステップ

  checked.at(y).at(x) = true;  // 既に調べているという状態に変えておく

  // 「上」「右」「下」「左」のいずれかの移動でゴールに到達できるか？
  bool result = false;

  // 上へ移動したマスからゴールに到達できるか？
  if (is_valid_move(board, checked, x, y - 1) && reachable(board, checked, x, y - 1, gx, gy)) {
    result = true;
  }
  // 右へ移動したマスからゴールに到達できるか？
  if (is_valid_move(board, checked, x + 1, y) && reachable(board, checked, x + 1, y, gx, gy)) {
    result = true;
  }
  // 下へ移動したマスからゴールに到達できるか？
  if (is_valid_move(board, checked, x, y + 1) && reachable(board, checked, x, y + 1, gx, gy)) {
    result = true;
  }
  // 左へ移動したマスからゴールに到達できるか？
  if (is_valid_move(board, checked, x - 1, y) && reachable(board, checked, x - 1, y, gx, gy)) {
    result = true;
  }

  return result;
}


int main() {
  int H, W;
  cin >> H >> W;
  // マス目の状態を受け取る
  vector<string> board(H);
  for (int i = 0; i < H; i++) {
    cin >> board.at(i);
  }
  //s,gの特定
  int sx, sy, gx, gy;
  for (int i = 0; i < H; i++)
  {
      for (int j = 0; j < W; j++)
      {
        if (board.at(i).at(j) == 's')
        {
            sx = j;
            sy = i;
        }
        if (board.at(i).at(j) == 'g')
        {
            gx = j;
            gy = i;
        }
      }
      
  }
  

  // 既にそのマスを調べたかを保持する二次元配列
  vector<vector<bool>> checked(H, vector<bool>(W, false));  // false(まだ調べていない)で初期化しておく

  // sからgまで到達できるか？
  if (reachable(board, checked, sx, sy, gx, gy)) {
    cout << "Yes" << endl;
  }
    else {
    cout << "No" << endl;
  }
}
