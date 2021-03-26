#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

// Doubling
// https://drken1215.hatenablog.com/entry/2020/12/29/190100

const int MAX = 20;
// 2^20

int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<vector<int>> next(MAX, vector<int>(N));
  // next[i][v] := vから2^iステップで到達できる場所
  // next[i+1][v] = next[i][next[i][v]]

  // 0ステップ(2^0=1)で行ける場所の初期化
  rep(i, N) {
    if (S[i] == 'L') next[0][i] = i-1;
    else next[0][i] = i+1;
  }
  // nextの更新
  // next[i+1][v] = next[i][next[i][v]]
  rep(i, MAX-1) {
    rep(v, N) {
      next[i+1][v] = next[i][next[i][v]];
    }
  }
  vector<int> res(N, 0);
  int K = N*2;
  // Kステップ後の子供の位置xを計算して
  // res[x]にその人数を格納する。
  rep(v, N) {
    int nv = v;
    rep(d, MAX) {
      // nvの更新
      // Kのdビット目が1かどうか
      if (K & (1<<d)) nv = next[d][nv];
    }
    res[nv]++;
  }
  // Answer
  /*
  rep(i, N) cout << res[i] << " " ;
  cout << endl;
  */

  // 任意のステップ後の場所
  int s = 0;
  int step = 5;
  rep(d, MAX-1) {
    if (step & (1<<d)) s = next[d][s];
  }
  cout << s << " " << S[s] << endl;
  return 0;
}