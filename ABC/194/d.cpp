#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

// Geometric Distribution
// https://ai-trend.jp/basic-study/geometric-distribution/geometric-distribution-mean-ver/
// k回目で初めて成功する事象の期待値の計算
// (1-p)^{k-1}*p*kの期待値を計算すれば良い
// \sum^{\infty}_{k=1}(1-p)^k*p*k = 1/p
int main() {
  int N;
  cin >> N;
  double ans = 0;
  for (int i = 1; i < N; i++) {
    ans += (double)N / (N-i);
  }
  printf("%.10f\n", ans);
  return 0;
}