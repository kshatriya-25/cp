/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 100;

int dp[N][N][N];

int brick, m, k;

int rec(int i, int cur_k, int p) {
  // base
  if (i == brick && cur_k == k) return 1;
  if (cur_k > k || i > brick) return 0;

  if (dp[i][cur_k][p] != -1) return dp[i][cur_k][p];

  // transition
  int ans = 0;
  // not changing the color
  ans += rec(i + 1, cur_k, p);
  // change to any one of the colour
  ans += rec(i + 1, cur_k + 1, (p + 1) % m);
  return dp[i][cur_k][p] = ans;
}

void jaiShreeRam() {
  mset(dp, -1);
  cin >> brick >> m >> k;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += rec(1, 0, i);
  }
  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    jaiShreeRam();
  }
}