#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
void chmin(int& x, int y) { x = min(x, y);}
const int INF = 1001001001;


int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N), z(N);
  rep(i, N) cin >> x[i] >> y[i] >> z[i];
  vector<vector<int>> dist(N, vector<int>(N));
  rep(i, N)rep(j, N) {
    dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]) + max(0, z[j]-z[i]);
  }
  int N2 = 1 << N;
  vector<vector<int>> dp(N2, vector<int>(N, INF));
  // dp[S][v]: 既に訪れた都市の集合S、現在の都市をvとした時の総距離
  // 初期化(0番目の都市からそれぞれの都市までの距離)
  rep(i, N) {
    if (i == 0) continue;
    dp[1<<i][i] = dist[0][i];
  }
  rep(s, N2) {
    rep(i, N) {
      // sに都市iが含まれていない場合はcontinue
      // iから次の行き先を決めるため
      if (~s>>i&1) continue;
      rep(j, N) {
        // sに既に都市jが含まれている場合はcontinue
        if (s>>j&1) continue;
        chmin(dp[s|1<<j][j], dp[s][i]+dist[i][j]);
      }
    }
  }
  cout << dp[N2-1][0] << endl;
  return 0;
}