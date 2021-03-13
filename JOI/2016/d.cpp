#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
void chmin(int& x, int y) { x = min(x, y);}

// Ref: https://blog.hamayanhamayan.com/entry/2019/10/27/233512

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> cnt(M); // 種類毎の出現回数
  vector<vector<int>> accum(M, vector<int>(N)); // 種類毎の累積和
  // 種類mのlからrまでのぬいぐるみの個数はaccum[m][r]-accum[m][l]で取得できる
  rep(i, N) {
    cin >> A[i];
    A[i]--;
    cnt[A[i]]++;
    accum[A[i]][i] = 1; // 種類mのぬいぐるみが位置iに存在する場合は1にする
  }
  // 累積和の計算
  rep(i, M)rep(j, N) {
    if (j == 0) continue;
    accum[i][j] += accum[i][j-1];
  }
  // DPの実行
  int N2 = 1 << M;
  int INF = 10000000;
  vector<int> dp(N2, INF);
  dp[0] = 0;
  // sが既に連続して配置されている種類の集合
  // s = {1, 2, 3}の場合、左から1,2,3の種類のぬいぐるみは連続して配置されている
  // 順番は不明 (1,2,3かもしれないし、3,1,2かもしれない)
  rep(s, N2) {
    int done = 0;
    // sに含まれるぬいぐるみの個数を取得する
    rep(i, M) if (s & (1<<i)) done += cnt[i];
    rep(next, M) { // 次にsに含めるぬいぐるみの種類を決める
      if (~s&1<<next) { // 種類nextが既にsに含まれいてはいけない
        int tot = dp[s];
        // 動かす種類nextのぬいぐるみの個数を求める
        // sに含まれるぬいぐるみを連続に整理した後の位置がdoneである
        // そこから種類nextの個数分だけぬいぐるみを動かす必要がある
        int next_cnt = accum[next][done + cnt[next] - 1];
        if (next_cnt > 0) next_cnt -= accum[next][done - 1];
        tot += cnt[next] - next_cnt;
        chmin(dp[s | 1<< next], tot);
      }
    }
  }
  cout << dp[N2-1] << endl;
  return 0;
}